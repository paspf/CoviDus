#include "germanyhistoryrecoveredendpoint.h"

GermanyHistoryRecoveredEndpoint::GermanyHistoryRecoveredEndpoint(QString baseUrl): Endpoint(baseUrl, "germany/history/recovered")
{

}

void GermanyHistoryRecoveredEndpoint::handleReply(QNetworkReply *reply)
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

    GermanyHistoryRecoveredEndpointData *data = new GermanyHistoryRecoveredEndpointData(json);
    emit dataReceived(data);
    emit signalEndpointFetched();

    reply->deleteLater();
}
