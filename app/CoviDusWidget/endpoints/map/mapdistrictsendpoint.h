#ifndef MAPDISTRICTSENDPOINT_H
#define MAPDISTRICTSENDPOINT_H

#include "../endpoint.h"
#include <QImage>
#include <QImageReader>
#include <QPixmap>

class MapDistrictsEndpoint : public Endpoint
{
    Q_OBJECT
public:
    MapDistrictsEndpoint(QString baseUrl = "https://api.corona-zahlen.org");

signals:
    void dataReceived(QImage *image);

private:
    virtual void handleReply(QNetworkReply *reply) override;
};

#endif // MAPDISTRICTSENDPOINT_H
