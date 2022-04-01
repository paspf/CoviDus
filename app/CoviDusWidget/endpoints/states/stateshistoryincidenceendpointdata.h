#ifndef STATESHISTORYINCIDENCEENDPOINTDATA_H
#define STATESHISTORYINCIDENCEENDPOINTDATA_H

#include<QJsonDocument>
#include"stateshistoryincidenceendpointdatainformation.h"
#include"../metadata.h"

class StatesHistoryIncidenceEndpointData
{
public:
    explicit StatesHistoryIncidenceEndpointData(QJsonDocument json);
    StatesHistoryIncidenceEndpointData();
    QMap<QString, StatesHistoryIncidenceEndpointDataInformation> data;
    MetaData meta;
    friend QDataStream &operator<<(QDataStream &out, const StatesHistoryIncidenceEndpointData &data);
    friend QDataStream &operator>>(QDataStream &in, StatesHistoryIncidenceEndpointData &data);
};

QDataStream &operator<<(QDataStream &out, const StatesHistoryIncidenceEndpointData &data);
QDataStream &operator>>(QDataStream &in, StatesHistoryIncidenceEndpointData &data);

#endif // STATESHISTORYINCIDENCEENDPOINTDATA_H
