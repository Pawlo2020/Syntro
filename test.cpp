#include "test.h"
#include <QDebug>


test::test(QObject* parent):QObject(parent){



}

void test::printMessage(QString txt)
{
    qDebug() << "Message from QML: " << txt;
}





