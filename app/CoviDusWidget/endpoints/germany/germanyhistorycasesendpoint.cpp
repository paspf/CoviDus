#include "germanyhistorycasesendpoint.h"

GermanyHistoryCasesEndpoint::GermanyHistoryCasesEndpoint(QString baseUrl): Endpoint(baseUrl, "germany/history/cases")
{

}

void GermanyHistoryCasesEndpoint::handleReply(QNetworkReply *reply)
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

    GermanyHistoryCasesEndpointData *data = new GermanyHistoryCasesEndpointData(json);
    emit dataReceived(data);
    emit signalEndpointFetched();

    reply->deleteLater();
}
