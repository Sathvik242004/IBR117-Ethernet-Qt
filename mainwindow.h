#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QProcess>
#include "Ethernet.h"
#include "SocketHandler.h"
#include "RTC.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_tcpdia_clicked();
    void on_udpdia_clicked();
    void on_connected_clicked();
    void on_getWifiIP_clicked();
    void on_getethip_clicked();
    void on_Internetstat_clicked();
    void on_prop_clicked();
    void on_tcpmes_clicked();
    void on_diaip_textChanged(const QString &arg1);
    void on_socip_textChanged(const QString &arg1);
    void on_udpmess_clicked();
    void on_Listen_clicked();
    void on_StopListening_clicked();
    void updateTextBox(const QString &message);
    void on_setdestip_clicked();
    void on_setdevip_clicked();
    void on_setportno_clicked();
    void updateRtClockTime();

private:
    Ui::MainWindow *ui;
    SocketHandler *socketHandler;
    QTimer* timer;
    QString destinationip="169.254.145.68";
    QString deviceip="169.254.22.22";
    quint16 port=5000;
};

#endif // MAINWINDOW_H
