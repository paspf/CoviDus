#include "districtshistoryincidenceendpointdata.h"

DistrictsHistoryIncidenceEndpointData::DistrictsHistoryIncidenceEndpointData(QJsonDocument json):
        data(),
        meta(json["meta"].toObject())
{
    QJsonObject infos = json["data"].toObject();
    for (QString key : infos.keys())
    {
        QJsonObject elem = infos.value(key).toObject();
        data.insert(
            elem["ags"].toString(),
            DistrictsHistoryIncidenceEndpointDataInformation(elem)
        );
    }
}

DistrictsHistoryIncidenceEndpointData::DistrictsHistoryIncidenceEndpointData() :
    data(),
    meta()
{

}

QDataStream &operator<<(QDataStream &out, const DistrictsHistoryIncidenceEndpointData &data)
{
    out << data.data
        << data.meta;
    return out;
}

QDataStream &operator>>(QDataStream &in, DistrictsHistoryIncidenceEndpointData &data)
{
    data = DistrictsHistoryIncidenceEndpointData();
    in >> data.data
       >> data.meta;
    return in;
}
