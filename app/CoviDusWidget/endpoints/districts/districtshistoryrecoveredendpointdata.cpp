#include "districtshistoryrecoveredendpointdata.h"

DistrictsHistoryRecoveredEndpointData::DistrictsHistoryRecoveredEndpointData(QJsonDocument json):
        data(),
        meta(json["meta"].toObject())
{
    QJsonObject infos = json["data"].toObject();
    for (QString key : infos.keys())
    {
        QJsonObject elem = infos.value(key).toObject();
        data.insert(
            elem["ags"].toString(),
            DistrictsHistoryRecoveredEndpointDataInformation(elem)
        );
    }
}

DistrictsHistoryRecoveredEndpointData::DistrictsHistoryRecoveredEndpointData() :
    data(),
    meta()
{

}

QDataStream &operator<<(QDataStream &out, const DistrictsHistoryRecoveredEndpointData &data)
{
    out << data.data
        << data.meta;
    return out;
}

QDataStream &operator>>(QDataStream &in, DistrictsHistoryRecoveredEndpointData &data)
{
    data = DistrictsHistoryRecoveredEndpointData();
    in >> data.data
       >> data.meta;
    return in;
}
