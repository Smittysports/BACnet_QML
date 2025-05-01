#pragma once

#include <QObject>

namespace Learning {

class LearningInterface : public QObject
{
    Q_OBJECT
public:
    explicit LearningInterface(QObject *parent = nullptr);

    Q_INVOKABLE void testOptional();
};

}
