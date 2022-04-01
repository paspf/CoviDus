#include "districtshistoryincidenceendpointdatainformation.h"

DistrictsHistoryIncidenceEndpointDataInformation::DistrictsHistoryIncidenceEndpointDataInformation(QJsonObject info):
    ags(info["ags"].toString()),
    name(info["name"].toString()),
    history()
{
    QJsonArray hist = info["history"].toArray();
    for(auto weekIncidenceData: hist){
        QJsonObject elem = weekIncidenceData.toObject();
        QString date = elem["date"].toString();
        HistoryData hdat = HistoryData(elem["weekIncidence"].toDouble(), date);
        history.push_back(hdat);
    }
}

DistrictsHistoryIncidenceEndpointDataInformation::DistrictsHistoryIncidenceEndpointDataInformation() :
    ags(),
    name(),
    history()
{

}

QDataStream &operator<<(QDataStream &out, const DistrictsHistoryIncidenceEndpointDataInformation &data)
{
    out << data.ags
        << data.name
        << data.history;
    return out;
}

QDataStream &operator>>(QDataStream &in, DistrictsHistoryIncidenceEndpointDataInformation &data)
{
    data = DistrictsHistoryIncidenceEndpointDataInformation();
    in >> data.ags
       >> data.name
       >> data.history;
    return in;
}
