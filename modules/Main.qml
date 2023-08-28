import QtQuick
import QtQuick.Window

Window {
    property double windowWidth: 640
    property double windowHeight: 480
    property double iconBarWidth: windowWidth / 5
    property double iconSlideWidth: iconBarWidth / 2

    id: window_main
    width: windowWidth
    height: windowHeight
    visible: true
    title: qsTr("Hello World")

    SlideIcon {
        width: iconSlideWidth
        height: parent.height
        anchors.top: parent.top
        anchors.left: parent.left
    }
}
