#ifndef GERMANYAGEGROUPSENDPOINTDATA_H
#define GERMANYAGEGROUPSENDPOINTDATA_H

#include "../metadata.h"
#include "germanyagegroupsendpointdatainformation.h"
#include <QtNetwork>

class GermanyAgeGroupsEndpointData
{
public:
    explicit GermanyAgeGroupsEndpointData(QJsonDocument json);
    GermanyAgeGroupsEndpointData();
    GermanyAgeGroupsEndpointDataInformation a00_a04;
    GermanyAgeGroupsEndpointDataInformation a05_a14;
    GermanyAgeGroupsEndpointDataInformation a15_a34;
    GermanyAgeGroupsEndpointDataInformation a35_a59;
    GermanyAgeGroupsEndpointDataInformation a60_a79;
    GermanyAgeGroupsEndpointDataInformation a80_over;
    MetaData meta;
    friend QDataStream &operator<<(QDataStream &out, const GermanyAgeGroupsEndpointData &data);
    friend QDataStream &operator>>(QDataStream &in, GermanyAgeGroupsEndpointData &data);
};

QDataStream &operator<<(QDataStream &out, const GermanyAgeGroupsEndpointData &data);
QDataStream &operator>>(QDataStream &in, GermanyAgeGroupsEndpointData &data);

#endif // GERMANYAGEGROUPSENDPOINTDATA_H
