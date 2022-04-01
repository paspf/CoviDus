#include "germanyhistorydeathsendpointdata.h"

GermanyHistoryDeathsEndpointData::GermanyHistoryDeathsEndpointData(QJsonDocument json):
    data(),
    meta(json["meta"].toObject())
{
    QJsonArray infos = json["data"].toArray();
    for (const auto &info : infos)
    {
        QJsonObject elem = info.toObject();
        QString date = elem["date"].toString();
        HistoryData hdat = HistoryData(elem["deaths"].toDouble(), date);
        data.push_back(hdat);
    }
}

GermanyHistoryDeathsEndpointData::GermanyHistoryDeathsEndpointData() :
    data(),
    meta()
{

}

QDataStream &operator<<(QDataStream &out, const GermanyHistoryDeathsEndpointData &data)
{
    out << data.data
        << data.meta;
    return out;
}

QDataStream &operator>>(QDataStream &in, GermanyHistoryDeathsEndpointData &data)
{
    data = GermanyHistoryDeathsEndpointData();
    in >> data.data
       >> data.meta;
    return in;
}
