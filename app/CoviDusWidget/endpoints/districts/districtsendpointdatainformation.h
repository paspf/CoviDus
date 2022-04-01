#ifndef DISTRICTSENDPOINTDATAINFORMATION_H
#define DISTRICTSENDPOINTDATAINFORMATION_H

#include <QtNetwork>
#include "../deltadata.h"

class DistrictsEndpointDataInformation
{
public:
    DistrictsEndpointDataInformation(QString ags,
                                     QString name,
                                     QString county,
                                     QString state,
                                     int population,
                                     int cases,
                                     int deaths,
                                     int casesPerWeek,
                                     int deathsPerWeek,
                                     QString stateAbbreviation,
                                     int recovered,
                                     double weekIncidence,
                                     double casesPer100k,
                                     DeltaData delta);
    DistrictsEndpointDataInformation();
    QString ags; //e.g. "09780"
    QString name; //e.g. "Oberallgäu"
    QString county; //e.g. "LK Oberallgäu"
    QString state; //e.g. "Saarland"
    int population; // e.g. 156008
    int cases; // e.g. 2846
    int deaths; // e.g 30
    int casesPerWeek; // e.g. 96
    int deathsPerWeek; // e.g. 0
    QString stateAbbreviation; // e.g. "SL"
    int recovered; // e.g. 2007
    double weekIncidence; // e.g. 61.53530588174966
    double casesPer100k; // e.g. 1824.265422286036
    DeltaData delta;
    friend QDataStream &operator<<(QDataStream &out, const DistrictsEndpointDataInformation &data);
    friend QDataStream &operator>>(QDataStream &in, DistrictsEndpointDataInformation &data);
};

QDataStream &operator<<(QDataStream &out, const DistrictsEndpointDataInformation &data);
QDataStream &operator>>(QDataStream &in, DistrictsEndpointDataInformation &data);

#endif // DISTRICTSENDPOINTDATAINFORMATION_H
