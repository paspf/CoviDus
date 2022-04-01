#ifndef GERMANYAGEGROUPSENDPOINT_H
#define GERMANYAGEGROUPSENDPOINT_H

#include "../endpoint.h"
#include "germanyagegroupsendpointdata.h"

class GermanyAgeGroupsEndpoint : public Endpoint
{
    Q_OBJECT
public:
    GermanyAgeGroupsEndpoint(QString baseUrl = "https://api.corona-zahlen.org");

signals:
    void dataReceived(GermanyAgeGroupsEndpointData *data);

private:
    virtual void handleReply(QNetworkReply *reply) override;
};

#endif // GERMANYAGEGROUPSENDPOINT_H
