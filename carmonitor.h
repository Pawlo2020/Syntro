#ifndef CARMONITOR_H
#define CARMONITOR_H

#include <QObject>
#include <ctime>
#include <string.h>
#include <conio.h>
#include <QString>
class Carmonitor : public QObject
{
    Q_OBJECT




public:
    Carmonitor(QObject* parent=0);

    Q_INVOKABLE void getTime();
};




#endif // CARMONITOR_H
