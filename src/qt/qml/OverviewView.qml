/*
    Overview view. The front page of the wallet
*/
import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Material
import QtQuick.Layouts
import MMPTheme 1.0

Rectangle {
    id: main
    color: MMPTheme.backgroundColor
    Rectangle {
        id: header
        color: MMPTheme.themeSelect(MMPTheme.cWhite, MMPTheme.cSpaceBlack)
        height: 70
        anchors {
            left: parent.left
            right: parent.right
            top: parent.top
        }
        Rectangle {
            id: bottomBorder
            height: 1
            color: MMPTheme.themeSelect("transparent", MMPTheme.cBlack)
            anchors {
                left: parent.left
                right: parent.right
                bottom: parent.bottom
            }
        }

        Text {
            id: titleText
            text: qsTr("Account Overview")
            font.weight: Font.DemiBold
            font.pixelSize: 22
            color: MMPTheme.textColor
            anchors {
                top: parent.top
                left: parent.left
                topMargin: 12
                leftMargin: 22
            }
        }
        MouseArea {
            id: cpidButton
            width: cpidText.width + cpidBorder.width + cpidText.anchors.leftMargin
            height: cpidBorder.height
            onClicked: {
                //TextEdit workaround without using C++, should probably be changed in the future
                cpidCopier.selectAll()
                cpidCopier.copy()
            }

            anchors {
                top: titleText.bottom
                left: parent.left
                topMargin: 2
                leftMargin: 22
            }

            Rectangle {
                id: cpidBorder
                border.color: MMPTheme.textColor
                radius: 10
                color: "transparent"
                width: cpidTitleText.implicitWidth + 20
                height: cpidTitleText.implicitHeight + 4
                anchors {
                    top: parent.top
                    left: parent.left
                }
                Text {
                    id: cpidTitleText
                    text: {
                        if (_researcherModel.researcherMode == 0) {
                            return qsTr("Non-cruncher");
                        } else if (_researcherModel.researcherMode == 1) {
                            return qsTr("Pool");
                        } else {
                            return qsTr("CPID");
                        }
                    }
                    color: MMPTheme.textColor
                    font.weight: Font.Light
                    anchors.centerIn: parent
                }
            }
            ToolTip {
                x: parent.width/2-width/2
                y: 20
                visible: cpidButton.pressed || visible   //Stay visible until timeout
                timeout: 1000
                contentItem: Text {
                    id: cpidCopiedText
                    text: qsTr("CPID copied")
                    color: MMPTheme.textColor
                    font.weight: Font.Light
                }
                background: Rectangle {
                    id: cpidCopiedBackground
                    color: MMPTheme.bodyColor
                    radius: 8
                    height: cpidCopiedText.implicitHeight+10
                    width: cpidCopiedText.implicitWidth+10
                    border.color: MMPTheme.borderColor
                    anchors.verticalCenter: cpidCopiedText.verticalCenter
                    anchors.horizontalCenter: cpidCopiedText.horizontalCenter
                }
            }

            Text {
                id: cpidText
                visible: _researcherModel.researcherMode == 2
                color: MMPTheme.textColor
                text: _researcherModel.cpid
                clip: true
                font.pixelSize: 10
                font.weight: Font.Light
                anchors {
                    left: cpidBorder.right
                    //right: parent.right
                    verticalCenter: cpidBorder.verticalCenter
                    leftMargin: 3
                }
                TextEdit{
                    id: cpidCopier
                    text: cpidText.text
                    visible: false
                }
            }
        }
        Row {
            id: headerStats
            spacing: 10
            layoutDirection: Qt.RightToLeft
            anchors {
                right: parent.right
                top: parent.top
                bottom: parent.bottom
                rightMargin: 20

            }
            Column {
                id: bal
                anchors.verticalCenter: parent.verticalCenter
                Text {
                    id: balanceValue
                    text: _walletModel.balance.toLocaleString(Qt.locale(), 'f', 2)
                    color: MMPTheme.highlightColor
                    font.pixelSize: 18
                    font.weight: Font.Medium
                    horizontalAlignment: Text.AllignHCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                }
                Text {
                    id: balanceLabel
                    text: qsTr("Your Balance")
                    color: MMPTheme.textColor
                    horizontalAlignment: Text.AllignHCenter
                    font.pixelSize: 10
                    font.weight: Font.Light
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }
            Rectangle {
                id: separator
                color: MMPTheme.separatorColor
                width: 1
                height: parent.height-30
                anchors.verticalCenter: parent.verticalCenter
            }
            Column {
                id: magnitude
                anchors.verticalCenter: parent.verticalCenter
                Text {
                    id: magValue
                    text: _researcherModel.magnitude
                    color: MMPTheme.highlightColor
                    font.pixelSize: 18
                    font.weight: Font.Medium
                    horizontalAlignment: Text.AllignHCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                }
                Text {
                    id: magLabel
                    text: qsTr("Magnitude")
                    color: MMPTheme.textColor
                    horizontalAlignment: Text.AllignHCenter
                    font.pixelSize: 10
                    font.weight: Font.Light
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }
        }

    }
    readonly property int panelSpacing: 10
    readonly property int panelRadius: 4
    readonly property int horBodyMargin: 20
    readonly property int vertBodyMargin: 10

    GridLayout {
        anchors {
            top: header.bottom
            bottom: parent.bottom
            left: parent.left
            right: parent.right
            margins: panelSpacing
        }

        columns: 2
        columnSpacing: panelSpacing

        ColumnLayout {
            spacing: panelSpacing
            Layout.fillWidth: true
            Layout.fillHeight: true

            Rectangle {
                id: walletDetailsPanel
                color: MMPTheme.bodyColor
                radius: panelRadius
                Layout.fillWidth: true
                Layout.preferredHeight: walletDetailsLayout.implicitHeight + 2 * vertBodyMargin

                ColumnLayout {
                    id: walletDetailsLayout
                    anchors.fill: parent
                    anchors.topMargin: vertBodyMargin
                    anchors.leftMargin: horBodyMargin
                    anchors.rightMargin: horBodyMargin
                    spacing: 10


                    PanelTitle {
                        id: walletDetailsTitle
                        text: qsTr("Wallet")
                        Layout.fillWidth: true

                        HelpHover{
                            id: walletHelp
                            popupWidth: 300
                            verticalPadding: 20
                            horiontalPadding: horBodyMargin
                            text:
                                "
                                    <html>
                                    <font color='"+MMPTheme.textColor+"'><b>" + qsTr("Available") + ":</b></font> " +
                                    qsTr("Balance available for spending") + "<br><br>
                                    <font color='"+MMPTheme.textColor+"'><b>" + qsTr("Stake") + ":</b></font> " +
                                    qsTr("Balance that is currently staked") + "<br><br>
                                    <font color='"+MMPTheme.textColor+"'><b>" + qsTr("Unconfirmed") + ":</b></font> " +
                                    qsTr("Coins that have been received but not yet confirmed") + "<br><br>
                                    <font color='"+MMPTheme.textColor+"'><b>" + qsTr("Total") + ":</b></font> " +
                                    qsTr("Your total coins") + "<br><br>
                                    <font color='"+MMPTheme.textColor+"'><b>" + qsTr("Research Rewards") + ":</b></font> " +
                                    qsTr("Earnt research rewards. Stake or make a manual reward claim in the receive view to receive them") + "
                                    </html>
                                "

                            anchors {
                                right: parent.right
                                verticalCenter: parent.verticalCenter
                            }

                        }
                    }

                    GridLayout {
                        id: balanceGridLayout
                        columns: 2
                        Layout.fillWidth: true
                        columnSpacing: 4
                        rowSpacing: 4

                        Text {
                            id: availableLabel
                            color: MMPTheme.textColor
                            text: qsTr("Available")+":"
                        }
                        Text {
                            id: availableValue
                            text: _walletModel.balance.toLocaleString(Qt.locale(), 'f', 2) + qsTr(" GRC")
                            color: MMPTheme.lightTextColor
                            horizontalAlignment: Text.AlignRight
                            Layout.fillWidth: true
                        }

                        Text {
                            id: stakeLabel
                            color: MMPTheme.textColor
                            text: qsTr("Stake")+":"
                        }
                        Text {
                            id: stakeValue
                            text: _walletModel.stake.toLocaleString(Qt.locale(), 'f', 2) + qsTr(" GRC")
                            color: MMPTheme.lightTextColor
                            horizontalAlignment: Text.AlignRight
                            Layout.fillWidth: true
                        }

                        Text {
                            id: unconfirmedLabel
                            color: MMPTheme.textColor
                            text: qsTr("Unconfirmed")+":"
                        }
                        Text {
                            id: unconfirmedValue
                            text: _walletModel.unconfirmedBalance.toLocaleString(Qt.locale(), 'f', 2) + qsTr(" GRC")
                            color: MMPTheme.lightTextColor
                            horizontalAlignment: Text.AlignRight
                            Layout.fillWidth: true
                        }

                        Text {
                            id: totalLabel
                            color: MMPTheme.textColor
                            font.weight: Font.DemiBold
                            text: qsTr("Total")+":"
                        }
                        Text {
                            id: totalValue
                            property real total: _walletModel.balance + _walletModel.stake + _walletModel.unconfirmedBalance
                            text: totalValue.total.toLocaleString(Qt.locale(), 'f', 2) + qsTr(" GRC")
                            color: MMPTheme.lightTextColor
                            font.weight: Font.DemiBold
                            horizontalAlignment: Text.AlignRight
                            Layout.fillWidth: true
                        }
                    }
                }
            }

            Rectangle {
                id: networkStatePanel
                color: MMPTheme.bodyColor
                radius: panelRadius
                Layout.fillWidth: true
                Layout.preferredHeight: networkStateLayout.implicitHeight + 2 * vertBodyMargin

                ColumnLayout {
                    id: networkStateLayout
                    anchors.fill: parent
                    anchors.topMargin: vertBodyMargin
                    anchors.leftMargin: horBodyMargin
                    anchors.rightMargin: horBodyMargin
                    spacing: 10

                    PanelTitle {
                        id: networkStateTitle
                        text: qsTr("Staking")
                        Layout.fillWidth: true

                        HelpHover {
                            id: networkStateQuestionMarkMouseOver
                            popupWidth: 300
                            verticalPadding: 20
                            horiontalPadding: horBodyMargin
                            text: "
                                <html>
                                <font color='"+MMPTheme.textColor+"'><b>" + qsTr("Blocks") + ":</b></font> " +
                                qsTr("The number of blocks your client currently has on the chain") + "<br><br>
                                <font color='"+MMPTheme.textColor+"'><b>" + qsTr("Difficulty") + ":</b></font> " +
                                qsTr("Current network difficulty. A larger value corresponds to smaller odds of staking") + "<br><br>
                                <font color='"+MMPTheme.textColor+"'><b>" + qsTr("Net Weight") + ":</b></font> " +
                                qsTr("Total number of coins on the entire network which are actively trying to stake") + "<br><br>
                                <font color='"+MMPTheme.textColor+"'><b>" + qsTr("Coin Weight") + ":</b></font> " +
                                qsTr("Number of your coins which are actively trying to stake") + "<br><br>
                                <font color='"+MMPTheme.textColor+"'><b>" + qsTr("Magnitude") + ":</b></font> " +
                                qsTr("Relative measure of your mining contributions") + "
                                </html>
                            "
                            anchors {
                                right: parent.right
                                verticalCenter: parent.verticalCenter
                            }
                        }
                    }

                    GridLayout {
                        columns: 2
                        Layout.fillWidth: true
                        columnSpacing: 4
                        rowSpacing: 4

                        Text {
                            id: blocksLabel
                            color: MMPTheme.textColor
                            text: qsTr("Blocks") + ":"
                        }
                        Text {
                            id: blockValue
                            text: {
                                if (_clientModel.numBlocks < _clientModel.numBlocksPeers) {
                                    var percent = Math.floor((_clientModel.numBlocks / _clientModel.numBlocksPeers) * 100)
                                    return qsTr("%1 of %2 (%3%)").arg(_clientModel.numBlocks).arg(_clientModel.numBlocksPeers).arg(percent)
                                } else {
                                    return _clientModel.numBlocks
                                }
                            }
                            color: MMPTheme.lightTextColor
                            horizontalAlignment: Text.AlignRight
                            Layout.fillWidth: true
                        }

                        Text {
                            id: difficultyLabel
                            color: MMPTheme.textColor
                            text: qsTr("Difficulty") + ":"
                        }
                        Text {
                            id: difficultyValue
                            text: _clientModel.difficulty.toLocaleString(Qt.locale(), 'f', 3)
                            color: MMPTheme.lightTextColor
                            horizontalAlignment: Text.AlignRight
                            Layout.fillWidth: true
                        }

                        Text {
                            id: netWeightLabel
                            color: MMPTheme.textColor
                            text: qsTr("Net Weight") + ":"
                        }
                        Text {
                            id: netWeightValue
                            text: _clientModel.networkWeight.toLocaleString(Qt.locale(), 'f', 0)
                            color: MMPTheme.lightTextColor
                            horizontalAlignment: Text.AlignRight
                            Layout.fillWidth: true
                        }

                        Text {
                            id: coinWeightLabel
                            color: MMPTheme.textColor
                            text: qsTr("Coin Weight") + ":"
                        }
                        Text {
                            id: coinWeightValue
                            text: _clientModel.coinWeight.toLocaleString(Qt.locale(), 'f', 0)
                            color: MMPTheme.lightTextColor
                            horizontalAlignment: Text.AlignRight
                            Layout.fillWidth: true
                        }
                    }
                }
            }

            Rectangle {
                id: researcherPanel
                color: MMPTheme.bodyColor
                radius: panelRadius
                Layout.fillWidth: true
                Layout.preferredHeight: researcherLayout.implicitHeight + 2 * vertBodyMargin

                ColumnLayout {
                    id: researcherLayout
                    anchors.fill: parent
                    anchors.topMargin: vertBodyMargin
                    anchors.leftMargin: horBodyMargin
                    anchors.rightMargin: horBodyMargin
                    spacing: 10

                    PanelTitle {
                        id: reseacherTitle
                        text: qsTr("Researcher")
                        Layout.fillWidth: true

                        HelpHover {
                            id: researcherHelp
                            popupWidth: 300
                            verticalPadding: 20
                            horiontalPadding: horBodyMargin
                            text: "
                                <html>
                                <font color='"+MMPTheme.textColor+"'><b>" + qsTr("Status:") + "</b></font> " +
                                qsTr("Current wallet status") + "<br><br>" +
                                "<font color='"+MMPTheme.textColor+"'><b>" + qsTr("Magnitude") + ":</b></font> " +
                                qsTr("Relative crunching") + "<br><br>" +
                                "<font color='"+MMPTheme.textColor+"'><b>" + qsTr("Research Rewards") + ":</b></font> " +
                                qsTr("Magnitude is a measure of your contribution to BOINC projects, calculated from your share of recent average credit (RAC) across whitelisted projects, and used to determine your daily Gridcoin rewards") + "
                                </html>
                            "
                            anchors {
                                right: parent.right
                                verticalCenter: parent.verticalCenter
                            }
                        }
                    }

                    GridLayout {
                        columns: 2
                        Layout.fillWidth: true
                        columnSpacing: 4
                        rowSpacing: 4

                        Text {
                            id: statusLabel
                            color: MMPTheme.textColor
                            font.pixelSize: 12
                            text: qsTr("Status:")
                        }
                        Text {
                            id: statusValue
                            text: _researcherModel.status
                            color: _clientModel.inSync ? MMPTheme.highlightColor : MMPTheme.cCarminePink
                            horizontalAlignment: Text.AlignRight
                            Layout.fillWidth: true
                        }

                        Text {
                            id: magnitudeLabel
                            color: MMPTheme.textColor
                            text: qsTr("Magnitude:")
                        }
                        Text {
                            id: magnitudeValue
                            text: _researcherModel.magnitude
                            color: MMPTheme.lightTextColor
                            horizontalAlignment: Text.AlignRight
                            Layout.fillWidth: true
                        }

                        Text {
                            id: pendingLabel
                            color: MMPTheme.textColor
                            text: qsTr("Pending Rewards:")
                        }
                        Text {
                            id: estRRValue
                            text: _researcherModel.accrual
                            color: MMPTheme.lightTextColor
                            horizontalAlignment: Text.AlignRight
                            Layout.fillWidth: true
                        }
                    }
                }
            }

            Rectangle {
                id: latestPollsPanel
                color: MMPTheme.bodyColor
                radius: panelRadius
                Layout.fillWidth: true
                height: pollsTitle.anchors.topMargin + pollsTitle.height + pollsInfo.anchors.topMargin + pollsInfo.height + vertBodyMargin
                PanelTitle {
                    id: pollsTitle
                    text: qsTr("Current Polls")
                    anchors {
                        left: parent.left
                        right: parent.right
                        top: parent.top
                        topMargin: vertBodyMargin
                        leftMargin: horBodyMargin
                        rightMargin: horBodyMargin
                    }
                }
                Text {
                    id: pollsInfo
                    color: MMPTheme.textColor
                    text: _votingModel.currentPollTitle
                    wrapMode: Text.WordWrap
                    anchors {
                        top: pollsTitle.bottom
                        left: parent.left
                        right: parent.right
                        leftMargin: horBodyMargin
                        rightMargin: horBodyMargin
                        topMargin: vertBodyMargin
                    }
                }
            }
        }

        Rectangle {
            id: recentTransactionsPanel
            color: MMPTheme.bodyColor
            radius: panelRadius
            Layout.fillWidth: true
            Layout.fillHeight: true

            PanelTitle {
                id: recentTransactionsTitle
                text: qsTr("Recent Transactions")
                anchors {
                    left: parent.left
                    right: parent.right
                    top: parent.top
                    topMargin: vertBodyMargin
                    leftMargin: horBodyMargin
                    rightMargin: horBodyMargin
                }
            }
            ListView {
                id: recentTransactionList
                contentWidth: width
                clip: true
                interactive: false
                anchors {
                    top: recentTransactionsTitle.bottom
                    left: parent.left
                    right: parent.right
                    bottom: parent.bottom
                    topMargin: vertBodyMargin
                    leftMargin: horBodyMargin
                    rightMargin: horBodyMargin
                    bottomMargin: vertBodyMargin
                }

                model: _walletModel.transactionTableModel
                delegate: RecentTransactionItem {
                    amount: model.amount
                    icon: model.iconSource
                    account: model.address
                    transactionDate: model.date
                }
                // ScrollIndicator.vertical: ScrollIndicator {
                //     parent: recentTransactionList.parent
                //     anchors {
                //         left: recentTransactionList.right
                //         leftMargin: 5
                //         top: recentTransactionList.top
                //         bottom: recentTransactionList.bottom
                //     }
                // }
            }

            Column {
                id: nothingYet
                padding: 5
                visible: recentTransactionList.count === 0
                anchors {
                    verticalCenter: parent.verticalCenter
                    horizontalCenter: parent.horizontalCenter
                }
                Image {
                    // id: clockImg
                    source: "qrc:/icons/generic/ic_no_result.svg"
                    anchors.horizontalCenter: parent.horizontalCenter
                    sourceSize: Qt.size(50, 50)
                }
                Text {
                    text: qsTr("Nothing here yet...")
                    color: MMPTheme.lightTextColor
                    horizontalAlignment: Text.AlignHCenter
                }
            }
        }
    }
}
