#ifndef DISTRITCSHISTORYRECOVEREDENDPOINTDATAINFORMATION_H
#define DISTRITCSHISTORYRECOVEREDENDPOINTDATAINFORMATION_H

#include <QtNetwork>
#include "../historydata.h"

class DistrictsHistoryRecoveredEndpointDataInformation
{
public:
    explicit DistrictsHistoryRecoveredEndpointDataInformation(QJsonObject info);
    DistrictsHistoryRecoveredEndpointDataInformation();
    QString ags; //e.g. "09780"
    QString name; //e.g. "Oberallgäu"
    QList<HistoryData> history;
    friend QDataStream &operator<<(QDataStream &out, const DistrictsHistoryRecoveredEndpointDataInformation &data);
    friend QDataStream &operator>>(QDataStream &in, DistrictsHistoryRecoveredEndpointDataInformation &data);
};

QDataStream &operator<<(QDataStream &out, const DistrictsHistoryRecoveredEndpointDataInformation &data);
QDataStream &operator>>(QDataStream &in, DistrictsHistoryRecoveredEndpointDataInformation &data);

#endif // DISTRITCSHISTORYRECOVEREDENDPOINTDATAINFORMATION_H
