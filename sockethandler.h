#ifndef SOCKETHANDLER_H
#define SOCKETHANDLER_H

#include <QObject>
#include <QTcpSocket>
#include <QUdpSocket>

class sockethandler : public QObject
{
    Q_OBJECT

public:
    explicit sockethandler(QObject *parent = nullptr);
    ~sockethandler();

    void sendTcpMessage(const QString &message, const QString &ip, quint16 port);
    void sendUdpMessage(const QString &message, const QString &ip, quint16 port);
    void startTcpListening(quint16 port);
    void startUdpListening(quint16 port);
    void stopListening();

signals:
    void messageReceived(const QString &message);

private slots:
    void readTcpMessage();
    void readUdpMessage();

private:
    QTcpSocket *tcpSocket;
    QUdpSocket *udpSocket;
    QTcpSocket *tcpListener;
};

#endif // SOCKETHANDLER_H
