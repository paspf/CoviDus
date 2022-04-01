#include "statesagegroupsendpointdata.h"

StatesAgeGroupsEndpointData::StatesAgeGroupsEndpointData(QJsonDocument json):
    data(),
    meta(json["meta"].toObject())
{
    QJsonObject infos = json["data"].toObject();
    for (QString &key : infos.keys())
    {
        QJsonObject elem = infos.value(key).toObject();
        data.insert(
            key,
            StatesAgeGroupsEndpointDataInformation(elem)
        );
    }
}

StatesAgeGroupsEndpointData::StatesAgeGroupsEndpointData() :
    data(),
    meta()
{

}

QDataStream &operator<<(QDataStream &out, const StatesAgeGroupsEndpointData &data)
{
    out << data.data
        << data.meta;
    return out;
}

QDataStream &operator>>(QDataStream &in, StatesAgeGroupsEndpointData &data)
{
    data = StatesAgeGroupsEndpointData();
    in >> data.data
       >> data.meta;
    return in;
}
