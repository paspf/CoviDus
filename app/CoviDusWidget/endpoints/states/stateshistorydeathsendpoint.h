#ifndef STATESHISTORYDEATHSENDPOINT_H
#define STATESHISTORYDEATHSENDPOINT_H

#include"../endpoint.h"
#include"stateshistorydeathsendpointdata.h"

class StatesHistoryDeathsEndpoint : public Endpoint
{
    Q_OBJECT
public:
    StatesHistoryDeathsEndpoint(QString baseUrl = "https://api.corona-zahlen.org");

signals:
    void dataReceived(StatesHistoryDeathsEndpointData *data);

private:
    virtual void handleReply(QNetworkReply *reply) override;
};

#endif // STATESHISTORYDEATHSENDPOINT_H
