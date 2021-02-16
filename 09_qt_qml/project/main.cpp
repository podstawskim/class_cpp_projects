#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "speed.h"
#include "acceleration.h"
#include "displacement.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    qmlRegisterType<Displacement>("pl.podstawski", 1, 0, "Displacement");
    qmlRegisterType<Speed>("pl.podstawski", 1, 0, "Speed");
    qmlRegisterType<Acceleration>("pl.podstawski", 1, 0, "Acceleration");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    //qml objects visible in c++
    auto displacement = engine.rootObjects().first()->findChild<Displacement*>();
    auto speed = engine.rootObjects().first()->findChild<Speed*>();
    auto acceleration = engine.rootObjects().first()->findChild<Acceleration*>();

    //connecting slots and signals
    QObject::connect(displacement, SIGNAL(valueChanged(float)),
                     speed, SLOT(notify(float)));
    QObject::connect(displacement, SIGNAL(valueChanged(float)),
                     acceleration, SLOT(notify(float)));


    return app.exec();
}
