#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include "Ethernet.h"
#include <string.h>
#include <iostream>
#include "SocketHandler.h"
#include "RTC.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    socketHandler(new SocketHandler(this))
{
    ui->setupUi(this);
    timer=new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateRtClockTime);
    timer->start(1000);
    updateRtClockTime();
    connect(socketHandler, &SocketHandler::messageReceived, this, &MainWindow::updateTextBox);
    ui->diaip->setText(destinationip);
    ui->Devip->setText(deviceip);
    ui->portno->setText(QString::number(port));
    Ethfuncs::setDeviceEthIp(QString::number(port).toStdString());
    QString status1=socketHandler->startTcpListening(port);
    QString status2=socketHandler->startUdpListening(port);
    ui->downbox->setText("Device ip is set to "+deviceip+"\n Destination ip is set to "+destinationip+"\n"+status1+"\n"+status2);
}


MainWindow::~MainWindow()
{
    delete socketHandler;
    delete ui;
}

void MainWindow::on_diaip_textChanged(const QString &arg1)
{
    ui->socip->setText(arg1);
}

void MainWindow::on_socip_textChanged(const QString &arg1)
{
    ui->diaip->setText(arg1);
}

void MainWindow::on_tcpdia_clicked()
{
    ui->downbox->setText("Configure destination with iperf3 in Server mode\n use this command\n iperf3 -s");
    ui->downbox->append("starting TCP test\n This may take up to 20 seconds");
    QString output = QString::fromStdString(Ethfuncs::StartTCP(ui->diaip->text().toStdString()));
    ui->downbox->setText(output);
}

void MainWindow::on_udpdia_clicked()
{
    ui->downbox->setText("Configure destination with iperf3 in Server mode\n use this command\n iperf3 -s");
    ui->downbox->append("starting UDP test\n This may take up to 20 seconds");
    QString output = QString::fromStdString(Ethfuncs::StartUDP(ui->diaip->text().toStdString()));
    ui->downbox->setText(output);
}

void MainWindow::on_connected_clicked()
{
    if (TestEthernet::isConnected()){
        ui->downbox->setText("Connected");
    } else {
        ui->downbox->setText("Not Connected");
    }
}

void MainWindow::on_getWifiIP_clicked()
{
    ui->downbox->setText(QString::fromStdString(TestEthernet::getWlanIp()));
}

void MainWindow::on_getethip_clicked()
{
    ui->downbox->setText(QString::fromStdString(TestEthernet::getEthernetIp()));
}

void MainWindow::on_Internetstat_clicked()
{
    ui->downbox->setText("Testing Internet Connectivity...");
    if (TestEthernet::isInternetAvailable()){
        ui->downbox->setText("Connected to the Internet");
    } else {
        ui->downbox->setText("Internet not Available");
    }
}

void MainWindow::on_prop_clicked()
{
    ui->downbox->setText(QString::fromStdString(TestEthernet::getEthernetProperties()));
}



void MainWindow::on_tcpmes_clicked()
{
    QString message = ui->soctb->toPlainText();
    QString ip = ui->socip->text();
    QString status=socketHandler->sendTcpMessage(message, ip, port);
    ui->downbox->setText(status);
}

void MainWindow::on_udpmess_clicked()
{
    QString message = ui->soctb->toPlainText();
    QString ip = ui->socip->text();
    socketHandler->sendUdpMessage(message, ip, port);
}

void MainWindow::on_Listen_clicked()
{
    QString status1=socketHandler->startTcpListening(port);
    QString status2=socketHandler->startUdpListening(port);
    ui->downbox->setText(status1+"\n"+status2);

}

void MainWindow::on_StopListening_clicked()
{
    socketHandler->stopListening();
    ui->downbox->setText("Stopped Listening");
}


void MainWindow::updateTextBox(const QString &message)
{
    ui->soctb->append(message);
}

void MainWindow::on_setdestip_clicked()
{
    destinationip=ui->diaip->text();
    ui->downbox->setText("destination ip is set to "+ destinationip);
}


void MainWindow::on_setdevip_clicked()
{
    deviceip=ui->Devip->text();
    QString output=QString::fromStdString(Ethfuncs::setDeviceEthIp(deviceip.toStdString()));

    ui->downbox->setText(output);
}


void MainWindow::on_setportno_clicked()
{
    port=qint16(ui->portno->text().toShort());
    ui->downbox->setText("Port number is set");
}

void MainWindow::updateRtClockTime(){
    std::string currentTime = RTCClock::getTime();
    ui->time->setText(QString::fromStdString(currentTime));
}
