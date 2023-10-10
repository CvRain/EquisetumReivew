import QtQuick
import QtQuick.Controls

Item {
    property double widget_width
    property double widget_height
    property color background_color: "white"
    property var context_list_view: listView

    id: item_root
    width: widget_width
    height: widget_height

    Rectangle {
        id: item_main
        width: item_root.widget_width
        height: parent.height
        anchors.fill: parent
        color: item_root.background_color

        ListView {
            id: listView
            width: parent
            height: parent
            anchors.fill: parent
        }
    }
}
