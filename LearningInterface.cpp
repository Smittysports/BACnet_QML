#include "LearningInterface.h"
#include "Learning/Optional.h"

namespace Learning {
LearningInterface::LearningInterface(QObject *parent)
    : QObject{parent}
{

}

void LearningInterface::clearLog()
{
    emit clearLogSignal();
}

void LearningInterface::notImplemented()
{
    emit clearLogSignal();
    emit logUpdatedSignal("Not implemented");
}

void LearningInterface::logText(const QString& text)
{
    emit logUpdatedSignal(text);
}

void LearningInterface::testOptional()
{
    emit clearLogSignal();
    Name testName{"Brian", "Michael", "Smith"};
    std::string tempStr{"Full name = " + testName.getName() + "\n"};
    emit logUpdatedSignal(QString::fromStdString(tempStr));
    Name testName2{"Brian", "Smith"};
    tempStr = "Name with optional left out = " + testName2.getName() + "\n";
    emit logUpdatedSignal(QString::fromStdString(tempStr));
}

} // namespace Learning
