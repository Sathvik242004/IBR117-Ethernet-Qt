#ifndef RECEIVERTHREAD_H
#define RECEIVERTHREAD_H

#include <QThread>
#include <QString>

class ReceiverThread : public QThread
{
    Q_OBJECT

public:
    ReceiverThread(const QString& ip, int port, QObject* parent = nullptr)
        : QThread(parent), ip(ip), port(port), serverConnection(nullptr) {}

    void run() override {
        serverConnection = new senrec(ip.toStdString(), port);
        serverConnection->startListening([this](const std::string& message) {
            emit newMessageReceived(QString::fromStdString(message));
        });
        exec();  // Start the event loop
    }

    void stop() {
        if (serverConnection) {
            delete serverConnection;
            serverConnection = nullptr;
        }
        quit();
        wait();
    }

signals:
    void newMessageReceived(const QString& message);

private:
    QString ip;
    int port;
    senrec* serverConnection;
};

#endif // RECEIVERTHREAD_H
