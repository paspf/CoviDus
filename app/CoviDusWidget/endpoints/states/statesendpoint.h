#ifndef STATESENDPOINT_H
#define STATESENDPOINT_H
//#include <QObject>

#include "../endpoint.h"
#include "statesendpointdata.h"

class StatesEndpoint : public Endpoint
{
    Q_OBJECT
public:
    StatesEndpoint(QString baseUrl = "https://api.corona-zahlen.org");

signals:
    void dataReceived(StatesEndpointData *data);

private:
    virtual void handleReply(QNetworkReply *reply) override;
};

#endif // STATESENDPOINT_H
