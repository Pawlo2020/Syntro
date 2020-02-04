#include "enginehandler.h"
#include <QQuickView>
#include <QQuickItem>



EngineHandler::EngineHandler()
{

}



void EngineHandler::giveengine(QQmlApplicationEngine* engine){
    //rootObj = root.value(0);
    _engine = engine;

}

