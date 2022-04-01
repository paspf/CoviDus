#ifndef GERMANYHISTORYRECOVEREDENDPOINT_H
#define GERMANYHISTORYRECOVEREDENDPOINT_H

#include "../endpoint.h"
#include "germanyhistoryrecoveredendpointdata.h"

class GermanyHistoryRecoveredEndpoint : public Endpoint
{
    Q_OBJECT
public:
    GermanyHistoryRecoveredEndpoint(QString baseUrl = "https://api.corona-zahlen.org");

signals:
    void dataReceived(GermanyHistoryRecoveredEndpointData *data);

private:
    virtual void handleReply(QNetworkReply *reply) override;
};

#endif // GERMANYHISTORYRECOVEREDENDPOINT_H
