#ifndef DISTRICTSHISTORYRECOVEREDENDPOINTDATA_H
#define DISTRICTSHISTORYRECOVEREDENDPOINTDATA_H

#include "../metadata.h"
#include "districtshistoryrecoveredendpointdatainformation.h"
#include <QtNetwork>

class DistrictsHistoryRecoveredEndpointData
{
public:
    explicit DistrictsHistoryRecoveredEndpointData(QJsonDocument json);
    DistrictsHistoryRecoveredEndpointData();
    QMap<QString, DistrictsHistoryRecoveredEndpointDataInformation> data;
    MetaData meta;
    friend QDataStream &operator<<(QDataStream &out, const DistrictsHistoryRecoveredEndpointData &data);
    friend QDataStream &operator>>(QDataStream &in, DistrictsHistoryRecoveredEndpointData &data);
};

QDataStream &operator<<(QDataStream &out, const DistrictsHistoryRecoveredEndpointData &data);
QDataStream &operator>>(QDataStream &in, DistrictsHistoryRecoveredEndpointData &data);

#endif // DISTRICTSHISTORYRECOVEREDENDPOINTDATA_H
