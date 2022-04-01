#ifndef DISTRICTSHISTORYCASESENDPOINTDATA_H
#define DISTRICTSHISTORYCASESENDPOINTDATA_H

#include "../metadata.h"
#include "districtshistorycasesendpointdatainformation.h"
#include <QtNetwork>

class DistrictsHistoryCasesEndpointData
{
public:
    explicit DistrictsHistoryCasesEndpointData(QJsonDocument json);
    DistrictsHistoryCasesEndpointData();
    QMap<QString, DistrictsHistoryCasesEndpointDataInformation> data;
    MetaData meta;
    friend QDataStream &operator<<(QDataStream &out, const DistrictsHistoryCasesEndpointData &data);
    friend QDataStream &operator>>(QDataStream &in, DistrictsHistoryCasesEndpointData &data);
};
QDataStream &operator<<(QDataStream &out, const DistrictsHistoryCasesEndpointData &data);
QDataStream &operator>>(QDataStream &in, DistrictsHistoryCasesEndpointData &data);

#endif // DISTRICTSHISTORYCASESENDPOINTDATA_H
