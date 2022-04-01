#ifndef STATESHISTORYENDPOINTDATAINFORMATION_H
#define STATESHISTORYENDPOINTDATAINFORMATION_H

#include<QString>
#include"../historydata.h"

class StatesHistoryCasesEndpointDataInformation
{
public:
    StatesHistoryCasesEndpointDataInformation(QString &id, QString &state, QVector<HistoryData> &data);
    StatesHistoryCasesEndpointDataInformation();
    QString id;
    QString state;
    QString name;
    QList<HistoryData> data;
    friend QDataStream &operator<<(QDataStream &out, const StatesHistoryCasesEndpointDataInformation &data);
    friend QDataStream &operator>>(QDataStream &in, StatesHistoryCasesEndpointDataInformation &data);
};

QDataStream &operator<<(QDataStream &out, const StatesHistoryCasesEndpointDataInformation &data);
QDataStream &operator>>(QDataStream &in, StatesHistoryCasesEndpointDataInformation &data);

#endif // STATESHISTORYENDPOINTDATAINFORMATION_H
