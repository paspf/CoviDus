#ifndef DISTRICTSHISTORYCASESENDPOINT_H
#define DISTRICTSHISTORYCASESENDPOINT_H

#include "../endpoint.h"
#include "districtshistorycasesendpointdata.h"

class DistrictsHistoryCasesEndpoint : public Endpoint
{
    Q_OBJECT
public:
    DistrictsHistoryCasesEndpoint(QString baseUrl = "https://api.corona-zahlen.org");

signals:
    void dataReceived(DistrictsHistoryCasesEndpointData *data);

private:
    virtual void handleReply(QNetworkReply *reply) override;
};

#endif // DISTRITCSHISTORYCASESENDPOINT_H
