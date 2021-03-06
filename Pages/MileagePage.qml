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
        text: qsTr("Total distance:")
        font.pixelSize: 14
    }

    Text {
        objectName: "mileageLbl"
        id: fuelAmount
        x: 109
        y: 10
        color: "#ffffff"
        text: qsTr("353 000 km")
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
