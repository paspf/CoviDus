#include "germanyhistoryincidenceendpoint.h"

GermanyHistoryIncidenceEndpoint::GermanyHistoryIncidenceEndpoint(QString baseUrl): Endpoint(baseUrl, "germany/history/incidence")
{

}

void GermanyHistoryIncidenceEndpoint::handleReply(QNetworkReply *reply)
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

    GermanyHistoryIncidenceEndpointData *data = new GermanyHistoryIncidenceEndpointData(json);
    emit dataReceived(data);
    emit signalEndpointFetched();

    reply->deleteLater();
}
