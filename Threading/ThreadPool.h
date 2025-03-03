/** \file ThreadPool.h 
 */
#pragma once

#include <thread>
#include <filesystem>
#include <fstream>
#include <functional>
#include <future>
#include "ThreadSafeQueue.h"

/** \page Threading
 * \section Thread Pool
 *
 * It is innefficient to always create and delete threads. If many threads are needed, and they can be managed, then it is better to
 * utilize a thread pool.
 *
 * Each thread should be running its own infinite loop, constantly waiting for new tasks to utlize them.
 * 
 * \section Promise and Future
 * 
 * A promise is an object that can store a value of type T to be retrieved by a future object (possibly in another thread),
 * offering a synchronization point.
 *
 * On construction, promise objects are associated to a new shared state on which they can store either a value of type T
 * or an exception derived from std::exception.
 * 
 * A shared state is a data structure or variable that can be accessed and modified by multiple functions.
 * It is different from a local state, which is only accessible within a single function.
 * 
 * This shared state can be associated to a future object by calling member get_future. After the call, both objects share
 * the same shared state:
 * - The promise object is the asynchronous provider and is expected to set a value for the shared state at some point.
 * - The future object is an asynchronous return object that can retrieve the value of the shared state, waiting for it to be ready, if necessary.
 *
 * The lifetime of the shared state lasts at least until the last object with which it is associated releases it or is destroyed.
 * Therefore it can survive the promise object that obtained it in the first place if associated also to a future.
 * 
 * \section Coroutines (C++20)
 * 
 * A coroutine is a function that can suspend execution to be resumed later. 
 * 
 * \section Other
 * 
 * Look up the C++Concurrency support library for more options
 */

/** The BrianThreadPool class
 * 
 * 1) createInitialWorkerThreads will create all the initial threads and load them into the
 *    m_threads vector.
 * 2) The initial threads, utilizing the ThreadLoop function, will all pend waiting on m_jobsToRun.pop()
 *    - If there are 10 threads in the m_threads vector, they will initially all be pending since the
 *      m_jobsToRun is empty
 * 3) Call addJob to add a new Thread to the m_jobsToRun queue. It should run as long as all of the threads in
 *    the m_threads are not busy running a Thread.
 * 
 * Notes:
 * - A promise is used to store a value that can be set from a thread and read from another thread without
 *   causing a race condition 
 */
class ThreadPool
{
public:
    ThreadPool();

    ~ThreadPool();

    /** Create a number of worker threads equal to the m_maxNumThreads.
     *
     * The m_maxNumThread is computed during the Constructor.
     * 
     * The internal lambda function used to create threads, which will be added to a vector,
     * creates a jthread. This is very useful since a jthread has logic for shutting down built
     * in from the c++ standard library.
     * 
     * The lambda function is an infinite loop and will exit when the jthread logic invokes
     * a shutdown.
     */
    void createInitialWorkerThreads();

    void shutdownWorkerThreads();

    /** Add a function to the m_jobsToRun queue. This will run whenever a thread in the
     * m_threads vector is free to run it.
     * 
     * Ex... If there are 10 total threads in the thread pool, one f them will run the
     * job as long as it is currently not busy already. If all 10 threads are busy, the
     * new job will only run once one of them finishes its current thread and pends waiting
     * for a new job.
     */
    void addJob(const std::function<void()>& job);

    void createThreadPoolThread();

    unsigned int getMaxNumThreads() { return m_maxNumThreads; }

private:
    std::jthread m_test_thread_object; /**< Thread used for testing function calls */
    std::filesystem::path m_filePath; /**< The location to store logging information */
    std::ofstream m_outputFile;       /**< The output file used to write to the m_filePath */
    unsigned int m_maxNumThreads;
    std::mutex m_fileMutex;           /**< A mutex protecting writes to the m_output file */
    /** A vector storing all of the threads used by the thread pool */
    std::vector<std::jthread> m_threads;
    /** A thread safe queue used to hold the jobs that are to be run by the thread pool, via ThreadLoop */
    ThreadSafeQueue <std::function<void()> > m_jobsToRun;


    void ThreadLoop(std::stop_token st);

/////// For testing basic threads without a threadpool
public: 
    unsigned int getThreadQueueCount();

    std::queue<int> getAllThreadValues(bool verbose = false);

    /** This method may block indefinitely (see BrianThreadSafeQueue::pop())
     *
     * \return int containing the first element of the BrianThreadSafeQueue (it is also removed from the queue)
     */
    int getThreadValue();

    /** Create a thread and detach from it.
     *
     * A labda function is used to make a simple function that just sleeps and increments
     * an integer (which is added to a BrianThreadSafeQueue for testing thread safety
     * with concurrency).
     *
     * This does not utilize the Thread Pool and is useful for just testing with
     * single threads.
     *
     * Note: Detaching a thread is not usually recommended, it is done here for simplicity
     */
    void testThread();

private:
    ThreadSafeQueue<int> m_queue;

//////// For testing promise & future

public:
    /** Uses a promise to set value that another thread can read using a future.
     *
     * If the promise has already called set_value, and a future has not read it yet, then
     * the next call to set_value will cause an exception.
     * 
     * Re-using an exception is not recommended but can be done with:
     *   m_promise = std::promise<int>();
     */
    void createProducerThread();

    /** The future will pend waiting for the promise to set a value. */
    void createConsumerThread();

    void joinProducerThread()
    {
        if (m_producer_thread_object.joinable())
            m_producer_thread_object.join();
    }

    void joinConsumerThread()
    {
        if (m_consumer_thread_object.joinable())
            m_consumer_thread_object.join();
    }

private:
    std::jthread m_producer_thread_object; 
    std::jthread m_consumer_thread_object;
    std::promise<int> m_promise;

///////// Coroutines
public:

private:

};

