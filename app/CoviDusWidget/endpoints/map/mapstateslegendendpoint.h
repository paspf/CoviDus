#ifndef MAPSTATESLEGENDENDPOINT_H
#define MAPSTATESLEGENDENDPOINT_H

#include "../endpoint.h"
#include "../legendinfo.h"

class MapStatesLegendEndpoint : public Endpoint
{
    Q_OBJECT
public:
    MapStatesLegendEndpoint(QString baseUrl = "https://api.corona-zahlen.org");

signals:
    void dataReceived(QList<LegendInfo> *statesInfo);

private:
    virtual void handleReply(QNetworkReply *reply) override;
};

#endif // MAPSTATESLEGENDENDPOINT_H
