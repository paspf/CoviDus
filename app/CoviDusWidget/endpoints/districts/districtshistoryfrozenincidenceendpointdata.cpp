#include "districtshistoryfrozenincidenceendpointdata.h"

DistrictsHistoryFrozenIncidenceEndpointData::DistrictsHistoryFrozenIncidenceEndpointData(QJsonDocument json):
        data(),
        meta(json["meta"].toObject())
    {
        QJsonObject infos = json["data"].toObject();
        for (auto key : infos.keys())
        {
            QJsonObject elem = infos.value(key).toObject();
            data.insert(
                elem["ags"].toString(),
                DistrictsHistoryFrozenIncidenceEndpointDataInformation(elem)
            );
        }
}

DistrictsHistoryFrozenIncidenceEndpointData::DistrictsHistoryFrozenIncidenceEndpointData() :
    data(),
    meta()
{

}

QDataStream &operator<<(QDataStream &out, const DistrictsHistoryFrozenIncidenceEndpointData &data)
{
    out << data.data
        << data.meta;
    return out;
}

QDataStream &operator>>(QDataStream &in, DistrictsHistoryFrozenIncidenceEndpointData &data)
{
    data = DistrictsHistoryFrozenIncidenceEndpointData();
    in >> data.data
       >> data.meta;
    return in;
}
