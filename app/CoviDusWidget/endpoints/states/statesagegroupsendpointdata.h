#ifndef STATESAGEGROUPSENDPOINTDATA_H
#define STATESAGEGROUPSENDPOINTDATA_H

#include<QJsonDocument>
#include"statesagegroupsendpointdatainformation.h"
#include"../metadata.h"

class StatesAgeGroupsEndpointData
{
public:
    explicit StatesAgeGroupsEndpointData(QJsonDocument json);
    StatesAgeGroupsEndpointData();
    QMap<QString, StatesAgeGroupsEndpointDataInformation> data;
    MetaData meta;
    friend QDataStream &operator<<(QDataStream &out, const StatesAgeGroupsEndpointData &data);
    friend QDataStream &operator>>(QDataStream &in, StatesAgeGroupsEndpointData &data);
};

QDataStream &operator<<(QDataStream &out, const StatesAgeGroupsEndpointData &data);
QDataStream &operator>>(QDataStream &in, StatesAgeGroupsEndpointData &data);
#endif // STATESAGEGROUPSENDPOINTDATA_H
