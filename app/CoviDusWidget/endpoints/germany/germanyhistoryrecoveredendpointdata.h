#ifndef GERMANYHISTORYRECOVEREDENDPOINTDATA_H
#define GERMANYHISTORYRECOVEREDENDPOINTDATA_H

#include "../metadata.h"
#include "../historydata.h"
#include <QtNetwork>

class GermanyHistoryRecoveredEndpointData
{
public:
    explicit GermanyHistoryRecoveredEndpointData(QJsonDocument json);
    GermanyHistoryRecoveredEndpointData();
    QVector<HistoryData> data;
    MetaData meta;
    friend QDataStream &operator<<(QDataStream &out, const GermanyHistoryRecoveredEndpointData &germanyEndpointData);
    friend QDataStream &operator>>(QDataStream &in, GermanyHistoryRecoveredEndpointData &germanyEndpointData);
};

QDataStream &operator<<(QDataStream &out, const GermanyHistoryRecoveredEndpointData &germanyEndpointData);
QDataStream &operator>>(QDataStream &in, GermanyHistoryRecoveredEndpointData &germanyEndpointData);

#endif // GERMANYHISTORYRECOVEREDENDPOINTDATA_H
