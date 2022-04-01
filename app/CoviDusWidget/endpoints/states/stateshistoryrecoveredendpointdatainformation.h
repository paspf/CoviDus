#ifndef STATESHISTORYRECOVEREDENDPOINTDATAINFORMATION_H
#define STATESHISTORYRECOVEREDENDPOINTDATAINFORMATION_H

#include<QString>
#include"../historydata.h"

class StatesHistoryRecoveredEndpointDataInformation
{
public:
    StatesHistoryRecoveredEndpointDataInformation(QString &id, QString &state, QVector<HistoryData> &data);
    StatesHistoryRecoveredEndpointDataInformation();
    QString id;
    QString state;
    QString name;
    QList<HistoryData> data;
    friend QDataStream &operator<<(QDataStream &out, const StatesHistoryRecoveredEndpointDataInformation &data);
    friend QDataStream &operator>>(QDataStream &in, StatesHistoryRecoveredEndpointDataInformation &data);
};

QDataStream &operator<<(QDataStream &out, const StatesHistoryRecoveredEndpointDataInformation &data);
QDataStream &operator>>(QDataStream &in, StatesHistoryRecoveredEndpointDataInformation &data);

#endif // STATESHISTORYRECOVEREDENDPOINTDATAINFORMATION_H
