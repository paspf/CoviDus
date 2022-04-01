#ifndef MAPDISTRICTSLEGENDENDPOINT_H
#define MAPDISTRICTSLEGENDENDPOINT_H

#include "../endpoint.h"
#include "../legendinfo.h"

class MapDistrictsLegendEndpoint : public Endpoint
{
    Q_OBJECT
public:
    MapDistrictsLegendEndpoint(QString baseUrl = "https://api.corona-zahlen.org");

signals:
    void dataReceived(QList<LegendInfo> *districtsLegend);

private:
    virtual void handleReply(QNetworkReply *reply) override;
};

#endif // MAPDISTRICTSLEGENDENDPOINT_H
