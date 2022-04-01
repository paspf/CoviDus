#ifndef DISTRICTSHISTORYINCIDENCEENDPOINTDATA_H
#define DISTRICTSHISTORYINCIDENCEENDPOINTDATA_H

#include "../metadata.h"
#include "districtshistoryincidenceendpointdatainformation.h"
#include <QtNetwork>

class DistrictsHistoryIncidenceEndpointData
{
public:
    explicit DistrictsHistoryIncidenceEndpointData(QJsonDocument json);
    DistrictsHistoryIncidenceEndpointData();
    QMap<QString, DistrictsHistoryIncidenceEndpointDataInformation> data;
    MetaData meta;
    friend QDataStream &operator<<(QDataStream &out, const DistrictsHistoryIncidenceEndpointData &data);
    friend QDataStream &operator>>(QDataStream &in, DistrictsHistoryIncidenceEndpointData &data);
};

QDataStream &operator<<(QDataStream &out, const DistrictsHistoryIncidenceEndpointData &data);
QDataStream &operator>>(QDataStream &in, DistrictsHistoryIncidenceEndpointData &data);

#endif // DISTRICTSHISTORYINCIDENCEENDPOINTDATA_H
