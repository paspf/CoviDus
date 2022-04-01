#ifndef MAPSTATESENDPOINT_H
#define MAPSTATESENDPOINT_H

#include "../endpoint.h"
#include <QImage>
#include <QImageReader>
#include <QPixmap>

class MapStatesEndpoint : public Endpoint
{
    Q_OBJECT
public:
    MapStatesEndpoint(QString baseUrl = "https://api.corona-zahlen.org");

signals:
    void dataReceived(QImage *image);

private:
    virtual void handleReply(QNetworkReply *reply) override;
};

#endif // MAPSTATESENDPOINT_H
