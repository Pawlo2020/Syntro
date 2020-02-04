import QtQuick 2.0

Item {
    id: hudBar
    width: 814
    height: 100
    Image {
        id: hudBack
        x: 0
        y: 0
        width: 814
        height: 100
        fillMode: Image.PreserveAspectFit
        source: "Assets/tophud.png"
    }

    Image {
        objectName: "hudFuel"
        id: fuel
        x: 218
        y: 13
        width: 45
        height: 45
        fillMode: Image.PreserveAspectFit
        source: "Assets/icons/car-light-GONE.png"
    }

    Image {
        objectName: "hudOil"
        id: oil
        x: 295
        y: 13
        width: 45
        height: 45
        fillMode: Image.PreserveAspectFit
        source: "Assets/icons/car-light-GONE.png"
    }

    Image {
        objectName: "hudAccu"
        id: accu
        x: 385
        y: 13
        width: 45
        height: 45
        fillMode: Image.PreserveAspectFit
        source: "Assets/icons/car-light-GONE.png"
    }

    Image {
        objectName: "hudEngine"
        id: engine
        x: 471
        y: 13
        width: 45
        height: 45
        fillMode: Image.PreserveAspectFit
        source: "Assets/icons/car-light-GONE.png"
    }

    Image {
        objectName: "hudLights"
        id: lights
        x: 560
        y: 13
        width: 45
        height: 45
        fillMode: Image.PreserveAspectFit
        source: "Assets/icons/car-light-GONE.png"
    }

}
