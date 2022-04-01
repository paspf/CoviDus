#include "germanyhistorycasesendpointdata.h"

GermanyHistoryCasesEndpointData::GermanyHistoryCasesEndpointData(QJsonDocument json):
    data(),
    meta(json["meta"].toObject())
{
    QJsonArray infos = json["data"].toArray();
    for (const auto &info : infos)
    {
        QJsonObject elem = info.toObject();
        QString date = elem["date"].toString();
        HistoryData hdat = HistoryData(elem["cases"].toDouble(), date);
        data.push_back(hdat);
    }
}

GermanyHistoryCasesEndpointData::GermanyHistoryCasesEndpointData() :
    data(),
    meta()
{

}

QDataStream &operator<<(QDataStream &out, const GermanyHistoryCasesEndpointData &data)
{
    out << data.data
        << data.meta;
    return out;
}

QDataStream &operator>>(QDataStream &in, GermanyHistoryCasesEndpointData &data)
{
    data = GermanyHistoryCasesEndpointData();
    in >> data.data
       >> data.meta;
    return in;
}
