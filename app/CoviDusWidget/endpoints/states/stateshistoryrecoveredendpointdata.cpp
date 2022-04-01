#include "stateshistoryrecoveredendpointdata.h"

StatesHistoryRecoveredEndpointData::StatesHistoryRecoveredEndpointData(QJsonDocument json) :
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
            HistoryData hdat = HistoryData(histData["recovered"].toDouble(), date);
            history.push_back(hdat);
        }
        QString id = QString::number(elem["id"].toInt());
        QString name = elem["name"].toString();
        data.insert(
            key,
            StatesHistoryRecoveredEndpointDataInformation(
                id,
                name,
                history
            )
        );
    }
}

StatesHistoryRecoveredEndpointData::StatesHistoryRecoveredEndpointData():
    data(),
    meta()
{

}

QDataStream &operator<<(QDataStream &out, const StatesHistoryRecoveredEndpointData &data)
{
    out << data.data
        << data.meta;
    return out;
}

QDataStream &operator>>(QDataStream &in, StatesHistoryRecoveredEndpointData &data)
{
    data = StatesHistoryRecoveredEndpointData();
    in >> data.data
       >> data.meta;
    return in;
}
