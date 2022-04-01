#ifndef STATESHISTORYDEATHSENDPOINTDATA_H
#define STATESHISTORYDEATHSENDPOINTDATA_H

#include<QJsonDocument>
#include"stateshistorydeathsendpointdatainformation.h"
#include"../metadata.h"

class StatesHistoryDeathsEndpointData
{
public:
    explicit StatesHistoryDeathsEndpointData(QJsonDocument json);
    StatesHistoryDeathsEndpointData();
    QMap<QString, StatesHistoryDeathsEndpointDataInformation> data;
    MetaData meta;
    friend QDataStream &operator<<(QDataStream &out, const StatesHistoryDeathsEndpointData &data);
    friend QDataStream &operator>>(QDataStream &in, StatesHistoryDeathsEndpointData &data);
};

QDataStream &operator<<(QDataStream &out, const StatesHistoryDeathsEndpointData &data);
QDataStream &operator>>(QDataStream &in, StatesHistoryDeathsEndpointData &data);

#endif // STATESHISTORYDEATHSENDPOINTDATA_H
