#ifndef GERMANYHISTORYDEATHSENDPOINT_H
#define GERMANYHISTORYDEATHSENDPOINT_H

#include "../endpoint.h"
#include "germanyhistorydeathsendpointdata.h"

class GermanyHistoryDeathsEndpoint : public Endpoint
{
    Q_OBJECT
public:
    GermanyHistoryDeathsEndpoint(QString baseUrl = "https://api.corona-zahlen.org");

signals:
    void dataReceived(GermanyHistoryDeathsEndpointData *data);

private:
    virtual void handleReply(QNetworkReply *reply) override;
};

#endif // GERMANYHISTORYDEATHSENDPOINT_H
