// A temporary view used for testing controls, etc. Should not appear in a release.
import QtQuick 2.15
import QtQuick.Controls 2.15
import MMPTheme 1.0

ScrollView {
    id: scrollView
    anchors.fill: parent
    width: parent.width
    background: Rectangle {
        anchors.fill: parent
        color: MMPTheme.backgroundColor
    }

    Column {
        anchors.fill: parent
        spacing: 15
        padding: 15

        GroupBox {
            width: scrollView.width - 2*parent.padding
            title: qsTr("Button")

            Grid {
                spacing: 5
                padding: 5
                anchors.fill: parent

                columns: 3

                Button {
                    text: qsTr("Default")
                    onReleased: {
                        if (MMPTheme.isLightTheme){
                            MMPTheme.theme = MMPTheme.darkTheme
                        } else {
                            MMPTheme.theme = MMPTheme.lightTheme
                        }
                    }
                }
                Button {
                    text: qsTr("Default")
                    icon.source: MMPTheme.themeSelect("qrc:/res/icons/buttons/ic_btn_verify_light.svg", "qrc:/res/icons/buttons/ic_btn_verify_dark.svg")
                    onPressed: console.log(Qt.locale())
                }

                Button {
                    icon.source: MMPTheme.themeSelect("qrc:/res/icons/buttons/ic_btn_verify_light.svg", "qrc:/res/icons/buttons/ic_btn_verify_dark.svg")
                }


                Button {
                    text: qsTr("Disabled")
                    enabled: false
                }

                Button {
                    text: qsTr("Disabled")
                    icon.source: MMPTheme.themeSelect("qrc:/res/icons/buttons/ic_btn_verify_light.svg", "qrc:/res/icons/buttons/ic_btn_verify_dark.svg")
                    enabled: false
                }

                Button {
                    icon.source: MMPTheme.themeSelect("qrc:/res/icons/buttons/ic_btn_verify_light.svg", "qrc:/res/icons/buttons/ic_btn_verify_dark.svg")
                    enabled: false
                }
            }
        }

        GroupBox {
            width: scrollView.width - 2*parent.padding
            title: qsTr("TextArea")
            Column {
                spacing: 5
                padding: 5
                anchors.fill: parent

                TextArea {
                    text: qsTr("This\nis\nfocused\ntextarea")
                }

                TextArea {
                    text: qsTr("This\nis\ndefault\ntextarea")
                }

                TextArea {
                    text: qsTr("This\nis\ndisabled\ntextarea")
                    enabled: false
                }

                ScrollView {
                    height: 24*4
                    width: 200
                    TextArea {
                        text: qsTr("This\nis\na\nscrollable\nplaceholder\ntextarea")
                    }
                }

                TextArea {
                    placeholderText: qsTr("This\nis\nplaceholder\ntextarea")
                }
            }
        }

        GroupBox {
            width: scrollView.width - 2*parent.padding
            title: qsTr("ComboBox")
            ListModel {
                id: comboModel
                ListElement {
                    name: "Focused"
                }
                ListElement {
                    name: "Default"
                }
                ListElement
                {
                    name: "TEst"
                }
            }

            Column {
                spacing: 5
                padding: 5
                anchors.fill: parent

                ComboBox {
                    model: comboModel
                }

                ComboBox {
                    model: [qsTr("Disabled")]
                    enabled: false
                }
            }
        }

        GroupBox {
            width: scrollView.width - 2*parent.padding
            title: qsTr("SpinBox")
            Column {
                spacing: 5
                padding: 5
                anchors.fill: parent

                SpinBox {
                    value: 50
                    editable: true
                }

                SpinBox {
                    value: 50
                }

                SpinBox {
                    value: 50
                    enabled: false
                }
            }
        }

        GroupBox {
            width: scrollView.width - 2*parent.padding
            title: qsTr("CheckBox")
            Column {
                spacing: 5
                padding: 5
                anchors.fill: parent

                CheckBox {
                    text: qsTr("Selected")
                    checked: true
                }

                CheckBox {
                    text: qsTr("Normal")
                }

                CheckBox {
                    text: qsTr("Hover")
                    active: true
                }
            }
        }

        GroupBox {
            width: scrollView.width - 2*parent.padding
            title: qsTr("RadioButton")
            Column {
                spacing: 5
                padding: 5
                anchors.fill: parent

                RadioButton {
                    text: qsTr("Selected")
                    checked: true
                }

                RadioButton {
                    text: qsTr("Normal")
                }

                RadioButton {
                    text: qsTr("Hover")
                    active: true
                }
            }
        }

        GroupBox {
            width: scrollView.width - 2*parent.padding
            title: qsTr("TextField")
            Column {
                spacing: 5
                padding: 5
                anchors.fill: parent

                TextField {
                    text: qsTr("Default")
                }

                TextField {
                    text: qsTr("Active")
                }

                TextField {
                    text: qsTr("Disabled")
                    enabled: false
                }

                TextField {
                    placeholderText: qsTr("Placeholder Default")
                }

                TextField {
                    placeholderText: qsTr("Placeholder Active")
                }

                TextField {
                    placeholderText: qsTr("Placeholder Disabled")
                    enabled: false
                }
            }
        }
    }
}
