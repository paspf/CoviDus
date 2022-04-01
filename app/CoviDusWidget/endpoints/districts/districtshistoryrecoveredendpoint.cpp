#include "districtshistoryrecoveredendpoint.h"

DistrictsHistoryRecoveredEndpoint::DistrictsHistoryRecoveredEndpoint(QString baseUrl): Endpoint(baseUrl, "districts/history/recovered")
{

}

void DistrictsHistoryRecoveredEndpoint::handleReply(QNetworkReply *reply)
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

    DistrictsHistoryRecoveredEndpointData *data = new DistrictsHistoryRecoveredEndpointData(json);
    emit dataReceived(data);
    emit signalEndpointFetched();

    reply->deleteLater();
}
