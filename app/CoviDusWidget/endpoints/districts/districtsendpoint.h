#ifndef DISTRICTSENDPOINT_H
#define DISTRICTSENDPOINT_H

#include "../endpoint.h"
#include "districtsendpointdata.h"

class DistrictsEndpoint : public Endpoint
{
    Q_OBJECT
public:
    DistrictsEndpoint(QString baseUrl = "https://api.corona-zahlen.org");

signals:
    void dataReceived(DistrictsEndpointData *data);

private:
    virtual void handleReply(QNetworkReply *reply) override;
};

#endif // DISTRICTSENDPOINT_H
