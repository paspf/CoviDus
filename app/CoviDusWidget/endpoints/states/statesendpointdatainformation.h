#ifndef STATESENDPOINTDATAINFORMATION_H
#define STATESENDPOINTDATAINFORMATION_H

#include <QString>
#include "../deltadata.h"

class StatesEndpointDataInformation
{
public:
    StatesEndpointDataInformation(
            QString &id,
            QString &state,
            int population,
            int cases,
            int deaths,
            double casesPerWeek,
            double deathsPerWeek,
            QString &stateAbbreviation,
            int recovered,
            double weekIncidence,
            double casesPer100k,
            DeltaData delta
        );
    StatesEndpointDataInformation();
    QString id; //e.g. "1"
    QString name; //e.g. "Saarland"
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
    friend QDataStream &operator<<(QDataStream &out, const StatesEndpointDataInformation &data);
    friend QDataStream &operator>>(QDataStream &in, StatesEndpointDataInformation &data);
};

QDataStream &operator<<(QDataStream &out, const StatesEndpointDataInformation &data);
QDataStream &operator>>(QDataStream &in, StatesEndpointDataInformation &data);

#endif // STATESENDPOINTDATAINFORMATION_H
