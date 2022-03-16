#ifndef TESTQTCLASS_H
#define TESTQTCLASS_H

#include <QObject>

class TestQtClass
{
    Q_OBJECT
public:
    TestQtClass();
};

Q_DECLARE_METATYPE(TestQtClass)

#endif // TESTQTCLASS_H
