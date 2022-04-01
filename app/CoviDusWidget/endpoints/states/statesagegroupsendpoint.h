#ifndef STATESAGEGROUPSENDPOINT_H
#define STATESAGEGROUPSENDPOINT_H

#include"statesagegroupsendpointdata.h"
#include "../endpoint.h"

class StatesAgeGroupsEndpoint : public Endpoint
{
    Q_OBJECT
public:
    StatesAgeGroupsEndpoint(QString baseUrl = "https://api.corona-zahlen.org");

signals:
    void dataReceived(StatesAgeGroupsEndpointData *data);

private:
    virtual void handleReply(QNetworkReply *reply) override;
};

#endif // STATESAGEGROUPSENDPOINT_H
