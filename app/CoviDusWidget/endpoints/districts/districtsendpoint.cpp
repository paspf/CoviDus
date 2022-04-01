#include "districtsendpoint.h"

DistrictsEndpoint::DistrictsEndpoint(QString baseUrl): Endpoint(baseUrl, "districts")
{

}

void DistrictsEndpoint::handleReply(QNetworkReply *reply)
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
    DistrictsEndpointData *data = new DistrictsEndpointData(json);
    emit dataReceived(data);
    emit signalEndpointFetched();

    reply->deleteLater();
}
