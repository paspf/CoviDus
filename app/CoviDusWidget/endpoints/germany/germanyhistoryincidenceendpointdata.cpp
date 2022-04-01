#include "germanyhistoryincidenceendpointdata.h"

GermanyHistoryIncidenceEndpointData::GermanyHistoryIncidenceEndpointData(QJsonDocument json):
    data(),
    meta(json["meta"].toObject())
{
    QJsonArray infos = json["data"].toArray();
    for (const auto &info : infos)
    {
        QJsonObject elem = info.toObject();
        QString date = elem["date"].toString();
        HistoryData hdat = HistoryData(elem["weekIncidence"].toDouble(), date);
        data.push_back(hdat);
    }
}

GermanyHistoryIncidenceEndpointData::GermanyHistoryIncidenceEndpointData() :
    data(),
    meta()
{

}


QDataStream &operator<<(QDataStream &out, const GermanyHistoryIncidenceEndpointData &germanyEndpointData)
{
    out << germanyEndpointData.data
        << germanyEndpointData.meta;
    return out;
}

QDataStream &operator>>(QDataStream &in, GermanyHistoryIncidenceEndpointData &germanyEndpointData)
{
    germanyEndpointData = GermanyHistoryIncidenceEndpointData();
    in >> germanyEndpointData.data
       >> germanyEndpointData.meta;
    return in;
}
