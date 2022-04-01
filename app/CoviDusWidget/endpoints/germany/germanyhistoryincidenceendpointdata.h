#ifndef GERMANYHISTORYINCIDENCEENDPOINTDATA_H
#define GERMANYHISTORYINCIDENCEENDPOINTDATA_H

#include "../metadata.h"
#include "../historydata.h"
#include <QtNetwork>

class GermanyHistoryIncidenceEndpointData
{
public:
    explicit GermanyHistoryIncidenceEndpointData(QJsonDocument json);
    GermanyHistoryIncidenceEndpointData();
    QVector<HistoryData> data;
    MetaData meta;

    friend QDataStream &operator<<(QDataStream &out, const GermanyHistoryIncidenceEndpointData &germanyEndpointData);
    friend QDataStream &operator>>(QDataStream &in, GermanyHistoryIncidenceEndpointData &germanyEndpointData);
};

QDataStream &operator<<(QDataStream &out, const GermanyHistoryIncidenceEndpointData &germanyEndpointData);
QDataStream &operator>>(QDataStream &in, GermanyHistoryIncidenceEndpointData &germanyEndpointData);

#endif // GERMANYHISTORYINCIDENCEENDPOINTDATA_H
