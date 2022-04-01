#include "statesendpoint.h"

StatesEndpoint::StatesEndpoint(QString baseUrl): Endpoint(baseUrl, "states")
{

}

void StatesEndpoint::handleReply(QNetworkReply *reply)
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

    StatesEndpointData *data = new StatesEndpointData(json);
    emit dataReceived(data);
    emit signalEndpointFetched();

    reply->deleteLater();
}
