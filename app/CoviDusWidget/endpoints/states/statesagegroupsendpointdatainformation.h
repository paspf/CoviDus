#ifndef STATESAGEGROUPSENDPOINTDATAINFORMATION_H
#define STATESAGEGROUPSENDPOINTDATAINFORMATION_H

#include<QJsonObject>
#include"../agegroupdata.h"

class StatesAgeGroupsEndpointDataInformation
{
public:
    explicit StatesAgeGroupsEndpointDataInformation(QJsonObject info);
    StatesAgeGroupsEndpointDataInformation();
    AgeGroupData a00_a04;
    AgeGroupData a05_a14;
    AgeGroupData a15_a34;
    AgeGroupData a35_a59;
    AgeGroupData a60_a79;
    AgeGroupData a80_over;
    friend QDataStream &operator<<(QDataStream &out, const StatesAgeGroupsEndpointDataInformation &data);
    friend QDataStream &operator>>(QDataStream &in, StatesAgeGroupsEndpointDataInformation &data);
};

QDataStream &operator<<(QDataStream &out, const StatesAgeGroupsEndpointDataInformation &data);
QDataStream &operator>>(QDataStream &in, StatesAgeGroupsEndpointDataInformation &data);

#endif // STATESAGEGROUPSENDPOINTDATAINFORMATION_H
