#ifndef VACCINATIONSHISTORYENDPOINT_H
#define VACCINATIONSHISTORYENDPOINT_H

#include"../endpoint.h"
#include"vaccinationshistoryendpointdata.h"

class VaccinationsHistoryEndpoint : public Endpoint
{
    Q_OBJECT
public:
    VaccinationsHistoryEndpoint(QString baseUrl = "https://api.corona-zahlen.org");

signals:
    void dataReceived(VaccinationsHistoryEndpointData *data);

private:
    virtual void handleReply(QNetworkReply *reply) override;
};

#endif // VACCINATIONSHISTORYENDPOINT_H
