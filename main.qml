import QtQuick 2.12
import QtQuick.Window 2.4
import QtQuick.Controls 2.12
Window {
    visible: true
    width: 1200
    height: 600
    title: qsTr("Syntro")

    Image {
        id: background
        x: 0
        y: 0
        width: 1200
        height: 600
        antialiasing: true
        source: "Assets/clusterBG.png"
        fillMode: Image.PreserveAspectFit

        Text {
            id: element
            x: 313
            y: 481
            width: 191
            height: 68
            color: "#ffffff"
            text: "Syntro"
            font.family: "Astro"
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 24
        }

        Image {
            id: image
            x: 47
            y: 47
            width: 1106
            height: 428
            fillMode: Image.PreserveAspectFit
            source: "Assets/cockpitwhat.png"
        }

        Text {
            id: element1
            x: 384
            y: 529
            width: 574
            height: 40
            color: "#ffffff"
            text: "Remastered Polonez Caro car cluster simulator"
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 18
            font.family: "Orbitron"
            horizontalAlignment: Text.AlignHCenter
        }

        Sure {
            id: sure
            x: 122
            y: 106
            scale: 0.75
        }

        Speedometer {
            id: speedometer
            x: 736
            y: 106
            scale: 0.75
        }

        HUD {
            id: hUD
            x: 193
            y: 61
            scale: 0.75
        }

        MainPanel {
            id: mainPanel
            x: 281
            y: 48
            width: 638
            height: 426
            scale: 0.7
        }




    }

    Image {
        id: glass
        x: 48
        y: 47
        width: 1103
        height: 423
        fillMode: Image.PreserveAspectFit
        source: "Assets/cockpit glass cut.png"
    }
}






