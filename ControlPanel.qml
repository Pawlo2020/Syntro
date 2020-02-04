import QtQuick 2.12
import QtQuick.Window 2.4
import QtQuick.Controls 2.12
import controller 1.0
Window {
    visible: true
    width: 800
    height: 350
    color: "#dcdfe5"
    title: qsTr("Syntro control panel")



    Switch {
        objectName: "switchEngine"
        id: element
        x: 46
        y: 175
        height: 40
        text: qsTr("Engine")
        checked: false
        checkable: true
        enabled: true
        font.pointSize: 12
        scale: 1
    }

    Switch {
        objectName: "switchLowBeams"
        id: element1
        x: 210
        y: 175
        height: 40
        text: qsTr("Low beams")
        enabled: false
        checked: false
        font.pointSize: 12
        scale: 1
    }

    Switch {
        objectName: "switchFullBeams"
        id: element2
        x: 410
        y: 175
        height: 40
        text: qsTr("Full beam")
        wheelEnabled: false
        font.preferShaping: true
        enabled: false
        font.pointSize: 12
        scale: 1
    }

    Slider {
        objectName: "AccelSlider"
        id: slider
        x: 33
        y: 49
        enabled: false
        to: 207
        from: -30
        value: -30
        Label {
            id: label
            x: 39
            y: 40
            width: 121
            height: 27
            text: qsTr("Acceleration")
            font.pointSize: 12
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.family: "Orbitron"
        }
    }

    Slider {
        objectName: "HandlingSlider"
        id: slider1
        x: 257
        y: 49
        to: 2
        enabled: false
        value: 0
        Label {
            id: label1
            x: 59
            y: 40
            width: 83
            height: 27
            text: qsTr("Handling")
            font.pointSize: 12
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.family: "Orbitron"
        }
    }

    Controller{
        id:controller
    }

    MenuBut {
        objectName: "GearUpBtn"
        id: menuBut
        x: 654
        y: 23
        width: 91
        height: 32
        text: "Gear up"
        enabled: false
        font.family: "Orbitron"
        font.pointSize: 12

        buttonClick: (function(){
            //console.log(controller.test())
            controller.upGear()
        }
            )
    }

    MenuBut {
        objectName: "GearDownBtn"
        id: menuBut1
        x: 654
        y: 71
        width: 91
        height: 32
        text: "Gear down"
        enabled: false
        font.family: "Orbitron"
        font.pointSize: 12

        buttonClick: (function(){
            //console.log(controller.test())
            controller.downGear()
        }
            )
    }

    Label {
        id: label2
        x: 22
        y: 9
        text: qsTr("Acceleration & Handling")
        font.family: "Orbitron"
        font.pointSize: 20
    }

    Label {
        id: label3
        x: 22
        y: 135
        width: 206
        height: 34
        text: qsTr("Instruments")
        font.family: "Orbitron"
        font.pointSize: 20
    }

    Connections {
        target: slider
        onMoved: controller.onAccelMove(slider.value)
    }

    Connections {
        target: element
        onClicked: controller.switchEngine(false)
    }

    Connections {
        target: element1
        onClicked: controller.switchLowBeams()
    }

    Connections {
        target: element2
        onClicked: controller.switchFullBeams()
    }

    Label {
        id: label4
        x: 22
        y: 232
        width: 206
        height: 34
        text: qsTr("Failures")
        font.pointSize: 20
        font.family: "Orbitron"
    }

    Switch {
        objectName: "switchLowOil"
        id: element3
        x: 40
        y: 278
        height: 40
        text: qsTr("Low oil")
        enabled: false
        font.pointSize: 12
        scale: 1
    }

    Switch {
        objectName: "switchLowBattery"
        id: element4
        x: 210
        y: 278
        height: 40
        text: qsTr("Low battery")
        enabled: false
        font.pointSize: 12
        scale: 1
    }

    Switch {
        objectName: "switchCheckEngine"
        id: element5
        x: 410
        y: 278
        height: 40
        text: qsTr("Check engine")
        enabled: false
        font.pointSize: 12
        scale: 1
    }

    Connections {
        target: element3
        onClicked: controller.switchLowOil()
    }

    Connections {
        target: element4
        onClicked: controller.switchLowBattery()
    }

    Connections {
        target: element5
        onClicked: controller.switchCheckEngine()
    }


}






