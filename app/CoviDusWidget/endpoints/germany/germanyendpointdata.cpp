#include "germanyendpointdata.h"

GermanyEndpointData::GermanyEndpointData(QJsonDocument json):
    cases(json["cases"].toInt()),
    deaths(json["deaths"].toInt()),
    recovered(json["recovered"].toInt()),
    weekIncidence(json["weekIncidence"].toDouble()),
    casesPer100k(json["casesPer100k"].toDouble()),
    casesPerWeek(json["casesPerWeek"].toDouble()),
    delta(
        json["delta"]["cases"].toInt(),
        json["delta"]["deaths"].toInt(),
        json["delta"]["recovered"].toInt()
    ),
    r(
        json["r"]["value"].toDouble(),
        json["r"]["date"].toString()
    ),
    meta(json["meta"].toObject())
{

}

GermanyEndpointData::GermanyEndpointData() :
    cases(0),
    deaths(0),
    recovered(0),
    weekIncidence(0),
    casesPer100k(0),
    casesPerWeek(0),
    delta(),
    r(),
    meta()
{

}

QDataStream &operator<<(QDataStream &out, const GermanyEndpointData &germanyEndpointData)
{
    out << germanyEndpointData.cases
        << germanyEndpointData.deaths
        << germanyEndpointData.recovered
        << germanyEndpointData.weekIncidence
        << germanyEndpointData.casesPer100k
        << germanyEndpointData.casesPerWeek
        << germanyEndpointData.delta
        << germanyEndpointData.r
        << germanyEndpointData.meta;
    return out;
}

QDataStream &operator>>(QDataStream &in, GermanyEndpointData &germanyEndpointData)
{
    germanyEndpointData = GermanyEndpointData();
    in >> germanyEndpointData.cases
       >> germanyEndpointData.deaths
       >> germanyEndpointData.recovered
       >> germanyEndpointData.weekIncidence
       >> germanyEndpointData.casesPer100k
       >> germanyEndpointData.casesPerWeek
       >> germanyEndpointData.delta
       >> germanyEndpointData.r
       >> germanyEndpointData.meta;
    return in;
}
