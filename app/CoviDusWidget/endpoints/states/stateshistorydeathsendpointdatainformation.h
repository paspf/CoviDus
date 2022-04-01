#ifndef STATESHISTORYDEATHSENDPOINTDATAINFORMATION_H
#define STATESHISTORYDEATHSENDPOINTDATAINFORMATION_H

#include<QString>
#include"../historydata.h"

class StatesHistoryDeathsEndpointDataInformation
{
public:
    StatesHistoryDeathsEndpointDataInformation(QString &id, QString &state, QVector<HistoryData> &data);
    StatesHistoryDeathsEndpointDataInformation();
    QString id;
    QString state;
    QString name;
    QList<HistoryData> data;
    friend QDataStream &operator<<(QDataStream &out, const StatesHistoryDeathsEndpointDataInformation &data);
    friend QDataStream &operator>>(QDataStream &in, StatesHistoryDeathsEndpointDataInformation &data);
};

QDataStream &operator<<(QDataStream &out, const StatesHistoryDeathsEndpointDataInformation &data);
QDataStream &operator>>(QDataStream &in, StatesHistoryDeathsEndpointDataInformation &data);

#endif // STATESHISTORYDEATHSENDPOINTDATAINFORMATION_H
