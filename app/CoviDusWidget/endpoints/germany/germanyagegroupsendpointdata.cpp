#include "germanyagegroupsendpointdata.h"

GermanyAgeGroupsEndpointData::GermanyAgeGroupsEndpointData(QJsonDocument json):
    a00_a04(json["data"]["A00_A04"].toObject()),
    a05_a14(json["data"]["A05_A14"].toObject()),
    a15_a34(json["data"]["A15_A34"].toObject()),
    a35_a59(json["data"]["A35_A59"].toObject()),
    a60_a79(json["data"]["A60_A79"].toObject()),
    a80_over(json["data"]["A80+"].toObject()),
    meta(json["meta"].toObject())
{

}

GermanyAgeGroupsEndpointData::GermanyAgeGroupsEndpointData() :
    a00_a04(),
    a05_a14(),
    a15_a34(),
    a35_a59(),
    a60_a79(),
    a80_over(),
    meta()
{

}

QDataStream &operator<<(QDataStream &out, const GermanyAgeGroupsEndpointData &data)
{
    out << data.a00_a04
        << data.a05_a14
        << data.a15_a34
        << data.a35_a59
        << data.a60_a79
        << data.a80_over
        << data.meta;

    return out;
}

QDataStream &operator>>(QDataStream &in, GermanyAgeGroupsEndpointData &data)
{
    data = GermanyAgeGroupsEndpointData();
    in >> data.a00_a04
       >> data.a05_a14
       >> data.a15_a34
       >> data.a35_a59
       >> data.a60_a79
       >> data.a80_over
       >> data.meta;
    return in;
}
