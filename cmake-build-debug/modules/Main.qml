import QtQuick
import QtQuick.Window

Window {
    property double windowWidth: 840
    property double windowHeight: 480

    id: window_main
    width: windowWidth
    height: windowHeight
    visible: true
    title: qsTr("Hello World")

    SlideBar {
        id: slideBar
        widget_height: parent.height
        widget_width: windowWidth / 4
        slide_width_ratio: 0.3
        anchors.top: parent.top
        background_color: "#bbdcce"
        anchors.left: parent.left
    }
}
