#include "statesendpointdata.h"

#include "../deltadata.h"

StatesEndpointData::StatesEndpointData(QJsonDocument json):
    data(),
    meta(json["meta"].toObject())
{
    QJsonObject infos = json["data"].toObject();
    for (QString &key : infos.keys())
    {
        QJsonObject elem = infos.value(key).toObject();
        QString id = elem["id"].toString();
        QString name = elem["name"].toString();
        QString abbreviation = elem["abbreviation"].toString();

        data.insert(
            elem["name"].toString(),
            StatesEndpointDataInformation(
                id,
                name,
                elem["population"].toInt(),
                elem["cases"].toInt(),
                elem["deaths"].toInt(),
                elem["casesPerWeek"].toDouble(),
                elem["deathsPerWeek"].toDouble(),
                abbreviation,
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

StatesEndpointData::StatesEndpointData() :
    data(),
    meta()
{

}

QDataStream &operator<<(QDataStream &out, const StatesEndpointData &data)
{
    out << data.data
        << data.meta;
    return out;
}

QDataStream &operator>>(QDataStream &in, StatesEndpointData &data)
{
    data = StatesEndpointData();
    in >> data.data
       >> data.meta;
    return in;
}
