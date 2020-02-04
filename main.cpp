#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <test.h>
#include <carmonitor.h>
#include <controller.h>
#include <QGlobalStatic>
#include <enginehandler.h>



//confidetial
#include "globals.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<Carmonitor>("carmonitor", 1, 0, "Monitor");
    qmlRegisterType<Controller>("controller", 1,0,"Controller");



    QQmlApplicationEngine engine; //engine



    const QUrl url(QStringLiteral("qrc:/main.qml")); //main page url
    const QUrl url2(QStringLiteral("qrc:/ControlPanel.qml")); //ControlPanel window url
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url,url2](QObject *obj, const QUrl &objUrl) {


        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);


    }, Qt::QueuedConnection);

    _geng = &engine;

    engine.load(url);

    Carmonitor car;
    car.getTime();



    QQmlApplicationEngine eng2; //engine



    QObject::connect(&eng2, &QQmlApplicationEngine::objectCreated,
                     &app, [url2](QObject *obj2, const QUrl &objUrl2) {


        if (!obj2 && url2 == objUrl2)
            QCoreApplication::exit(-1);

    }, Qt::QueuedConnection);

    _ceng = &eng2;
    eng2.load(url2);

    return app.exec();
}
