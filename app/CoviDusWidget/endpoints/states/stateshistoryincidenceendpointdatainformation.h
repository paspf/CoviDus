#ifndef STATESHISTORYINCIDENCEENDPOINTDATAINFORMATION_H
#define STATESHISTORYINCIDENCEENDPOINTDATAINFORMATION_H

#include<QString>
#include"../historydata.h"

class StatesHistoryIncidenceEndpointDataInformation
{
public:
    StatesHistoryIncidenceEndpointDataInformation(QString &id, QString &state, QVector<HistoryData> &data);
    StatesHistoryIncidenceEndpointDataInformation();
    QString id;
    QString state;
    QString name;
    QList<HistoryData> data;
    friend QDataStream &operator<<(QDataStream &out, const StatesHistoryIncidenceEndpointDataInformation &data);
    friend QDataStream &operator>>(QDataStream &in, StatesHistoryIncidenceEndpointDataInformation &data);
};

QDataStream &operator<<(QDataStream &out, const StatesHistoryIncidenceEndpointDataInformation &data);
QDataStream &operator>>(QDataStream &in, StatesHistoryIncidenceEndpointDataInformation &data);

#endif // STATESHISTORYINCIDENCEENDPOINTDATAINFORMATION_H
