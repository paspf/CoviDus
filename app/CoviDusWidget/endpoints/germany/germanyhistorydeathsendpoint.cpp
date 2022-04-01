#include "germanyhistorydeathsendpoint.h"

GermanyHistoryDeathsEndpoint::GermanyHistoryDeathsEndpoint(QString baseUrl): Endpoint(baseUrl, "germany/history/deaths")
{

}

void GermanyHistoryDeathsEndpoint::handleReply(QNetworkReply *reply)
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

    GermanyHistoryDeathsEndpointData *data = new GermanyHistoryDeathsEndpointData(json);
    emit dataReceived(data);
    emit signalEndpointFetched();

    reply->deleteLater();
}
