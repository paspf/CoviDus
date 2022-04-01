#ifndef DISTRICTSHISTORYCASESENDPOINTDATAINFORMATION_H
#define DISTRICTSHISTORYCASESENDPOINTDATAINFORMATION_H

#include <QtNetwork>
#include "../historydata.h"

class DistrictsHistoryCasesEndpointDataInformation
{
public:
    explicit DistrictsHistoryCasesEndpointDataInformation(QJsonObject info);
    DistrictsHistoryCasesEndpointDataInformation();
    QString ags; //e.g. "09780"
    QString name; //e.g. "Oberallgäu"
    QList<HistoryData> history;
    friend QDataStream &operator<<(QDataStream &out, const DistrictsHistoryCasesEndpointDataInformation &data);
    friend QDataStream &operator>>(QDataStream &in, DistrictsHistoryCasesEndpointDataInformation &data);
};

QDataStream &operator<<(QDataStream &out, const DistrictsHistoryCasesEndpointDataInformation &data);
QDataStream &operator>>(QDataStream &in, DistrictsHistoryCasesEndpointDataInformation &data);

#endif // DISTRICTSHISTORYCASESENDPOINTDATAINFORMATION_H
