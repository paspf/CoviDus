#include "germanyagegroupsendpointdatainformation.h"

GermanyAgeGroupsEndpointDataInformation::GermanyAgeGroupsEndpointDataInformation(QJsonObject info):
    casesMale(info["casesMale"].toInt()),
    casesFemale(info["casesFemale"].toInt()),
    deathsMale(info["deathsMale"].toInt()),
    deathsFemale(info["deathsFemale"].toInt()),
    casesMalePer100k(info["casesMalePer100k"].toDouble()),
    casesFemalePer100k(info["casesFemalePer100k"].toDouble()),
    deathsMalePer100k(info["deathsMalePer100k"].toDouble()),
    deathsFemalePer100k(info["deathsFemalePer100k"].toDouble())
{

}

GermanyAgeGroupsEndpointDataInformation::GermanyAgeGroupsEndpointDataInformation() :
    casesMale(0),
    casesFemale(0),
    deathsMale(0),
    deathsFemale(0),
    casesMalePer100k(0),
    casesFemalePer100k(0),
    deathsMalePer100k(0),
    deathsFemalePer100k(0)
{

}

QDataStream &operator<<(QDataStream &out, const GermanyAgeGroupsEndpointDataInformation &data)
{
    out << data.casesMale << data.casesFemale
        << data.deathsMale << data.deathsFemale
        << data.casesMalePer100k << data.casesFemalePer100k
        << data.deathsMalePer100k << data.deathsFemalePer100k;
    return out;
}

QDataStream &operator>>(QDataStream &in, GermanyAgeGroupsEndpointDataInformation &data)
{
    data = GermanyAgeGroupsEndpointDataInformation();
    in >> data.casesMale >> data.casesFemale
        >> data.deathsMale >> data.deathsFemale
        >> data.casesMalePer100k >> data.casesFemalePer100k
        >> data.deathsMalePer100k >> data.deathsFemalePer100k;
    return in;
}
