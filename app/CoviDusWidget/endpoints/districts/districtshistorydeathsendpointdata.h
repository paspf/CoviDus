#ifndef DISTRICTSHISTORYDEATHSENDPOINTDATA_H
#define DISTRICTSHISTORYDEATHSENDPOINTDATA_H

#include "../metadata.h"
#include "districtshistorydeathsendpointdatainformation.h"
#include <QtNetwork>

class DistrictsHistoryDeathsEndpointData
{
public:
    explicit DistrictsHistoryDeathsEndpointData(QJsonDocument json);
    DistrictsHistoryDeathsEndpointData();
    QMap<QString, DistrictsHistoryDeathsEndpointDataInformation> data;
    MetaData meta;
    friend QDataStream &operator<<(QDataStream &out, const DistrictsHistoryDeathsEndpointData &data);
    friend QDataStream &operator>>(QDataStream &in, DistrictsHistoryDeathsEndpointData &data);
};

QDataStream &operator<<(QDataStream &out, const DistrictsHistoryDeathsEndpointData &data);
QDataStream &operator>>(QDataStream &in, DistrictsHistoryDeathsEndpointData &data);

#endif // DISTRICTSHISTORYDEATHSENDPOINTDATA_H
