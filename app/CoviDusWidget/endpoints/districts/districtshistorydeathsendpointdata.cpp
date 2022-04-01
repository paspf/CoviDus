#include "districtshistorydeathsendpointdata.h"

DistrictsHistoryDeathsEndpointData::DistrictsHistoryDeathsEndpointData(QJsonDocument json):
        data(),
        meta(json["meta"].toObject())
    {
        QJsonObject infos = json["data"].toObject();
        for (QString key : infos.keys())
        {
            QJsonObject elem = infos.value(key).toObject();
            data.insert(
                elem["ags"].toString(),
                DistrictsHistoryDeathsEndpointDataInformation(elem)
            );
        }
}

DistrictsHistoryDeathsEndpointData::DistrictsHistoryDeathsEndpointData() :
    data(),
    meta()
{

}

QDataStream &operator<<(QDataStream &out, const DistrictsHistoryDeathsEndpointData &data)
{
    out << data.data
        << data.meta;
    return out;
}

QDataStream &operator>>(QDataStream &in, DistrictsHistoryDeathsEndpointData &data)
{
    data = DistrictsHistoryDeathsEndpointData();
    in >> data.data
       >> data.meta;
    return in;
}
