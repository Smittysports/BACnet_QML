#include "LearningInterface.h"
#include "Learning/cpp17/Optional.h"
#include "Learning/cpp17/Any.h"
#include "Learning/cpp17/Variant.h"

#include <QDesktopServices>
#include <QUrl>

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

void LearningInterface::shouldShowDoc(const bool& choice)
{
    m_shouldShowDoc = choice;
}

void LearningInterface::testOriginalLambda()
{
    emit clearLogSignal();

    emit logUpdatedSignal("Ex...\n");
    emit logUpdatedSignal("auto testLambda = []() -> QString {\n");
    emit logUpdatedSignal(R"(    return QString::fromStdString("This string is returned from a lambda\n");)");
    emit logUpdatedSignal("\n};\n");
    emit logUpdatedSignal("--------------------------------------------------------------------------\n");
    auto testLambda = []() -> QString {
        return QString::fromStdString("This string is returned from the lambda\n");
    };

    emit logUpdatedSignal(testLambda());

    if (m_shouldShowDoc)
    {
        QUrl url("https://en.cppreference.com/w/cpp/language/lambda");
        QDesktopServices::openUrl(url);
    }
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

    if (m_shouldShowDoc)
    {
        QUrl url("https://en.cppreference.com/w/cpp/utility/optional");
        QDesktopServices::openUrl(url);
    }
}

void LearningInterface::testAny()
{
    AnyTest anyTest;
    emit clearLogSignal();
    if (m_shouldShowDoc)
    {
        QUrl url(QString::fromStdString(anyTest.getDocLink()));
        QDesktopServices::openUrl(url);
    }
}

void LearningInterface::testVariant()
{
    VariantTest variantTest {};

    emit clearLogSignal();

    /* The lambda function, visitor, is designed to handle different types with myVariant. It will return
     * a QString that describes what the index and value of the variant are.
     *
     * The lamda takes a single arg, of a generic type. The auto keyword allows it accept any type.
     *
     * The 'if constexpr' line checks it the type of arg is an int. The constexpr keyword in C++ stands for
     * "constant expression." It is used to indicate that the value of a variable or the result of a function
     * can be evaluated at compile time. If the compiler can evaluate the expression at compile time, it will
     * replace the expression with its result, making the code faster.
     * - The constexpr in this lambda is used for conditional compilation based on the type of the argument.
     *
     * The std::decay<decltype(arg)> is used to remove any reference or const/volatile qualifiers from the type of arg.
     *
     * Note: A boolean will implicitly convert to an int
     *
     * Ex... If an int is assigned to myVariant, it will be using index 0 and will be formatted as an integer
     */
    auto visitor = [](auto arg){
        if constexpr (std::is_same_v<std::decay_t<decltype(arg)>, int>)
        {
            return QString("Index: 0, Value: " + QString::number(arg) + "\n");
        }
        else if constexpr (std::is_same_v<std::decay_t<decltype(arg)>, float>)
        {
            return QString("Index: 1, Value: " + QString::number(arg) + "\n");
        }
    };

    VariantTest::myVariant variantVal = variantTest.getVariant();
    variantVal = 5;
    /* std::visit is a function that applies a visitor (in this case, the visitor lambda) to a std::variant.
     *
     * The visitor lambda is called with the current value held by variantVal.
     *
     * Depending on the type of the value in variantVal, the appropriate branch of the if constexpr statement in the lambda is executed
     */
    emit logUpdatedSignal(std::visit(visitor, variantVal));

    variantVal = 5.5f;
    emit logUpdatedSignal(std::visit(visitor, variantVal));

    variantVal = true;
    emit logUpdatedSignal(std::visit(visitor, variantVal));

    if (m_shouldShowDoc)
    {
        QUrl url(QString::fromStdString(variantTest.getDocLink()));
        QDesktopServices::openUrl(url);

        url = QString::fromStdString(variantTest.getVisitDocLink());
        QDesktopServices::openUrl(url);
    }
}

} // namespace Learning
