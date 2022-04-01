#ifndef DISTRICTSHISTORYRECOVEREDENDPOINT_H
#define DISTRICTSHISTORYRECOVEREDENDPOINT_H

#include "../endpoint.h"
#include "districtshistoryrecoveredendpointdata.h"

class DistrictsHistoryRecoveredEndpoint : public Endpoint
{
    Q_OBJECT
public:
    DistrictsHistoryRecoveredEndpoint(QString baseUrl = "https://api.corona-zahlen.org");

signals:
    void dataReceived(DistrictsHistoryRecoveredEndpointData *data);

private:
    virtual void handleReply(QNetworkReply *reply) override;
};

#endif // DISTRICTSHISTORYRECOVEREDENDPOINT_H
