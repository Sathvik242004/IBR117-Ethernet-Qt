#include "sockethandler.h"
#include <QDebug>

sockethandler::sockethandler(QObject *parent)
    : QObject(parent),
      tcpSocket(new QTcpSocket(this)),
      udpSocket(new QUdpSocket(this)),
      tcpListener(new QTcpSocket(this)) // Use QTcpServer in a real application
{
    connect(tcpSocket, &QTcpSocket::readyRead, this, &sockethandler::readTcpMessage);
    connect(udpSocket, &QUdpSocket::readyRead, this, &sockethandler::readUdpMessage);
}

sockethandler::~sockethandler()
{
    delete tcpSocket;
    delete udpSocket;
    delete tcpListener;
}

void sockethandler::sendTcpMessage(const QString &message, const QString &ip, quint16 port)
{
    tcpSocket->connectToHost(ip, port);
    if (tcpSocket->waitForConnected()) {
        tcpSocket->write(message.toUtf8());
        tcpSocket->flush();
        tcpSocket->disconnectFromHost();
    } else {
        qDebug() << "Failed to connect for TCP";
    }
}

void sockethandler::sendUdpMessage(const QString &message, const QString &ip, quint16 port)
{
    udpSocket->writeDatagram(message.toUtf8(), QHostAddress(ip), port);
}

void sockethandler::startTcpListening(quint16 port)
{
    tcpListener->bind(port);
    connect(tcpListener, &QTcpSocket::readyRead, this, &sockethandler::readTcpMessage);
}

void sockethandler::startUdpListening(quint16 port)
{
    udpSocket->bind(port);
}

void sockethandler::stopListening()
{
    tcpListener->disconnectFromHost();
    udpSocket->close();
}

void sockethandler::readTcpMessage()
{
    while (tcpSocket->canReadLine()) {
        QString message = tcpSocket->readLine();
        emit messageReceived(message);
    }
}

void sockethandler::readUdpMessage()
{
    while (udpSocket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(), datagram.size());
        emit messageReceived(QString(datagram));
    }
}
