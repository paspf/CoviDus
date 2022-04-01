#include "districtshistoryfrozenincidenceendpoint.h"

DistrictsHistoryFrozenIncidenceEndpoint::DistrictsHistoryFrozenIncidenceEndpoint(QString baseUrl): Endpoint(baseUrl, "districts/history/frozen-incidence")
{

}

void DistrictsHistoryFrozenIncidenceEndpoint::handleReply(QNetworkReply *reply)
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

    DistrictsHistoryFrozenIncidenceEndpointData *data = new DistrictsHistoryFrozenIncidenceEndpointData(json);
    emit dataReceived(data);
    emit signalEndpointFetched();

    reply->deleteLater();
}
