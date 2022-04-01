#ifndef GERMANYENDPOINTDATA_H
#define GERMANYENDPOINTDATA_H

#include "../metadata.h"
#include "../deltadata.h"
#include "../rdata.h"
#include <QtNetwork>


class GermanyEndpointData
{
public:
    explicit GermanyEndpointData(QJsonDocument json);
    GermanyEndpointData();
    int cases;
    int deaths;
    int recovered;
    double weekIncidence;
    double casesPer100k;
    int casesPerWeek;
    DeltaData delta;
    RData r;
    MetaData meta;

    friend QDataStream &operator<<(QDataStream &out, const GermanyEndpointData &germanyEndpointData);
    friend QDataStream &operator>>(QDataStream &in, GermanyEndpointData &germanyEndpointData);
};

QDataStream &operator<<(QDataStream &out, const GermanyEndpointData &germanyEndpointData);
QDataStream &operator>>(QDataStream &in, GermanyEndpointData &germanyEndpointData);

#endif // GERMANYENDPOINTDATA_H
