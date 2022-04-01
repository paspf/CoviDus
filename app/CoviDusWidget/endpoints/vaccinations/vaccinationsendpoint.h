#ifndef VACCINATIONSENDPOINT_H
#define VACCINATIONSENDPOINT_H

#include "../endpoint.h"
#include "vaccinationsendpointdata.h"

class VaccinationsEndpoint : public Endpoint
{
    Q_OBJECT
public:
    VaccinationsEndpoint(QString baseUrl = "https://api.corona-zahlen.org");

signals:
    void dataReceived(VaccinationsEndpointData *data);

private:
    virtual void handleReply(QNetworkReply *reply) override;
};

#endif // VACCINATIONSENDPOINT_H
