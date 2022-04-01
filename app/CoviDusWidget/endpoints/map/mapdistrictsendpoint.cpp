#include "mapdistrictsendpoint.h"

MapDistrictsEndpoint::MapDistrictsEndpoint(QString baseUrl): Endpoint(baseUrl, "map/districts")
{
    request.setHeader(QNetworkRequest::ContentTypeHeader, "image/png");
}

void MapDistrictsEndpoint::handleReply(QNetworkReply *reply)
{
    if (reply->error())
    {
        qDebug() << reply->errorString();
        startRetryTimer();
        return;
    }

    qDebug() << reply->url();

    QImage *image = new QImage();
    image->loadFromData(reply->readAll(), "PNG");

    emit dataReceived(image);
    emit signalEndpointFetched();

    reply->deleteLater();
}
