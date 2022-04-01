#ifndef GERMANYHISTORYDEATHSENDPOINTDATA_H
#define GERMANYHISTORYDEATHSENDPOINTDATA_H

#include "../metadata.h"
#include "../historydata.h"
#include <QtNetwork>

class GermanyHistoryDeathsEndpointData
{
public:
    explicit GermanyHistoryDeathsEndpointData(QJsonDocument json);
    GermanyHistoryDeathsEndpointData();
    QList<HistoryData> data;
    MetaData meta;
    friend QDataStream &operator<<(QDataStream &out, const GermanyHistoryDeathsEndpointData &data);
    friend QDataStream &operator>>(QDataStream &in, GermanyHistoryDeathsEndpointData &data);
};

QDataStream &operator<<(QDataStream &out, const GermanyHistoryDeathsEndpointData &data);
QDataStream &operator>>(QDataStream &in, GermanyHistoryDeathsEndpointData &data);

#endif // GERMANYHISTORYDEATHSENDPOINTDATA_H
