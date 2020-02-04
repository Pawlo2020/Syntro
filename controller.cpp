#include "controller.h"
#include <QDebug>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQuickItem>
#include <QTimer>
#include <QDateTime>
#include <QThread>

#include "globals.h"

Controller::Controller(QObject* parent):QObject(parent){
qDebug("Controller created");


QTimer* timer = new QTimer(this);
connect(timer, SIGNAL(timeout()), this, SLOT(justDo()));

timer->start(20);
}

void Controller::switchEngine(bool force){
if(fuelAmount!=0 || force){


    engine = !engine;

if(engine){
if(_geng!=nullptr){
    QObject *root = _geng->rootObjects().value(0);

    QObject *hudOil = root->findChild<QObject*>("hudOil");

    if(hudOil){
        QThread *thread = QThread::create(animateEngineTurnON);

        thread->start();

    }

 }
}else{
    switchControlPanel(false);

    lowOil = false;
    lowBattery = false;
    lowBeams = false;
    fullBeams = false;
    checkEngine = false;
    engine = false;

    QObject *root = _geng->rootObjects().value(0);

    QObject *pointer = root->findChild<QObject*>("pointer");

    pointer->setProperty("targetRot", -30);

    updateView();
}

}
}

void Controller::animateEngineTurnON(){
    if(_geng!=nullptr){
        QObject *root = _geng->rootObjects().value(0);
        QObject *eng2 = _ceng->rootObjects().value(0);

        QObject *hudOil = root->findChild<QObject*>("hudOil");
        QObject *hudAccu = root->findChild<QObject*>("hudAccu");
        QObject *hudEngine = root->findChild<QObject*>("hudEngine");

        if(hudOil){
            hudOil->setProperty("source", QStringLiteral("qrc:/Assets/icons/nooil.png"));
            hudAccu->setProperty("source", QStringLiteral("qrc:/Assets/icons/accumulatorred.png"));
            hudEngine->setProperty("source", QStringLiteral("qrc:/Assets/icons/motorred.png"));

            Sleep(2000);

            hudOil->setProperty("source", QStringLiteral("qrc:/Assets/icons/car-light-GONE.png"));
            hudAccu->setProperty("source", QStringLiteral("qrc:/Assets/icons/car-light-GONE.png"));
            hudEngine->setProperty("source", QStringLiteral("qrc:/Assets/icons/car-light-GONE.png"));

            switchControlPanel(true);
        }
     }
}

void Controller::switchControlPanel(bool state){

    QObject *eng2 = _ceng->rootObjects().value(0);

    QObject *hudLowBeams = eng2->findChild<QObject*>("switchLowBeams");
    QObject *hudFull = eng2->findChild<QObject*>("switchFullBeams");
    QObject *hudLowBatt = eng2->findChild<QObject*>("switchLowBattery");
    QObject *hudCheckEng = eng2->findChild<QObject*>("switchCheckEngine");
    QObject *hudLowOil = eng2->findChild<QObject*>("switchLowOil");
    QObject *switcher = eng2->findChild<QObject*>("switchEngine");

    QObject *gearDownBtn = eng2->findChild<QObject*>("GearDownBtn");
    QObject *gearUpBtn = eng2->findChild<QObject*>("GearUpBtn");

    QObject *accelSlider = eng2->findChild<QObject*>("AccelSlider");
    QObject *handlingSlider = eng2->findChild<QObject*>("HandlingSlider");

    hudLowBeams->setProperty("checked", false);
    hudFull->setProperty("checked", false);
    hudLowBatt->setProperty("checked", false);
    hudCheckEng->setProperty("checked", false);
    hudLowOil->setProperty("checked", false);
    switcher->setProperty("checked", state);

    accelSlider->setProperty("value", -30);

    hudLowBeams->setProperty("enabled", state);
    hudFull->setProperty("enabled", state);
    hudLowBatt->setProperty("enabled", state);
    hudCheckEng->setProperty("enabled", state);
    hudLowOil->setProperty("enabled", state);

    gearDownBtn->setProperty("enabled", state);
    gearUpBtn->setProperty("enabled", state);

    accelSlider->setProperty("enabled", state);
    handlingSlider->setProperty("enabled", state);
}

void Controller::switchLowOil(){
lowOil = !lowOil;



if(_geng!=nullptr){
    QObject *root = _geng->rootObjects().value(0);

    QObject *rect = root->findChild<QObject*>("hudOil");

    if(rect){
        if(lowOil){
            rect->setProperty("source", QStringLiteral("qrc:/Assets/icons/nooil.png"));
        }

        if(!lowOil){
            rect->setProperty("source", QStringLiteral("qrc:/Assets/icons/car-light-GONE.png"));

        }

    }
}

}

void Controller::updateView(){
    if(_geng!=nullptr){
        QObject *root = _geng->rootObjects().value(0);

        QObject *hudOil = root->findChild<QObject*>("hudOil");
        QObject *hudAccu = root->findChild<QObject*>("hudAccu");
        QObject *hudEngine = root->findChild<QObject*>("hudEngine");
        QObject *hudLights = root->findChild<QObject*>("hudLights");

        if(hudOil){
            if(lowOil){
                hudOil->setProperty("source", QStringLiteral("qrc:/Assets/icons/nooil.png"));
            }

            if(!lowOil){
                hudOil->setProperty("source", QStringLiteral("qrc:/Assets/icons/car-light-GONE.png"));

            }

            if(lowBattery){
                hudAccu->setProperty("source", QStringLiteral("qrc:/Assets/icons/accumulatorred.png"));
            }

            if(!lowBattery){
                hudAccu->setProperty("source", QStringLiteral("qrc:/Assets/icons/car-light-GONE.png"));

            }

            if(checkEngine){
                hudEngine->setProperty("source", QStringLiteral("qrc:/Assets/icons/motorred.png"));
            }

            if(!checkEngine){
                hudEngine->setProperty("source", QStringLiteral("qrc:/Assets/icons/car-light-GONE.png"));

            }


            if(fullBeams){
                hudLights->setProperty("source", QStringLiteral("qrc:/Assets/icons/car-light-blu.png"));
            }

            if(!lowBeams && !fullBeams){
                hudLights->setProperty("source", QStringLiteral("qrc:/Assets/icons/car-light-GONE.png"));

            }

            if(!fullBeams && lowBeams){
                hudLights->setProperty("source", QStringLiteral("qrc:/Assets/icons/car-light-grn.png"));
            }


        }
    }
}

void Controller::switchLowBattery(){
lowBattery = !lowBattery;

if(_geng!=nullptr){
    QObject *root = _geng->rootObjects().value(0);

    QObject *rect = root->findChild<QObject*>("hudAccu");

    if(rect){
        if(lowBattery){
            rect->setProperty("source", QStringLiteral("qrc:/Assets/icons/accumulatorred.png"));
        }

        if(!lowBattery){
            rect->setProperty("source", QStringLiteral("qrc:/Assets/icons/car-light-GONE.png"));

        }

    }
}
}

void Controller::switchCheckEngine(){
checkEngine = !checkEngine;

if(_geng!=nullptr){
    QObject *root = _geng->rootObjects().value(0);

    QObject *rect = root->findChild<QObject*>("hudEngine");

    if(rect){
        if(checkEngine){
            rect->setProperty("source", QStringLiteral("qrc:/Assets/icons/motorred.png"));
        }

        if(!checkEngine){
            rect->setProperty("source", QStringLiteral("qrc:/Assets/icons/car-light-GONE.png"));

        }

    }
}
}

void Controller::switchLowBeams(){
lowBeams = !lowBeams;


//  source: "Assets/icons/car-light-grn.png"

if(_geng!=nullptr){
    QObject *root = _geng->rootObjects().value(0);

    QObject *rect = root->findChild<QObject*>("hudLights");

    if(rect){
        if(lowBeams && !fullBeams){
            rect->setProperty("source", QStringLiteral("qrc:/Assets/icons/car-light-grn.png"));
        }

        if(!lowBeams && !fullBeams){
            rect->setProperty("source", QStringLiteral("qrc:/Assets/icons/car-light-GONE.png"));

        }

    }
}
}

void Controller::switchFullBeams(){
fullBeams = !fullBeams;


if(_geng!=nullptr){
    QObject *root = _geng->rootObjects().value(0);

    QObject *rect = root->findChild<QObject*>("hudLights");

    if(rect){
        if(fullBeams){
            rect->setProperty("source", QStringLiteral("qrc:/Assets/icons/car-light-blu.png"));
        }

        if(!lowBeams && !fullBeams){
            rect->setProperty("source", QStringLiteral("qrc:/Assets/icons/car-light-GONE.png"));

        }

        if(!fullBeams && lowBeams){
            rect->setProperty("source", QStringLiteral("qrc:/Assets/icons/car-light-grn.png"));
        }

    }
}

}

void Controller::justDo(){
    setSpeed();
}

void Controller::onAccelMove(qreal real){
    //qDebug() << real;

    if(_geng!=nullptr){
        QObject *root = _geng->rootObjects().value(0);

        QObject *rect = root->findChild<QObject*>("pointer");
        QObject *rect2 = root->findChild<QObject*>("tek");

        if(rect){
            //QMetaObject::invokeMethod(rect2, "stop");
            rect->setProperty("targetRot", real);
            //QMetaObject::invokeMethod(rect2, "start");
            //rect2->setProperty("to", real);
            //QMetaObject::invokeMethod(rect2, "start");
        }

    }
}

void Controller::upGear(){
    if(_currentGear!=5){
        _currentGear++;
    }

    QObject *root = _geng->rootObjects().value(0);
    QObject *rect = root->findChild<QObject*>("gearLbl");

    if(rect){
        rect->setProperty("text", gearTable[_currentGear]);
    }


}

void Controller::downGear(){
    if(_currentGear!=0){
        _currentGear--;
    }

    QObject *root = _geng->rootObjects().value(0);
    QObject *rect = root->findChild<QObject*>("gearLbl");

    if(rect){
        rect->setProperty("text", gearTable[_currentGear]);
    }


}

void Controller::setSpeed(){

    if(_geng!=nullptr){
        QObject *root = _geng->rootObjects().value(0);
        QObject *ceng = _ceng->rootObjects().value(0);

        QObject *switcher = ceng->findChild<QObject*>("switchEngine");

        QObject *rect = root->findChild<QObject*>("pointer");
        QObject *rect2 = root->findChild<QObject*>("speedometer");

        QObject *handSlider = ceng->findChild<QObject*>("HandlingSlider");

        if(rect){
        rect->setProperty("rotation", rect->property("targetRot"));
        //qDebug() << rect->property("targetRot");

        float curSpeedVal = rect2->property("rotation").toFloat();
        float curAccelVal = rect->property("rotation").toFloat();

        float sliderVal = handSlider->property("value").toFloat();




        float definitiveBrakeAmount = 0.8 + sliderVal;

    switch(_currentGear){
        case 0:
            rect2->setProperty("rotation", curSpeedVal - definitiveBrakeAmount);
            break;

        case 1:
            //Animate speed rotation from -30 to -6

            if(!(curSpeedVal >= -6)){
                if(definitiveBrakeAmount > 1){
                    rect2->setProperty("rotation", (curSpeedVal + curAccelVal /  158) - definitiveBrakeAmount);
                }else{
                    rect2->setProperty("rotation", curSpeedVal + curAccelVal /  158);
                }
            }else if(!(curAccelVal > 0) || curSpeedVal > -6){
                rect2->setProperty("rotation", curSpeedVal - definitiveBrakeAmount);
            }

            break;

        case 2:
            //Animate speed rotation from -6 to 17

        if(!(curSpeedVal >= 17)){
            if(definitiveBrakeAmount > 1){
                rect2->setProperty("rotation", (curSpeedVal + curAccelVal /  158) - definitiveBrakeAmount);
            }else{
                rect2->setProperty("rotation", curSpeedVal + curAccelVal /  158);
            }
        }else if(!(curAccelVal > 0) || curSpeedVal > 17){
            rect2->setProperty("rotation", curSpeedVal - definitiveBrakeAmount);
        }
            break;

        case 3:
            //Animate speed rotation from 17 to 41
        if(!(curSpeedVal >= 41)){
            if(definitiveBrakeAmount > 1){
                rect2->setProperty("rotation", (curSpeedVal + curAccelVal /  158) - definitiveBrakeAmount);
            }else{
                rect2->setProperty("rotation", curSpeedVal + curAccelVal /  158);
            }
        }else if(!(curAccelVal > 0) || curSpeedVal > 41){
            rect2->setProperty("rotation", curSpeedVal - definitiveBrakeAmount);
        }
            break;

        case 4:
            //Animate speed rotation from 41 to 64
        if(!(curSpeedVal >= 64)){
            if(definitiveBrakeAmount > 1){
                rect2->setProperty("rotation", (curSpeedVal + curAccelVal /  158) - definitiveBrakeAmount);
            }else{
                rect2->setProperty("rotation", curSpeedVal + curAccelVal /  158);
            }

        }else if(!(curAccelVal > 0) || curSpeedVal > 64){
            rect2->setProperty("rotation", curSpeedVal - definitiveBrakeAmount);
        }
            break;

        case 5:
            //Animate speed rotation from 64 to 158
        if(!(curSpeedVal >= 158)){
            if(definitiveBrakeAmount > 1){
                rect2->setProperty("rotation", (curSpeedVal + curAccelVal /  158) - definitiveBrakeAmount);
            }else{
                rect2->setProperty("rotation", curSpeedVal + curAccelVal /  158);
            }

        }else if(!(curAccelVal > 0) || curSpeedVal > 158){
            rect2->setProperty("rotation", curSpeedVal - definitiveBrakeAmount);
        }
            break;
    }

    if(milcount > 1000){
        mileage += 1;
        milcount = 0;

        if(fuelAmount>0){
            fuelAmount--;
        }
    }

        QObject *hudFuel = root->findChild<QObject*>("hudFuel");



        if(hudFuel && engine){

            if(fuelAmount<=5 && fuelAmount>0){

                hudFuel->setProperty("source", QStringLiteral("qrc:/Assets/icons/nogasoline.png"));


            }else if(fuelAmount==0){
                qDebug("OFF");
                switchEngine(true);


            }


            else{
                hudFuel->setProperty("source", QStringLiteral("qrc:/Assets/icons/yesgasoline.png"));

            }
        }else if(switcher->property("checked")==true && fuelAmount==0){
            hudFuel->setProperty("source", QStringLiteral("qrc:/Assets/icons/nogasoline.png"));
        }else{
            hudFuel->setProperty("source", QStringLiteral("qrc:/Assets/icons/car-light-GONE.png"));

        }


    if(curSpeedVal > 0){
        milcount += 0.5 * (curSpeedVal / 20);
    }

    if(rect2->property("rotation").toInt() > 158)
        rect2->setProperty("rotation", 158);

    if(rect2->property("rotation").toInt() < -30)
        rect2->setProperty("rotation", -30);

        }


        QObject *milLbl = root->findChild<QObject*>("mileageLbl");

        QObject *fuel = root->findChild<QObject*>("fuelAmount");

        if(milLbl){
            milLbl->setProperty("text", mileage);
        }

        if(fuel){
            fuel->setProperty("text", fuelAmount);


        }



       }




}
