#ifndef DISTRICTSHISTORYFROZENINCIDENCEENDPOINT_H
#define DISTRICTSHISTORYFROZENINCIDENCEENDPOINT_H

#include "../endpoint.h"
#include "districtshistoryfrozenincidenceendpointdata.h"

class DistrictsHistoryFrozenIncidenceEndpoint : public Endpoint
{
    Q_OBJECT
public:
    DistrictsHistoryFrozenIncidenceEndpoint(QString baseUrl = "https://api.corona-zahlen.org");

signals:
    void dataReceived(DistrictsHistoryFrozenIncidenceEndpointData *data);

private:
    virtual void handleReply(QNetworkReply *reply) override;
};

#endif // DISTRICTSHISTORYFROZENINCIDENCEENDPOINT_H
