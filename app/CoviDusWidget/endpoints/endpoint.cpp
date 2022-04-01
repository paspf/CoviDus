#include "endpoint.h"
#include <QTimer>

Endpoint::Endpoint(QString baseUrl, QString path)
{
    networkAccessManager = new QNetworkAccessManager();
    request.setUrl(baseUrl.remove(QRegularExpression("/$")) + "/" + path.remove(QRegularExpression("^/")));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    connect(networkAccessManager, &QNetworkAccessManager::finished, this, &Endpoint::handleReply);
}

void Endpoint::startRetryTimer()
{
    if (retryCounter > 24) {
        // qDebug() << "no more retries!";
        return;
    }
    retryCounter++;
    // qDebug() << "Start Retry Timer: " + QString::number(retryCounter);
    QTimer::singleShot(20000, this, &Endpoint::get);
}

void Endpoint::get()
{
    networkAccessManager->get(request);
}
