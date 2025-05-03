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
    Q_INVOKABLE void testOptional();

signals:
    void clearLogSignal();
    void logUpdatedSignal(const QString& message);
};

}
