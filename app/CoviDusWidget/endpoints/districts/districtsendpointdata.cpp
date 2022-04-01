#include "districtsendpointdata.h"

DistrictsEndpointData::DistrictsEndpointData(QJsonDocument json):
        data(),
        meta(json["meta"].toObject())
    {
        QJsonObject infos = json["data"].toObject();
        for (auto key : infos.keys())
        {
            QJsonObject elem = infos.value(key).toObject();
            data.insert(
                elem["ags"].toString(),
                DistrictsEndpointDataInformation(
                    elem["ags"].toString(),
                    elem["name"].toString(),
                    elem["county"].toString(),
                    elem["state"].toString(),
                    elem["population"].toInt(),
                    elem["cases"].toInt(),
                    elem["deaths"].toInt(),
                    elem["casesPerWeek"].toInt(),
                    elem["deathsPerWeek"].toInt(),
                    elem["stateAbbreviation"].toString(),
                    elem["recovered"].toInt(),
                    elem["weekIncidence"].toDouble(),
                    elem["casesPer100k"].toDouble(),
                    DeltaData(
                        elem["delta"].toObject()["cases"].toInt(),
                        elem["delta"].toObject()["deaths"].toInt(),
                        elem["delta"].toObject()["recovered"].toInt()
                    )
                )
            );
        }
}

DistrictsEndpointData::DistrictsEndpointData() :
    data(),
    meta()
{

}

QDataStream &operator<<(QDataStream &out, const DistrictsEndpointData &data)
{
    out << data.data
        << data.meta;
    return out;
}

QDataStream &operator>>(QDataStream &in, DistrictsEndpointData &data)
{
    data = DistrictsEndpointData();
    in >> data.data
       >> data.meta;
    return in;
}
