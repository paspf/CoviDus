#include "districtshistorycasesendpointdata.h"

DistrictsHistoryCasesEndpointData::DistrictsHistoryCasesEndpointData(QJsonDocument json):
        data(),
        meta(json["meta"].toObject())
    {
        QJsonObject infos = json["data"].toObject();
        for (auto key : infos.keys())
        {
            QJsonObject elem = infos.value(key).toObject();
            data.insert(
                elem["ags"].toString(),
                DistrictsHistoryCasesEndpointDataInformation(elem)
            );
        }
}

DistrictsHistoryCasesEndpointData::DistrictsHistoryCasesEndpointData() :
    data(),
    meta()
{

}

QDataStream &operator<<(QDataStream &out, const DistrictsHistoryCasesEndpointData &data)
{
    out << data.data
        << data.meta;
    return out;
}

QDataStream &operator>>(QDataStream &in, DistrictsHistoryCasesEndpointData &data)
{
    data = DistrictsHistoryCasesEndpointData();
    in >> data.data
       >> data.meta;
    return in;
}
