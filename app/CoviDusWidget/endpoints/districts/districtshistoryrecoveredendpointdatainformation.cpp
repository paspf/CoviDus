#include "districtshistoryrecoveredendpointdatainformation.h"

DistrictsHistoryRecoveredEndpointDataInformation::DistrictsHistoryRecoveredEndpointDataInformation(QJsonObject info):
    ags(info["ags"].toString()),
    name(info["name"].toString()),
    history()
{
    QJsonArray hist = info["history"].toArray();
    for(auto recoveredData: hist){
        QJsonObject elem = recoveredData.toObject();
        QString date = elem["date"].toString();
        HistoryData hdat = HistoryData(elem["recovered"].toDouble(), date);
        history.push_back(hdat);
    }
}

DistrictsHistoryRecoveredEndpointDataInformation::DistrictsHistoryRecoveredEndpointDataInformation() :
    ags(),
    name(),
    history()
{

}

QDataStream &operator<<(QDataStream &out, const DistrictsHistoryRecoveredEndpointDataInformation &data)
{
    out << data.ags
        << data.name
        << data.history;
    return out;
}

QDataStream &operator>>(QDataStream &in, DistrictsHistoryRecoveredEndpointDataInformation &data)
{
    data = DistrictsHistoryRecoveredEndpointDataInformation();
    in >> data.ags
       >> data.name
       >> data.history;
    return in;
}
