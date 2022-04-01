#ifndef STATESHISTORYRECOVEREDENDPOINTDATA_H
#define STATESHISTORYRECOVEREDENDPOINTDATA_H

#include<QJsonDocument>
#include"stateshistoryrecoveredendpointdatainformation.h"
#include"../metadata.h"

class StatesHistoryRecoveredEndpointData
{
public:
    explicit StatesHistoryRecoveredEndpointData(QJsonDocument json);
    StatesHistoryRecoveredEndpointData();
    QMap<QString, StatesHistoryRecoveredEndpointDataInformation> data;
    MetaData meta;
    friend QDataStream &operator<<(QDataStream &out, const StatesHistoryRecoveredEndpointData &data);
    friend QDataStream &operator>>(QDataStream &in, StatesHistoryRecoveredEndpointData &data);
};

QDataStream &operator<<(QDataStream &out, const StatesHistoryRecoveredEndpointData &data);
QDataStream &operator>>(QDataStream &in, StatesHistoryRecoveredEndpointData &data);

#endif // STATESHISTORYRECOVEREDENDPOINTDATA_H
