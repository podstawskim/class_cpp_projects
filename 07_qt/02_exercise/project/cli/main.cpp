#include <QCoreApplication>

#include "utils.h"
#include "speed.h"
#include "acceleration.h"
#include "displacement.h"
#include <QtDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Utils utils{};

    Speed speed{};
    Acceleration acceleration{};
    Displacement displacement{};

    Speed::connect(&displacement, SIGNAL(valueChanged(float)),
            &speed, SLOT(notify(float)) );
    Acceleration::connect(&displacement, SIGNAL(valueChanged(float)),
                          &acceleration, SLOT(notify(float)));

    displacement.set(10);
    displacement.set(11);
    displacement.set(13);

    qDebug() <<"Result: speed: " << speed.get()<< ", acceleration: " << acceleration.get();




    return a.exec();
}
