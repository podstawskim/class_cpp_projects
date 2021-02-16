#include <QtTest>
#include "displacement.h"
#include "acceleration.h"


class AccelerationTest : public QObject
{
    Q_OBJECT

private slots:
    void OneValueTest() {
        Displacement displacement{};
        Acceleration acceleration{};

        Acceleration::connect(&displacement, SIGNAL(valueChanged(float)),
                &acceleration, SLOT(notify(float)) );

        displacement.set(5);

        QCOMPARE(5.0, displacement.getValue());
        QVERIFY(acceleration.isHasSecondValue() == false);
        QVERIFY(acceleration.isHasFirstValue() == true);
        QVERIFY(acceleration.isHasThirdValue() == false);
        QCOMPARE(5.0, acceleration.getFirstValue());
        QCOMPARE(0.0, acceleration.getSecondValue());
        QCOMPARE(0.0, acceleration.getThirdValue());
        QCOMPARE(0.0, acceleration.get());
    };
    void TwoValuesTest() {
        Displacement displacement{};
        Acceleration acceleration{};

        Acceleration::connect(&displacement, SIGNAL(valueChanged(float)),
                &acceleration, SLOT(notify(float)) );

        displacement.set(5);
        displacement.set(6);

        QCOMPARE(6.0, displacement.getValue());
        QVERIFY(acceleration.isHasSecondValue() == true);
        QVERIFY(acceleration.isHasFirstValue() == true);
        QVERIFY(acceleration.isHasThirdValue() == false);
        QCOMPARE(5.0, acceleration.getFirstValue());
        QCOMPARE(6.0, acceleration.getSecondValue());
        QCOMPARE(0.0, acceleration.getThirdValue());
        QCOMPARE(0.0, acceleration.get());
    };

    void ThirdValuesTest() {
        Displacement displacement{};
        Acceleration acceleration{};

        Acceleration::connect(&displacement, SIGNAL(valueChanged(float)),
                &acceleration, SLOT(notify(float)) );

        displacement.set(5);
        displacement.set(6);
        displacement.set(8);

        QCOMPARE(8.0, displacement.getValue());
        QVERIFY(acceleration.isHasSecondValue() == true);
        QVERIFY(acceleration.isHasFirstValue() == true);
        QVERIFY(acceleration.isHasThirdValue() == true);
        QCOMPARE(5.0, acceleration.getFirstValue());
        QCOMPARE(6.0, acceleration.getSecondValue());
        QCOMPARE(8.0, acceleration.getThirdValue());
        QCOMPARE(1.0, acceleration.get());
    };

};

QTEST_APPLESS_MAIN(AccelerationTest)

#include "tst_accelerationtest.moc"
