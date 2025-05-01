#include "LearningInterface.h"
#include "Learning/Optional.h"
#include <iostream>

namespace Learning {
LearningInterface::LearningInterface(QObject *parent)
    : QObject{parent}
{

}

void LearningInterface::testOptional()
{
    Name testName{"Brian", "Michael", "Smith"};
    std::cout << "Full name = " << testName.getName() << "\n";
    Name testName2{"Brian", "Smith"};
    std::cout << "Name with optional left out = " << testName2.getName() << "\n";
}

} // namespace Learning
