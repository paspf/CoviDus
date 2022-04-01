#ifndef DISTRICTSHISTORYFROZENINCIDENCEENDPOINTDATA_H
#define DISTRICTSHISTORYFROZENINCIDENCEENDPOINTDATA_H

#include "../metadata.h"
#include "districtshistoryfrozenincidenceendpointdatainformation.h"
#include <QtNetwork>

class DistrictsHistoryFrozenIncidenceEndpointData
{
public:
    explicit DistrictsHistoryFrozenIncidenceEndpointData(QJsonDocument json);
    DistrictsHistoryFrozenIncidenceEndpointData();
    QMap<QString, DistrictsHistoryFrozenIncidenceEndpointDataInformation> data;
    MetaData meta;
    friend QDataStream &operator<<(QDataStream &out, const DistrictsHistoryFrozenIncidenceEndpointData &data);
    friend QDataStream &operator>>(QDataStream &in, DistrictsHistoryFrozenIncidenceEndpointData &data);
};

QDataStream &operator<<(QDataStream &out, const DistrictsHistoryFrozenIncidenceEndpointData &data);
QDataStream &operator>>(QDataStream &in, DistrictsHistoryFrozenIncidenceEndpointData &data);

#endif // DISTRICTSHISTORYFROZENINCIDENCEENDPOINTDATA_H
