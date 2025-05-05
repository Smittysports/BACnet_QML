#pragma once

#include <QObject>

namespace Learning {

class LearningInterface : public QObject
{
    Q_OBJECT
public:
    explicit LearningInterface(QObject *parent = nullptr);

    Q_INVOKABLE void clearLog();
    Q_INVOKABLE void notImplemented();
    Q_INVOKABLE void logText(const QString& text);
    Q_INVOKABLE void shouldShowDoc(const bool& choice);
    // C++ 11
    Q_INVOKABLE void testOriginalLambda();

    // C++17
    Q_INVOKABLE void testOptional();
    Q_INVOKABLE void testAny();
    Q_INVOKABLE void testVariant();

private:
    bool m_shouldShowDoc = false;

signals:
    void clearLogSignal();
    void logUpdatedSignal(const QString& message);
};

}
