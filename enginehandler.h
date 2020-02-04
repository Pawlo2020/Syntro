#ifndef ENGINEHANDLER_H
#define ENGINEHANDLER_H
#include <QQmlApplicationEngine>
#include <QGuiApplication>

class EngineHandler
{
    QQmlApplicationEngine* _engine;


QObject* rootObj;

public:
    EngineHandler();
void giveengine(QQmlApplicationEngine* engine);
};

#endif // ENGINEHANDLER_H
