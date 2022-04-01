#include "stateshistoryincidenceendpointdata.h"

StatesHistoryIncidenceEndpointData::StatesHistoryIncidenceEndpointData(QJsonDocument json):
    data(),
    meta(json["meta"].toObject())
{
    QJsonObject infos = json["data"].toObject();
    for (QString &key : infos.keys())
    {
        QJsonObject elem = infos.value(key).toObject();
        QVector<HistoryData> history;
        for (auto info : elem["history"].toArray())
        {
            QJsonObject histData = info.toObject();
            QString date = histData["date"].toString();
            HistoryData hdat = HistoryData(histData["weekIncidence"].toDouble(), date);
            history.push_back(hdat);
        }
        QString id = QString::number(elem["id"].toInt());
        QString name = elem["name"].toString();
        data.insert(
            key,
            StatesHistoryIncidenceEndpointDataInformation(
                id,
                name,
                history
            )
        );
    }
}

StatesHistoryIncidenceEndpointData::StatesHistoryIncidenceEndpointData() :
    data(),
    meta()
{

}

QDataStream &operator<<(QDataStream &out, const StatesHistoryIncidenceEndpointData &data)
{
    out << data.data
        << data.meta;
    return out;
}

QDataStream &operator>>(QDataStream &in, StatesHistoryIncidenceEndpointData &data)
{
    data = StatesHistoryIncidenceEndpointData();
    in >> data.data
       >> data.meta;
    return in;
}
