#ifndef GERMANYHISTORYCASESENDPOINTDATA_H
#define GERMANYHISTORYCASESENDPOINTDATA_H

#include "../metadata.h"
#include "../historydata.h"
#include <QtNetwork>

class GermanyHistoryCasesEndpointData
{
public:
    explicit GermanyHistoryCasesEndpointData(QJsonDocument json);
    GermanyHistoryCasesEndpointData();
    QList<HistoryData> data;
    MetaData meta;
    friend QDataStream &operator<<(QDataStream &out, const GermanyHistoryCasesEndpointData &data);
    friend QDataStream &operator>>(QDataStream &in, GermanyHistoryCasesEndpointData &data);
};

QDataStream &operator<<(QDataStream &out, const GermanyHistoryCasesEndpointData &data);
QDataStream &operator>>(QDataStream &in, GermanyHistoryCasesEndpointData &data);

#endif // GERMANYHISTORYCASESENDPOINTDATA_H
