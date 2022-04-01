#include "germanyendpoint.h"

GermanyEndpoint::GermanyEndpoint(QString baseUrl): Endpoint(baseUrl, "germany")
{

}

void GermanyEndpoint::handleReply(QNetworkReply *reply)
{
    if (reply->error())
    {
        qDebug() << reply->errorString();
        startRetryTimer();
        return;
    }
    qDebug() << reply->url();

    QByteArray response = reply->readAll();
    QJsonDocument json = QJsonDocument::fromJson(response);

    GermanyEndpointData *data = new GermanyEndpointData(json);
    emit dataReceived(data);
    emit signalEndpointFetched();

    reply->deleteLater();
}
