#ifndef STATESHISTORYENDPOINT_H
#define STATESHISTORYENDPOINT_H

#include "../endpoint.h"
#include "stateshistorycasesendpointdata.h"

class StatesHistoryCasesEndpoint : public Endpoint
{
    Q_OBJECT
public:
    StatesHistoryCasesEndpoint(QString baseUrl = "https://api.corona-zahlen.org");

signals:
    void dataReceived(StatesHistoryCasesEndpointData *data);

private:
    virtual void handleReply(QNetworkReply *reply) override;
};

#endif // STATESHISTORYENDPOINT_H
