import QtQuick 2.12
import "../"
import QtQuick.Controls 2.12
Item {

    id: topelem
    width: 303
    height: 258

    signal go(string msg)

    Text {
        id: element
        x: 8
        y: 8
        width: 51
        height: 17
        color: "#ffffff"
        text: qsTr("Fuel: ")
        font.pixelSize: 14
    }

    Text {
        objectName: "fuelAmount"
        id: fuelAmount
        x: 65
        y: 10
        color: "#ffffff"
        text: qsTr("100%")
        font.pixelSize: 12
    }

    Text {
        id: element1
        x: 8
        y: 40
        color: "#ffffff"
        text: qsTr("Fuel/100km")
        font.pixelSize: 12
    }

    Text {
        id: fuelConsumption
        x: 86
        y: 40
        color: "#ffffff"
        text: qsTr("12l")
        font.pixelSize: 12
    }

    MenuBut {
        id: backBut
        x: -1
        y: 197
        text: "Back"
        textSize: 15

        buttonClick: (function(){


            topelem.go("Pages/MainPage.qml");


        }

            )




    }

}
