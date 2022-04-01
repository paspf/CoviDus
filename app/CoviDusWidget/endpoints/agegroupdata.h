#ifndef AGEGROUPDATA_H
#define AGEGROUPDATA_H

#include<QJsonObject>

class AgeGroupData
{
public:
    explicit AgeGroupData(QJsonObject data);
    AgeGroupData();
    int casesMale;
    int casesFemale;
    int deathsMale;
    int deathsFemale;
    double casesMalePer100k;
    double casesFemalePer100k;
    double deathsMalePer100k;
    double deathsFemalePer100k;
    friend QDataStream &operator<<(QDataStream &out, const AgeGroupData &data);
    friend QDataStream &operator>>(QDataStream &in, AgeGroupData &data);
};

QDataStream &operator<<(QDataStream &out, const AgeGroupData &data);
QDataStream &operator>>(QDataStream &in, AgeGroupData &data);

#endif // AGEGROUPDATA_H
