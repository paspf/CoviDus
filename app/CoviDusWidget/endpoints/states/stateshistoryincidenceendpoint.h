#ifndef STATESHISTORYINCIDENCEENDPOINT_H
#define STATESHISTORYINCIDENCEENDPOINT_H

#include"../endpoint.h"
#include"stateshistoryincidenceendpointdata.h"

class StatesHistoryIncidenceEndpoint : public Endpoint
{
    Q_OBJECT
public:
    StatesHistoryIncidenceEndpoint(QString baseUrl = "https://api.corona-zahlen.org");

signals:
    void dataReceived(StatesHistoryIncidenceEndpointData *data);

private:
    virtual void handleReply(QNetworkReply *reply) override;
};

#endif // STATESHISTORYINCIDENCEENDPOINT_H
