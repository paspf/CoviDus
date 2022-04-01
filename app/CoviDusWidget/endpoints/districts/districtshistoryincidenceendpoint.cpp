#include "districtshistoryincidenceendpoint.h"

DistrictsHistoryIncidenceEndpoint::DistrictsHistoryIncidenceEndpoint(QString baseUrl): Endpoint(baseUrl, "districts/history/incidence")
{

}

void DistrictsHistoryIncidenceEndpoint::handleReply(QNetworkReply *reply)
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

    DistrictsHistoryIncidenceEndpointData *data = new DistrictsHistoryIncidenceEndpointData(json);
    emit dataReceived(data);
    emit signalEndpointFetched();

    reply->deleteLater();
}
