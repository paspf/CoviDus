#ifndef ENDPOINT_H
#define ENDPOINT_H

#include <QtNetwork>

class Endpoint : public QObject
{
    Q_OBJECT
protected:
    Endpoint(const QString baseUrl, const QString path);
    void startRetryTimer();
    QNetworkAccessManager *networkAccessManager;
    QNetworkRequest request;

public:
    void get();

signals:
    void signalEndpointFetched();

protected slots:
    virtual void handleReply(QNetworkReply *reply) = 0;

private:
    uint8_t retryCounter = 0;
};

#endif // ENDPOINT_H
