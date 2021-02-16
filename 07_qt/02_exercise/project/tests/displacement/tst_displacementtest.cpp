#include <QtTest>

#include "displacement.h"

class DisplacementTest : public QObject
{
    Q_OBJECT

public:


private slots:
    void DisplacementSetTest() {
        Displacement displacement{};
        displacement.set(10);

        QCOMPARE(10.0, displacement.getValue());

    };

    void SetAndEmitTest() {
        Displacement displacement{};

        QSignalSpy signalSpy(&displacement, SIGNAL(valueChanged(float)));

        displacement.set(1);

        QCOMPARE(signalSpy.count(), 1);
        QList<QVariant> arguments = signalSpy.takeFirst();
        QVERIFY(arguments.at(0).toBool() == true);

        QCOMPARE(1.0, displacement.getValue());

    }

    void SetTwoValuesAndEmitToSignals() {

        Displacement displacement{};

        QSignalSpy signalSpy(&displacement, SIGNAL(valueChanged(float)));

        displacement.set(1);
        displacement.set(2);

        QCOMPARE(signalSpy.count(), 2);
        QList<QVariant> arguments = signalSpy.takeFirst();

        QVERIFY(arguments.at(0).toBool() == true);


        QCOMPARE(2.0, displacement.getValue());

    }

    void noValueSetTest() {
        Displacement displacement{};

        QVERIFY(displacement.getValue() == false);

    }

    void noValueSetAndNoSignalEmit() {

        Displacement displacement{};

        QSignalSpy signalSpy(&displacement, SIGNAL(valueChanged(float)));

        QCOMPARE(signalSpy.count(), 0);

        QVERIFY(displacement.getValue() == false);

    }

};


QTEST_APPLESS_MAIN(DisplacementTest)

#include "tst_displacementtest.moc"
