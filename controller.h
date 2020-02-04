#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QString>
class Controller : public QObject
{
    Q_OBJECT

private:
    int _currentGear=0;

    int mileage = 0;
    int milcount = 0;

    int fuelAmount=100;

    bool engine = false;
    bool lowBeams = false;
    bool fullBeams = false;

    bool lowOil = false;
    bool checkEngine = false;
    bool lowBattery = false;



public:
    Controller(QObject* parent=0);

    Q_INVOKABLE void onAccelMove(qreal real);

    //Q_INVOKABLE void getTime();

    QString gearTable[6]= {"N", "1", "2", "3", "4", "5"};


    Q_INVOKABLE void upGear();

    Q_INVOKABLE void downGear();

    Q_INVOKABLE void justDo();

    Q_INVOKABLE void switchEngine(bool force);

    Q_INVOKABLE void switchLowBeams();
    Q_INVOKABLE void switchFullBeams();

    Q_INVOKABLE void switchLowOil();
    Q_INVOKABLE void switchLowBattery();
    Q_INVOKABLE void switchCheckEngine();

    Q_INVOKABLE static void animateEngineTurnON();

    Q_INVOKABLE static void switchControlPanel(bool state);

    Q_INVOKABLE void updateView();

    Q_INVOKABLE void setSpeed();
};


#endif // CONTROLLER_H
