#include "districtshistoryfrozenincidenceendpointdatainformation.h"

DistrictsHistoryFrozenIncidenceEndpointDataInformation::DistrictsHistoryFrozenIncidenceEndpointDataInformation(QJsonObject info):
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

DistrictsHistoryFrozenIncidenceEndpointDataInformation::DistrictsHistoryFrozenIncidenceEndpointDataInformation() :
    ags(),
    name(),
    history()
{

}

QDataStream &operator<<(QDataStream &out, const DistrictsHistoryFrozenIncidenceEndpointDataInformation &data)
{
    out << data.ags
        << data.name
        << data.history;
    return out;
}

QDataStream &operator>>(QDataStream &in, DistrictsHistoryFrozenIncidenceEndpointDataInformation &data)
{
    data = DistrictsHistoryFrozenIncidenceEndpointDataInformation();
    in >> data.ags
       >> data.name
       >> data.history;
    return in;
}
