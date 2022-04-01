#ifndef STATESHISTORYENDPOINTDATA_H
#define STATESHISTORYENDPOINTDATA_H

#include <QtNetwork>
#include "../metadata.h"
#include "stateshistorycasesendpointdatainformation.h"

class StatesHistoryCasesEndpointData
{
public:
    explicit StatesHistoryCasesEndpointData(QJsonDocument json);
    StatesHistoryCasesEndpointData();
    QMap<QString, StatesHistoryCasesEndpointDataInformation> data;
    MetaData meta;
    friend QDataStream &operator<<(QDataStream &out, const StatesHistoryCasesEndpointData &data);
    friend QDataStream &operator>>(QDataStream &in, StatesHistoryCasesEndpointData &data);
};

QDataStream &operator<<(QDataStream &out, const StatesHistoryCasesEndpointData &data);
QDataStream &operator>>(QDataStream &in, StatesHistoryCasesEndpointData &data);
#endif // STATESHISTORYENDPOINTDATA_H
