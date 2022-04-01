#ifndef DISTRICTSHISTORYFROZENINCIDENCEENDPOINTDATAINFORMATION_H
#define DISTRICTSHISTORYFROZENINCIDENCEENDPOINTDATAINFORMATION_H

#include <QtNetwork>
#include "../historydata.h"

class DistrictsHistoryFrozenIncidenceEndpointDataInformation
{
public:
    explicit DistrictsHistoryFrozenIncidenceEndpointDataInformation(QJsonObject info);
    DistrictsHistoryFrozenIncidenceEndpointDataInformation();
    QString ags; //e.g. "09780"
    QString name; //e.g. "Oberallgäu"
    QList<HistoryData> history;
    friend QDataStream &operator<<(QDataStream &out, const DistrictsHistoryFrozenIncidenceEndpointDataInformation &data);
    friend QDataStream &operator>>(QDataStream &in, DistrictsHistoryFrozenIncidenceEndpointDataInformation &data);
};

QDataStream &operator<<(QDataStream &out, const DistrictsHistoryFrozenIncidenceEndpointDataInformation &data);
QDataStream &operator>>(QDataStream &in, DistrictsHistoryFrozenIncidenceEndpointDataInformation &data);

#endif // DISTRICTSHISTORYFROZENINCIDENCEENDPOINTDATAINFORMATION_H
