#include "districtshistorydeathsendpoint.h"

DistrictsHistoryDeathsEndpoint::DistrictsHistoryDeathsEndpoint(QString baseUrl): Endpoint(baseUrl, "districts/history/deaths")
{

}

void DistrictsHistoryDeathsEndpoint::handleReply(QNetworkReply *reply)
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

    DistrictsHistoryDeathsEndpointData *data = new DistrictsHistoryDeathsEndpointData(json);
    emit dataReceived(data);
    emit signalEndpointFetched();

    reply->deleteLater();
}
