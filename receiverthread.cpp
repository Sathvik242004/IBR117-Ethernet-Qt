#include "receiverthread.h"
#include "Ethernet.h"

ReceiverThread::ReceiverThread(const QString& ip, int port, QObject* parent)
    : QThread(parent), ip(ip), port(port), serverConnection(nullptr) {}

void ReceiverThread::run()
{
    serverConnection = new senrec(ip.toStdString(), port);
    serverConnection->startListening([this](const std::string& message) {
        emit newMessageReceived(QString::fromStdString(message));
    });
    exec();  // Start the event loop
}

void ReceiverThread::stop()
{
    if (serverConnection) {
        delete serverConnection;
        serverConnection = nullptr;
    }
    quit();
    wait();
}
