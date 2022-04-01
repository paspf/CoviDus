#ifndef GERMANYAGEGROUPSENDPOINTDATAINFORMATION_H
#define GERMANYAGEGROUPSENDPOINTDATAINFORMATION_H

#include <QtNetwork>

class GermanyAgeGroupsEndpointDataInformation
{
public:
    explicit GermanyAgeGroupsEndpointDataInformation(QJsonObject info);
    GermanyAgeGroupsEndpointDataInformation();
    int casesMale;
    int casesFemale;
    int deathsMale;
    int deathsFemale;
    double casesMalePer100k;
    double casesFemalePer100k;
    double deathsMalePer100k;
    double deathsFemalePer100k;
    friend QDataStream &operator<<(QDataStream &out, const GermanyAgeGroupsEndpointDataInformation &data);
    friend QDataStream &operator>>(QDataStream &in, GermanyAgeGroupsEndpointDataInformation &data);
};

QDataStream &operator<<(QDataStream &out, const GermanyAgeGroupsEndpointDataInformation &data);
QDataStream &operator>>(QDataStream &in, GermanyAgeGroupsEndpointDataInformation &data);;

#endif // GERMANYAGEGROUPSENDPOINTDATAINFORMATION_H
