import QtQuick 2.12
import "../"
import QtQuick.Controls 2.12
import carmonitor 1.0
Item {
    id: topelem
    width: 303
    height: 258

    signal go(string msg)

    MenuBut {
        id: fuelBut
        x: 0
        y: 31
        text: "Fuel economy"
        textSize: 15

        buttonClick: (function(){


            topelem.go("Pages/FuelPage.qml");
        }

            )
    }

    MenuBut {
        id: mileageBut
        x: -2
        y: 113
        text: "Mileage"
        textSize: 15

        buttonClick: (function(){
            topelem.go("Pages/MileagePage.qml");
        }
            )
    }

    MenuBut {
        id: aboutBut
        x: -2
        y: 194
        text: "About"
        textSize: 15

        buttonClick: (function(){

            //monit.getTime();
            topelem.go("Pages/AboutPage.qml");
        }

            )

    }

}
