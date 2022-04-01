#ifndef VACCINATIONSHISTORYENDPOINTDATA_H
#define VACCINATIONSHISTORYENDPOINTDATA_H

#include<QJsonDocument>
#include"../vaccinationhistorydata.h"
#include"../metadata.h"

class VaccinationsHistoryEndpointData
{
public:
    explicit VaccinationsHistoryEndpointData(QJsonDocument json);
    VaccinationsHistoryEndpointData();
    QVector<VaccinationHistoryData> history;
    MetaData meta;
    friend QDataStream &operator<<(QDataStream &out, const VaccinationsHistoryEndpointData &data);
    friend QDataStream &operator>>(QDataStream &in, VaccinationsHistoryEndpointData &data);
};

QDataStream &operator<<(QDataStream &out, const VaccinationsHistoryEndpointData &data);
QDataStream &operator>>(QDataStream &in, VaccinationsHistoryEndpointData &data);

#endif // VACCINATIONSHISTORYENDPOINTDATA_H
