#ifndef GERMANYHISTORYCASESENDPOINT_H
#define GERMANYHISTORYCASESENDPOINT_H

#include "../endpoint.h"
#include "germanyhistorycasesendpointdata.h"

class GermanyHistoryCasesEndpoint : public Endpoint
{
    Q_OBJECT
public:
    GermanyHistoryCasesEndpoint(QString baseUrl = "https://api.corona-zahlen.org");

signals:
    void dataReceived(GermanyHistoryCasesEndpointData *data);

private:
    virtual void handleReply(QNetworkReply *reply) override;
};

#endif // GERMANYHISTORYCASESENDPOINT_H
