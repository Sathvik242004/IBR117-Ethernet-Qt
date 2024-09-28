/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_7;
    QTextEdit *downbox;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *Internetstat;
    QPushButton *connected;
    QPushButton *getethip;
    QPushButton *prop;
    QPushButton *getWifiIP;
    QFormLayout *formLayout_3;
    QLineEdit *Devip;
    QPushButton *setdevip;
    QWidget *layoutWidget1;
    QFormLayout *formLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QLineEdit *diaip;
    QLabel *label;
    QPushButton *tcpdia;
    QLabel *label_3;
    QPushButton *udpdia;
    QLabel *label_5;
    QWidget *layoutWidget2;
    QFormLayout *formLayout_2;
    QLabel *label_6;
    QLabel *label_4;
    QLineEdit *socip;
    QTextEdit *soctb;
    QPushButton *udpmess;
    QPushButton *tcpmes;
    QPushButton *Listen;
    QPushButton *StopListening;
    QPushButton *setdestip;
    QFormLayout *formLayout_4;
    QLineEdit *portno;
    QPushButton *setportno;
    QLabel *label_10;
    QPushButton *settime;
    QLineEdit *timeip;
    QLabel *time;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1024, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(410, 10, 151, 41));
        label_7->setStyleSheet(QStringLiteral("font: 57 18pt \"Ubuntu\";"));
        downbox = new QTextEdit(centralwidget);
        downbox->setObjectName(QStringLiteral("downbox"));
        downbox->setGeometry(QRect(0, 430, 1021, 131));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(70, 70, 351, 184));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        Internetstat = new QPushButton(layoutWidget);
        Internetstat->setObjectName(QStringLiteral("Internetstat"));

        gridLayout->addWidget(Internetstat, 4, 0, 1, 1);

        connected = new QPushButton(layoutWidget);
        connected->setObjectName(QStringLiteral("connected"));

        gridLayout->addWidget(connected, 0, 0, 1, 1);

        getethip = new QPushButton(layoutWidget);
        getethip->setObjectName(QStringLiteral("getethip"));

        gridLayout->addWidget(getethip, 2, 0, 1, 1);

        prop = new QPushButton(layoutWidget);
        prop->setObjectName(QStringLiteral("prop"));

        gridLayout->addWidget(prop, 5, 0, 1, 1);

        getWifiIP = new QPushButton(layoutWidget);
        getWifiIP->setObjectName(QStringLiteral("getWifiIP"));

        gridLayout->addWidget(getWifiIP, 1, 0, 1, 1);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        Devip = new QLineEdit(layoutWidget);
        Devip->setObjectName(QStringLiteral("Devip"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, Devip);

        setdevip = new QPushButton(layoutWidget);
        setdevip->setObjectName(QStringLiteral("setdevip"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, setdevip);


        gridLayout->addLayout(formLayout_3, 6, 0, 1, 1);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(70, 270, 355, 145));
        formLayout = new QFormLayout(layoutWidget1);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        formLayout->setItem(0, QFormLayout::FieldRole, horizontalSpacer_2);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        diaip = new QLineEdit(layoutWidget1);
        diaip->setObjectName(QStringLiteral("diaip"));

        formLayout->setWidget(1, QFormLayout::FieldRole, diaip);

        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral("font: 57 15pt \"Ubuntu\";"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label);

        tcpdia = new QPushButton(layoutWidget1);
        tcpdia->setObjectName(QStringLiteral("tcpdia"));

        formLayout->setWidget(2, QFormLayout::FieldRole, tcpdia);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QStringLiteral("font: 57 15pt \"Ubuntu\";"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        udpdia = new QPushButton(layoutWidget1);
        udpdia->setObjectName(QStringLiteral("udpdia"));

        formLayout->setWidget(3, QFormLayout::FieldRole, udpdia);

        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setStyleSheet(QStringLiteral("font: 16pt \"Ubuntu\";"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_5);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(550, 60, 401, 351));
        formLayout_2 = new QFormLayout(layoutWidget2);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setStyleSheet(QStringLiteral("font: 16pt \"Ubuntu\";"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_6);

        label_4 = new QLabel(layoutWidget2);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_4);

        socip = new QLineEdit(layoutWidget2);
        socip->setObjectName(QStringLiteral("socip"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, socip);

        soctb = new QTextEdit(layoutWidget2);
        soctb->setObjectName(QStringLiteral("soctb"));

        formLayout_2->setWidget(3, QFormLayout::SpanningRole, soctb);

        udpmess = new QPushButton(layoutWidget2);
        udpmess->setObjectName(QStringLiteral("udpmess"));

        formLayout_2->setWidget(8, QFormLayout::FieldRole, udpmess);

        tcpmes = new QPushButton(layoutWidget2);
        tcpmes->setObjectName(QStringLiteral("tcpmes"));

        formLayout_2->setWidget(7, QFormLayout::FieldRole, tcpmes);

        Listen = new QPushButton(layoutWidget2);
        Listen->setObjectName(QStringLiteral("Listen"));

        formLayout_2->setWidget(7, QFormLayout::LabelRole, Listen);

        StopListening = new QPushButton(layoutWidget2);
        StopListening->setObjectName(QStringLiteral("StopListening"));

        formLayout_2->setWidget(8, QFormLayout::LabelRole, StopListening);

        setdestip = new QPushButton(layoutWidget2);
        setdestip->setObjectName(QStringLiteral("setdestip"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, setdestip);

        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName(QStringLiteral("formLayout_4"));
        portno = new QLineEdit(layoutWidget2);
        portno->setObjectName(QStringLiteral("portno"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, portno);

        setportno = new QPushButton(layoutWidget2);
        setportno->setObjectName(QStringLiteral("setportno"));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, setportno);


        formLayout_2->setLayout(0, QFormLayout::FieldRole, formLayout_4);

        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(70, 40, 349, 24));
        label_10->setStyleSheet(QStringLiteral("font: 16pt \"Ubuntu\";"));
        settime = new QPushButton(centralwidget);
        settime->setObjectName(QStringLiteral("settime"));
        settime->setGeometry(QRect(850, 20, 89, 25));
        timeip = new QLineEdit(centralwidget);
        timeip->setObjectName(QStringLiteral("timeip"));
        timeip->setGeometry(QRect(730, 20, 113, 25));
        time = new QLabel(centralwidget);
        time->setObjectName(QStringLiteral("time"));
        time->setGeometry(QRect(60, 10, 171, 21));
        time->setStyleSheet(QStringLiteral("font: 17pt \"Ubuntu\";"));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label_7->setText(QApplication::translate("MainWindow", "Ethernet Tool", 0));
        Internetstat->setText(QApplication::translate("MainWindow", "Get Internet Status", 0));
        connected->setText(QApplication::translate("MainWindow", "Verify Ethernet Connection", 0));
        getethip->setText(QApplication::translate("MainWindow", "Get Ethernet IP", 0));
        prop->setText(QApplication::translate("MainWindow", "Get Ethernet Properties", 0));
        getWifiIP->setText(QApplication::translate("MainWindow", "Get Wi-Fi IP", 0));
        setdevip->setText(QApplication::translate("MainWindow", "Set Device Ip", 0));
        label_2->setText(QApplication::translate("MainWindow", "Enter destination IP", 0));
        label->setText(QApplication::translate("MainWindow", "Test TCP Connection", 0));
        tcpdia->setText(QApplication::translate("MainWindow", "Start TCP Diagonstics", 0));
        label_3->setText(QApplication::translate("MainWindow", "Test UDP Connection", 0));
        udpdia->setText(QApplication::translate("MainWindow", "Start UDP Diagonstics", 0));
        label_5->setText(QApplication::translate("MainWindow", "Run Diagonstics", 0));
        label_6->setText(QApplication::translate("MainWindow", "Socket", 0));
        label_4->setText(QApplication::translate("MainWindow", "Enter destination IP", 0));
        soctb->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Type your message here...</p></body></html>", 0));
        udpmess->setText(QApplication::translate("MainWindow", "Send Message using UDP", 0));
        tcpmes->setText(QApplication::translate("MainWindow", "Send Message using TCP", 0));
        Listen->setText(QApplication::translate("MainWindow", "Listen for Messages", 0));
        StopListening->setText(QApplication::translate("MainWindow", "Stop Listening", 0));
        setdestip->setText(QApplication::translate("MainWindow", "Set Destination ip", 0));
        setportno->setText(QApplication::translate("MainWindow", "Set Port", 0));
        label_10->setText(QApplication::translate("MainWindow", "Quick help", 0));
        settime->setText(QApplication::translate("MainWindow", "Set Time", 0));
        time->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
