#ifndef DISTRICTSHISTORYDEATHSENDPOINT_H
#define DISTRICTSHISTORYDEATHSENDPOINT_H

#include "../endpoint.h"
#include "districtshistorydeathsendpointdata.h"

class DistrictsHistoryDeathsEndpoint : public Endpoint
{
    Q_OBJECT
public:
    DistrictsHistoryDeathsEndpoint(QString baseUrl = "https://api.corona-zahlen.org");

signals:
    void dataReceived(DistrictsHistoryDeathsEndpointData *data);

private:
    virtual void handleReply(QNetworkReply *reply) override;
};

#endif // DISTRICTSHISTORYDEATHSENDPOINT_H
