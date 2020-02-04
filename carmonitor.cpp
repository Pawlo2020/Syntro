#include "carmonitor.h"
#include <QDebug>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQuickItem>
#include <QTimer>
#include <QDateTime>

#include "globals.h"

Carmonitor::Carmonitor(QObject* parent):QObject(parent){
qDebug("Car monitor created");


QTimer* timer = new QTimer(this);
connect(timer, SIGNAL(timeout()), this, SLOT(getTime()));

timer->start();

}

//Gets current time
void Carmonitor::getTime(){
    if(_geng!=nullptr){
        QObject *root = _geng->rootObjects().value(0);

        QObject *rect = root->findChild<QObject*>("time");

        QObject *dateRect = root->findChild<QObject*>("date");

        //time_t now = time(0);

        if(rect){
//            rect->setProperty("text", ctime(&now));

            QTime time = QTime::currentTime();
            QString time_text = time.toString("hh:mm:ss");

            rect->setProperty("text", time_text);

            QDate date = QDate::currentDate();
            QString date_text = date.toString();
            dateRect->setProperty("text", date_text);


        }
}




}


