#ifndef DISTRICTSHISTORYINCIDENCEENDPOINT_H
#define DISTRICTSHISTORYINCIDENCEENDPOINT_H

#include "../endpoint.h"
#include "districtshistoryincidenceendpointdata.h"

class DistrictsHistoryIncidenceEndpoint : public Endpoint
{
    Q_OBJECT
public:
    DistrictsHistoryIncidenceEndpoint(QString baseUrl = "https://api.corona-zahlen.org");

signals:
    void dataReceived(DistrictsHistoryIncidenceEndpointData *data);

private:
    virtual void handleReply(QNetworkReply *reply) override;
};

#endif // DISTRICTSHISTORYINCIDENCEENDPOINT_H
