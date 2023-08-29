import QtQuick
import QtQuick.Controls
import QtQuick.Shapes

Item {
    property double widget_width
    property double widget_height
    property double slide_width_ratio: 0.3
    property color background_color: "white"

    id: item_root
    width: rectangle_main.width
    height: widget_height

    Rectangle {
        id: rectangle_main
        width: slideIcon.width + slideContext.widget_height
        height: parent.height
        anchors.fill: parent
        border.color: Qt.darker(background_color, 2)
        border.width: 2

        SlideIcon {
            id: slideIcon
            width: item_root.widget_width * slide_width_ratio - 10
            height: parent.height
            anchors.top: parent.top
            anchors.left: parent.left
            onButton_menu_clicked: {
                slideContext.visible = !slideContext.visible
            }
        }

        SlideContext {
            id: slideContext
            widget_width: item_root.widget_width * (1 - slide_width_ratio) + 10
            widget_height: parent.height
            anchors.left: slideIcon.right
            anchors.top: parent.top
            background_color: item_root.background_color
        }
    }
}
