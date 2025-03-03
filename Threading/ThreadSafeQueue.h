/** \file BrianThreadSafeQueue.h 
 */
#pragma once

#include <queue>
#include <mutex>

/** The ThreadSafeQueue class
 *
 * This class allows for the functionality of a std::queue with the additional protection
 * of a mutex and conditional. The extra protection will allow multiple threads to safely
 * add and remove data from the queue (concurrenct access) without causing a race condition.
 *
 * - The std::queue allows for data to be placed in a container for processing.
 * - The std::mutex is used to 
 * 
 * *** Condition ***
 * 
 * The condition_variable class is a synchronization primitive used with a std::mutex to block
 * one or more threads until another thread both modifies a shared variable (the condition) and
 * notifies the condition_variable.
 *
 * The thread that intends to modify the shared variable must:
 * - Acquire a std::mutex (typically via std::lock_guard)
 * - Modify the shared variable while the lock is owned
 * - Call notify_one or notify_all on the std::condition_variable (can be done after releasing the lock)
 * 
 * Any thread that intends to wait on a std::condition_variable must:
 *
 * Acquire a std::unique_lock<std::mutex> on the mutex used to protect the shared variable
 * Do one of the following:
 * - Check the condition, in case it was already updated and notified
 * - Call wait, wait_for, or wait_until on the std::condition_variable (atomically releases the mutex and
 *   suspends thread execution until the condition variable is notified, a timeout expires, or a spurious
 *   wakeup occurs, then atomically acquires the mutex before returning)
 * - Check the condition and resume waiting if not satisfied
 * or:
 * - Use the predicated overload of wait, wait_for, and wait_until, which performs the same three steps
 */

template <class T>
class ThreadSafeQueue
	{
	public:
    ThreadSafeQueue() = default;

    ~ThreadSafeQueue() = default;

    /** Add a value to the end of the m_queue.
     *
     * This method will block if the m_mutex lock used by the m_queue is currently being held
     */
    void push(T item)
    {
      // Obtain the lock
      // This is needed so that this method will not push to the m_queue while it is currently in use
      std::unique_lock<std::mutex> lock(m_mutex);

      m_queue.push(item);

      // Notify one thread that
      // is waiting
      m_cond.notify_one();
    }

    /** Remove the first value from the m_queue.
     *
     * This method will block if the m_mutex lock used by the m_queue is currently being held.
     *
     * This method will block indefinitely until a value is added to the m_queue if the m_queue is empty.
     * 
     * \return T Returns the first element of the m_queue (it is also removed from the m_queue)
     */
    T pop()
    {
      // Obtain the lock
      // This is needed so that this method will not pop from the m_queue while it is currently in use
      std::unique_lock<std::mutex> lock(m_mutex);

      // wait until queue is not empty
      // 1) Atomically unlocks lock, blocks the current executing thread, and adds it to the list of threads
      // waiting on *this. The thread will be unblocked when notify_all() or notify_one() is executed. It may
      // also be unblocked spuriously. When unblocked, regardless of the reason, lock is reacquired and wait exits.
      m_cond.wait(lock, [this]() { return !m_queue.empty(); });

      T item = m_queue.front();
      m_queue.pop();

      // return item
      return item;
    }

    void swap(std::queue<T>& otherQueue)
    { 
      std::unique_lock<std::mutex> lock(m_mutex);
      m_queue.swap(otherQueue);
    }

    unsigned int GetNumQueueEntries()
    { 
      std::unique_lock<std::mutex> lock(m_mutex);
      return static_cast<unsigned int>(m_queue.size());
    }

  private:
    std::queue<T> m_queue;
    std::mutex m_mutex;
    std::condition_variable m_cond;
  };

