#include "mapstatesendpoint.h"

MapStatesEndpoint::MapStatesEndpoint(QString baseUrl): Endpoint(baseUrl, "map/states")
{
    request.setHeader(QNetworkRequest::ContentTypeHeader, "image/png");
}

void MapStatesEndpoint::handleReply(QNetworkReply *reply)
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
