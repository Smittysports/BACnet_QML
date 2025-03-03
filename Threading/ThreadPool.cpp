#include "ThreadPool.h"
#include <iostream>

static int s_producer_int = 0;
static int s_consumer_int = 0;

ThreadPool::ThreadPool()
    : m_filePath("/home/guest/Dev/BACnet_QML/BrianThreadPool.txt")
    , m_maxNumThreads(std::thread::hardware_concurrency() / 2)
{
    createInitialWorkerThreads();
}

ThreadPool::~ThreadPool()
{
    // TODO: Stop all of the JThreads, clearing will not work since the threads are still running
    // Since it is a JThread, the threads will auto join but will run forever since the shutdown
    // was not called
    shutdownWorkerThreads();
}

void ThreadPool::createInitialWorkerThreads()
{
    std::string myPath = std::filesystem::absolute(m_filePath).string();
    m_outputFile.open(myPath);
    m_outputFile << "Max number of threads = " << this->getMaxNumThreads() << std::endl;

    for (unsigned int i = 0; i < m_maxNumThreads; ++i) 
    {
        m_threads.emplace_back(
            std::jthread ( [i, this](std::stop_token st) 
            {
                {
                    std::scoped_lock lock(m_fileMutex);
                    m_outputFile << "Thread #" << i << " started" << std::endl;
                }

                while (!st.stop_requested())
                {
                    std::function<void()> task;
                    // ThreadSafeQueue.pop() will pend waiting for a job to be added
                    task = m_jobsToRun.pop();
                    if (task)
                    {
                        task();
                        m_outputFile << "Thread #" << i << " ran a task" << std::endl;
                    }
                }
                std::scoped_lock lock(m_fileMutex);
                m_outputFile << "Thread #" << i << " shutdown" << std::endl;
            } )
        );
    }
}

void ThreadPool::shutdownWorkerThreads()
{
    // Tell all of the threads that they should shutdown
    for (auto& currentThread : m_threads)
        currentThread.request_stop();

    // Send a command to each thread to wake it up if it is pending
    for (auto& currentThread : m_threads)
        addJob(std::function<void()>{});

    // Join each thread to make sure they exited
    for (auto& currentThread : m_threads)
        currentThread.join();

    m_threads.clear();

    if (m_outputFile.is_open())
    {
        std::scoped_lock lock(m_fileMutex);
        m_outputFile.close();
    }
}

void ThreadPool::addJob(const std::function<void()>& job)
{
    m_jobsToRun.push(job);
}

void ThreadPool::createThreadPoolThread()
{
    auto f = [&]() {
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        std::scoped_lock lock(m_fileMutex);
        m_outputFile << "Thread #" << s_producer_int++ << std::endl;
    };

    this->addJob(f);
}

/////// For testing basic threads without a threadpool

void ThreadPool::testThread()
{ 
    auto f = [&]() {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        this->m_queue.push(s_producer_int++);
    };

    std::jthread test_thread_object = std::jthread{f};
    m_test_thread_object.detach();
}

unsigned int ThreadPool::getThreadQueueCount()
{
    unsigned int count = m_queue.GetNumQueueEntries();
    std::scoped_lock lock(m_fileMutex);
    m_outputFile << "Number of queue entries = " << count << std::endl;
    return count;
}

std::queue<int> ThreadPool::getAllThreadValues(bool verbose)
{
    std::queue<int> tempQueue;
    m_queue.swap(tempQueue);

    if (verbose)
    {
        std::queue<int> copyQueue = tempQueue;
        while (!copyQueue.empty())
        {
        std::scoped_lock lock(m_fileMutex);
        m_outputFile << "Value = " << copyQueue.front() << std::endl;
        copyQueue.pop();
        }
    }
    return tempQueue;
}

int ThreadPool::getThreadValue()
{
    return m_queue.pop();
}

//////// For testing promise and future

void ThreadPool::createProducerThread()
{
    auto f = [&]() {
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        try
        {
            m_promise.set_value(11);
        }
        catch (std::exception& e)
        {
            std::scoped_lock lock(m_fileMutex);
            m_outputFile << "Producer thread, exception setting value: " << e.what()<< std::endl;
            //m_promise.set_exception(std::current_exception());
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        std::scoped_lock lock(m_fileMutex);
        m_outputFile << "Producer thread finished waiting" << std::endl;
    };

    m_producer_thread_object = std::jthread{f};
}

void ThreadPool::createConsumerThread()
{
    auto f = [&]() {
        std::future<int> futureVal = m_promise.get_future();
        std::scoped_lock lock(m_fileMutex);

        try
        {
            m_outputFile << "Consumer thread, future val = " << futureVal.get() << std::endl;
        }
        catch (std::exception& e)
        {
            m_outputFile << "Consumer thread, exception getting value " << e.what() << std::endl;
        }      
    };

    m_consumer_thread_object = std::jthread{f};
}
