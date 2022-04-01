#include "districtshistorycasesendpointdatainformation.h"

DistrictsHistoryCasesEndpointDataInformation::DistrictsHistoryCasesEndpointDataInformation(QJsonObject info):
    ags(info["ags"].toString()),
    name(info["name"].toString()),
    history()
{
    QJsonArray hist = info["history"].toArray();
    for (auto casesData: hist) {
        QJsonObject elem = casesData.toObject();
        QString date = elem["date"].toString();
        HistoryData hdat = HistoryData(elem["cases"].toDouble(), date);
        history.push_back(hdat);
    }
}

DistrictsHistoryCasesEndpointDataInformation::DistrictsHistoryCasesEndpointDataInformation() :
    ags(),
    name(),
    history()
{

}

QDataStream &operator<<(QDataStream &out, const DistrictsHistoryCasesEndpointDataInformation &data)
{
    out << data.ags
        << data.name
        << data.history;
    return out;
}

QDataStream &operator>>(QDataStream &in, DistrictsHistoryCasesEndpointDataInformation &data)
{
    data = DistrictsHistoryCasesEndpointDataInformation();
    in >> data.ags
       >> data.name
       >> data.history;
    return in;
}
