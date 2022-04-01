#ifndef GERMANYENDPOINT_H
#define GERMANYENDPOINT_H
//#include <QObject>

#include "../endpoint.h"
#include "germanyendpointdata.h"

class GermanyEndpoint : public Endpoint
{
    Q_OBJECT
public:
    GermanyEndpoint(QString baseUrl = "https://api.corona-zahlen.org");

signals:
    void dataReceived(GermanyEndpointData *data);

private:
    virtual void handleReply(QNetworkReply *reply) override;
};

#endif // GERMANYENDPOINT_H
