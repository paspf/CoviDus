#include "districtshistorydeathsendpointdatainformation.h"

DistrictsHistoryDeathsEndpointDataInformation::DistrictsHistoryDeathsEndpointDataInformation(QJsonObject info):
    ags(info["ags"].toString()),
    name(info["name"].toString()),
    history()
{
    QJsonArray hist = info["history"].toArray();
    for(auto deathsData: hist){
        QJsonObject elem = deathsData.toObject();
        QString date = elem["date"].toString();
        HistoryData hdat = HistoryData(elem["deaths"].toDouble(), date);
        history.push_back(hdat);
    }
}

DistrictsHistoryDeathsEndpointDataInformation::DistrictsHistoryDeathsEndpointDataInformation() :
    ags(),
    name(),
    history()
{

}

QDataStream &operator<<(QDataStream &out, const DistrictsHistoryDeathsEndpointDataInformation &data)
{
    out << data.ags
        << data.name
        << data.history;
    return out;
}

QDataStream &operator>>(QDataStream &in, DistrictsHistoryDeathsEndpointDataInformation &data)
{
    data = DistrictsHistoryDeathsEndpointDataInformation();
    in >> data.ags
       >> data.name
       >> data.history;
    return in;
}
