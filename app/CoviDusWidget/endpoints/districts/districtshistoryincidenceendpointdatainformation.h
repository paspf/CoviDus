#ifndef DISTRITCSHISTORYINCIDENCEENDPOINTDATAINFORMATION_H
#define DISTRITCSHISTORYINCIDENCEENDPOINTDATAINFORMATION_H

#include <QtNetwork>
#include "../historydata.h"

class DistrictsHistoryIncidenceEndpointDataInformation
{
public:
    explicit DistrictsHistoryIncidenceEndpointDataInformation(QJsonObject info);
    DistrictsHistoryIncidenceEndpointDataInformation();
    QString ags; //e.g. "09780"
    QString name; //e.g. "Oberallgäu"
    QList<HistoryData> history;
    friend QDataStream &operator<<(QDataStream &out, const DistrictsHistoryIncidenceEndpointDataInformation &data);
    friend QDataStream &operator>>(QDataStream &in, DistrictsHistoryIncidenceEndpointDataInformation &data);
};

QDataStream &operator<<(QDataStream &out, const DistrictsHistoryIncidenceEndpointDataInformation &data);
QDataStream &operator>>(QDataStream &in, DistrictsHistoryIncidenceEndpointDataInformation &data);

#endif // DISTRITCSHISTORYINCIDENCEENDPOINTDATAINFORMATION_H
