#ifndef DISTRICTSENDPOINTDATA_H
#define DISTRICTSENDPOINTDATA_H

#include "../metadata.h"
#include "districtsendpointdatainformation.h"
#include <QtNetwork>

class DistrictsEndpointData
{
public:
    explicit DistrictsEndpointData(QJsonDocument json);
    DistrictsEndpointData();
    QMap<QString, DistrictsEndpointDataInformation> data;
    MetaData meta;
    friend QDataStream &operator<<(QDataStream &out, const DistrictsEndpointData &data);
    friend QDataStream &operator>>(QDataStream &in, DistrictsEndpointData &data);
};
QDataStream &operator<<(QDataStream &out, const DistrictsEndpointData &data);
QDataStream &operator>>(QDataStream &in, DistrictsEndpointData &data);

#endif // DISTRICTSENDPOINTDATA_H
