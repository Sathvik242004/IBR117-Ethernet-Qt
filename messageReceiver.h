#pragma once
#include <QThread>
#include <QString>
#include <string>
#include "Ethernet.h" // Ensure this header is correctly included

class MessageReceiver : public QThread
{
    Q_OBJECT

public:
    explicit MessageReceiver(const std::string& ip, QObject *parent = nullptr);
    void run() override;
    void stop();

signals:
    void newMessage(const QString &message);

private:
    std::string ip;
    bool stopFlag;
};
