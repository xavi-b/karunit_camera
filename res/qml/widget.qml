import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtMultimedia 5.15

import Karunit 1.0

Item {
    anchors.fill: parent

    Camera {
        id: camera
        objectName: "camera"

        // position: Camera.BackFace
        videoRecorder {
            resolution: "1280x960"
            frameRate: 30
        }

        //  focus {
        //      focusMode: CameraFocus.FocusContinuous
        //      focusPointMode: CameraFocus.FocusPointAuto
        //  }
        Component.onCompleted: {
            var deviceId = KUSettings.get("karunit_camera/deviceId", "")
            if (deviceId)
                camera.deviceId = deviceId
        }
    }

    VideoOutput {
        id: viewfinder
        anchors.fill: parent
        source: camera
        autoOrientation: true
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            popup.open()
        }
    }

    Popup {
        id: popup

        anchors.centerIn: parent
        width: parent.width - 50
        height: parent.height - 50

        modal: true
        focus: true
        closePolicy: Popup.CloseOnEscape

        contentItem: Item {
            anchors.fill: parent
            anchors.margins: 5

            ListView {
                id: view
                snapMode: ListView.SnapOneItem
                highlightFollowsCurrentItem: true
                highlight: Rectangle {
                    color: "gray"
                }
                currentIndex: 0
                model: QtMultimedia.availableCameras

                width: 340
                anchors.top: parent.top
                anchors.bottom: closeButton.top
                anchors.horizontalCenter: parent.horizontalCenter

                delegate: Item {
                    width: 300
                    height: childrenRect.height

                    Text {
                        text: modelData.displayName

                        padding: 5
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        elide: Text.ElideRight
                        color: "orange"
                        font.bold: true
                        font.pixelSize: 14
                    }
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            view.currentIndex = index
                            camera.deviceId = modelData.deviceId
                            KUSettings.save("karunit_camera/deviceId",
                                            camera.deviceId)
                            popup.close()
                        }
                    }
                }
            }

            Button {
                id: closeButton

                anchors.right: parent.right
                anchors.bottom: parent.bottom

                text: qsTr("Close")
                onClicked: {
                    popup.close()
                }
            }
        }
    }
}
