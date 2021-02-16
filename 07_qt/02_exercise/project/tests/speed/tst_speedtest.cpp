#include <QtTest>
#include "speed.h"
#include "displacement.h"


class SpeedTest : public QObject
{
    Q_OBJECT

private slots:
    void OneValueSpeedTest()
    {
        Displacement displacement{};

        Speed speed{};

        Speed::connect(&displacement, SIGNAL(valueChanged(float)), &speed, SLOT(notify(float)));

        displacement.set(5);

        QCOMPARE(5.0, displacement.getValue());
        QVERIFY(speed.isHasFirstValue() == true);
        QVERIFY(speed.isHasSecondValue() == false);
        QCOMPARE(5.0, speed.getFirstValue());
        QCOMPARE(0.0, speed.getSecondValue());
        QCOMPARE(0.0, speed.get());
    }

    void TwoValuesSpeedTest()
    {
        Displacement displacement{};

        Speed speed{};

        Speed::connect(&displacement, SIGNAL(valueChanged(float)), &speed, SLOT(notify(float)));

        displacement.set(5);
        displacement.set(6);

        QCOMPARE(6.0, displacement.getValue());
        QVERIFY(speed.isHasFirstValue() == true);
        QVERIFY(speed.isHasSecondValue() == true);
        QCOMPARE(5.0, speed.getFirstValue());
        QCOMPARE(6.0, speed.getSecondValue());
        QCOMPARE(1.0, speed.get());
    }

};



QTEST_APPLESS_MAIN(SpeedTest)

#include "tst_speedtest.moc"

