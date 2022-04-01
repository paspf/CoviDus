#include "germanyhistoryrecoveredendpointdata.h"

GermanyHistoryRecoveredEndpointData::GermanyHistoryRecoveredEndpointData(QJsonDocument json):
    data(),
    meta(json["meta"].toObject())
{
    QJsonArray infos = json["data"].toArray();
    for (const auto &info : infos)
    {
        QJsonObject elem = info.toObject();
        QString date = elem["date"].toString();
        HistoryData hdat = HistoryData(elem["recovered"].toDouble(), date);
        data.push_back(hdat);
    }
}

GermanyHistoryRecoveredEndpointData::GermanyHistoryRecoveredEndpointData() :
    data(),
    meta()
{

}

QDataStream &operator<<(QDataStream &out, const GermanyHistoryRecoveredEndpointData &data)
{
    out << data.data
        << data.meta;
    return out;
}

QDataStream &operator>>(QDataStream &in, GermanyHistoryRecoveredEndpointData &data)
{
    data = GermanyHistoryRecoveredEndpointData();
    in >> data.data
       >> data.meta;
    return in;
}
