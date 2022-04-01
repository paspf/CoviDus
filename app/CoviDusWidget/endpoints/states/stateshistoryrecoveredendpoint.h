#ifndef STATESHISTORYRECOVEREDENDPOINT_H
#define STATESHISTORYRECOVEREDENDPOINT_H

#include"../endpoint.h"
#include"stateshistoryrecoveredendpointdata.h"

class StatesHistoryRecoveredEndpoint : public Endpoint
{
    Q_OBJECT
public:
    StatesHistoryRecoveredEndpoint(QString baseUrl = "https://api.corona-zahlen.org");

signals:
    void dataReceived(StatesHistoryRecoveredEndpointData *data);

private:
    virtual void handleReply(QNetworkReply *reply) override;
};

#endif // STATESHISTORYRECOVEREDENDPOINT_H
