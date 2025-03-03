#include <iostream>

class Subscriber
{
    public:

    Subscriber() = default;

    ~Subscriber() = default;

    void printSomething(const std::string message)
    {
        std::cout << message << "\n";
    }
};