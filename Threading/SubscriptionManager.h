#include "ThreadSafeQueue.h"

/** This class is an example of how to create a queue of std::function pointers.
 * These pointers can then be used to call the underlying function when needed.
 */
class SubscriptionManager
{
    public:
    SubscriptionManager() = default;

    ~SubscriptionManager() = default;

    void addSubscription(std::function<void()> subscription)
    {
        m_subscriptions.push(subscription);
    }

    /** Goes through each function that is subscribed and calls it. After that,
     * the function is removed from the queue 
     */
    void runAllSubscriptions()
    {
        while(m_subscriptions.GetNumQueueEntries())
        {
            std::function<void()> task;
            task = m_subscriptions.pop();
            task();
        }
    }

    private:
    ThreadSafeQueue<std::function<void()>> m_subscriptions;
};