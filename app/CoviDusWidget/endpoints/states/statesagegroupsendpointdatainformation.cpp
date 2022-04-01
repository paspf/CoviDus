
#include "statesagegroupsendpointdatainformation.h"

StatesAgeGroupsEndpointDataInformation::StatesAgeGroupsEndpointDataInformation(QJsonObject info):
    a00_a04(info["A00_A04"].toObject()),
    a05_a14(info["A05_A14"].toObject()),
    a15_a34(info["A15_A34"].toObject()),
    a35_a59(info["A35_A59"].toObject()),
    a60_a79(info["A60_A79"].toObject()),
    a80_over(info["A80+"].toObject())
{

}

StatesAgeGroupsEndpointDataInformation::StatesAgeGroupsEndpointDataInformation() :
    a00_a04(),
    a05_a14(),
    a15_a34(),
    a35_a59(),
    a60_a79(),
    a80_over()
{

}

QDataStream &operator<<(QDataStream &out, const StatesAgeGroupsEndpointDataInformation &data)
{
    out << data.a00_a04
        << data.a05_a14
        << data.a15_a34
        << data.a35_a59
        << data.a60_a79
        << data.a80_over;
    return out;
}

QDataStream &operator>>(QDataStream &in, StatesAgeGroupsEndpointDataInformation &data)
{
    data = StatesAgeGroupsEndpointDataInformation();
    in >> data.a00_a04
       >> data.a05_a14
       >> data.a15_a34
       >> data.a35_a59
       >> data.a60_a79
       >> data.a80_over;
    return in;
}
