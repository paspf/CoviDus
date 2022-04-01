#include "agegroupdata.h"

AgeGroupData::AgeGroupData(QJsonObject data):
    casesMale(data["casesMale"].toInt()),
    casesFemale(data["casesFemale"].toInt()),
    deathsMale(data["deathsMale"].toInt()),
    deathsFemale(data["deathsFemale"].toInt()),
    casesMalePer100k(data["casesMalePer100k"].toDouble()),
    casesFemalePer100k(data["casesFemalePer100k"].toDouble()),
    deathsMalePer100k(data["deathsMalePer100k"].toDouble()),
    deathsFemalePer100k(data["deathsFemalePer100k"].toDouble())
{

}

AgeGroupData::AgeGroupData() :
    casesMale(),
    casesFemale(),
    deathsMale(),
    deathsFemale(),
    casesMalePer100k(),
    casesFemalePer100k(),
    deathsMalePer100k(),
    deathsFemalePer100k()
{

}

QDataStream &operator<<(QDataStream &out, const AgeGroupData &data)
{
    out << data.casesMale
        << data.casesFemale
        << data.deathsMale
        << data.deathsFemale
        << data.casesMalePer100k
        << data.casesFemalePer100k
        << data.deathsMalePer100k
        << data.deathsFemalePer100k;
    return out;
}

QDataStream &operator>>(QDataStream &in, AgeGroupData &data)
{
    data = AgeGroupData();
    in >> data.casesMale
        >> data.casesFemale
        >> data.deathsMale
        >> data.deathsFemale
        >> data.casesMalePer100k
        >> data.casesFemalePer100k
        >> data.deathsMalePer100k
        >> data.deathsFemalePer100k;
    return in;
}
