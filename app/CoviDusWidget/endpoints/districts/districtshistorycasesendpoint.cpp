#include "districtshistorycasesendpoint.h"

DistrictsHistoryCasesEndpoint::DistrictsHistoryCasesEndpoint(QString baseUrl): Endpoint(baseUrl, "districts/history/cases")
{

}

void DistrictsHistoryCasesEndpoint::handleReply(QNetworkReply *reply)
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

    DistrictsHistoryCasesEndpointData *data = new DistrictsHistoryCasesEndpointData(json);
    emit dataReceived(data);
    emit signalEndpointFetched();

    reply->deleteLater();
}
