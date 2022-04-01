#ifndef GERMANYHISTORYINCIDENCEENDPOINT_H
#define GERMANYHISTORYINCIDENCEENDPOINT_H

#include "../endpoint.h"
#include "germanyhistoryincidenceendpointdata.h"

class GermanyHistoryIncidenceEndpoint : public Endpoint
{
    Q_OBJECT
public:
    GermanyHistoryIncidenceEndpoint(QString baseUrl = "https://api.corona-zahlen.org");

signals:
    void dataReceived(GermanyHistoryIncidenceEndpointData *data);

private:
    virtual void handleReply(QNetworkReply *reply);
};

#endif // GERMANYHISTORYINCIDENCEENDPOINT_H
