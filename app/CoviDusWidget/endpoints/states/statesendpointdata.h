#ifndef STATESENDPOINTDATA_H
#define STATESENDPOINTDATA_H

#include <QtNetwork>
#include "../metadata.h"
#include "statesendpointdatainformation.h"


class StatesEndpointData
{
public:
    explicit StatesEndpointData(QJsonDocument json);
    StatesEndpointData();
    QMap<QString, StatesEndpointDataInformation> data;
    MetaData meta;
    friend QDataStream &operator<<(QDataStream &out, const StatesEndpointData &data);
    friend QDataStream &operator>>(QDataStream &in, StatesEndpointData &data);
};

QDataStream &operator<<(QDataStream &out, const StatesEndpointData &data);
QDataStream &operator>>(QDataStream &in, StatesEndpointData &data);

#endif // STATESENDPOINTDATA_H
