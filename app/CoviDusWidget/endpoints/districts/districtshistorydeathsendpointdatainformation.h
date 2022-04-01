#ifndef DISTRITCSHISTORYDEATHSENDPOINTDATAINFORMATION_H
#define DISTRITCSHISTORYDEATHSENDPOINTDATAINFORMATION_H

#include <QtNetwork>
#include "../historydata.h"

class DistrictsHistoryDeathsEndpointDataInformation
{
public:
    explicit DistrictsHistoryDeathsEndpointDataInformation(QJsonObject info);
    DistrictsHistoryDeathsEndpointDataInformation();
    QString ags; //e.g. "09780"
    QString name; //e.g. "Oberallgäu"
    QList<HistoryData> history;
    friend QDataStream &operator<<(QDataStream &out, const DistrictsHistoryDeathsEndpointDataInformation &data);
    friend QDataStream &operator>>(QDataStream &in, DistrictsHistoryDeathsEndpointDataInformation &data);
};

QDataStream &operator<<(QDataStream &out, const DistrictsHistoryDeathsEndpointDataInformation &data);
QDataStream &operator>>(QDataStream &in, DistrictsHistoryDeathsEndpointDataInformation &data);

#endif // DISTRITCSHISTORYDEATHSENDPOINTDATAINFORMATION_H
