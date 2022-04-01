#include "mapstateslegendendpoint.h"

MapStatesLegendEndpoint::MapStatesLegendEndpoint(QString baseUrl): Endpoint(baseUrl, "map/states/legend")
{

}

void MapStatesLegendEndpoint::handleReply(QNetworkReply *reply)
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

    QList<LegendInfo> *districtsLegend = new QList<LegendInfo>();
    QJsonArray incidentRanges = json["incidentRanges"].toArray();
    for (const auto &ir : incidentRanges) {
        QJsonObject elem = ir.toObject();
        districtsLegend->emplace_back(elem);
    }

    emit dataReceived(districtsLegend);
    emit signalEndpointFetched();

    reply->deleteLater();
}
