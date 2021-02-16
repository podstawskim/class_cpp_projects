#include <QtTest>
#include "utils.h"

class DummyTest : public QObject
{
    Q_OBJECT

private slots:
    void add() {
        Utils utils{};
        QCOMPARE(3, utils.add(1, 2));

    }

//    void addError() {
//        Utils utils{};
//        QCOMPARE(4, utils.add(1, 3));

//    }
};


QTEST_APPLESS_MAIN(DummyTest)

#include "tst_dummytest.moc"
