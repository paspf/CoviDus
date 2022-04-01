#include "stateshistorydeathsendpointdata.h"

StatesHistoryDeathsEndpointData::StatesHistoryDeathsEndpointData(QJsonDocument json):
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
            HistoryData hdat = HistoryData(histData["deaths"].toDouble(), date);
            history.push_back(hdat);
        }
        QString id = QString::number(elem["id"].toInt());
        QString name = elem["name"].toString();
        data.insert(
            key,
            StatesHistoryDeathsEndpointDataInformation(
                id,
                name,
                history
            )
        );
    }
}

StatesHistoryDeathsEndpointData::StatesHistoryDeathsEndpointData() :
    data(),
    meta()
{

}

QDataStream &operator<<(QDataStream &out, const StatesHistoryDeathsEndpointData &data)
{
    out << data.data
        << data.meta;
    return out;
}

QDataStream &operator>>(QDataStream &in, StatesHistoryDeathsEndpointData &data)
{
    data = StatesHistoryDeathsEndpointData();
    in >> data.data
       >> data.meta;
    return in;
}
