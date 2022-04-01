#include "stateshistorycasesendpointdata.h"

StatesHistoryCasesEndpointData::StatesHistoryCasesEndpointData(QJsonDocument json):
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
            HistoryData hdat = HistoryData(histData["cases"].toDouble(), date);
            history.push_back(hdat);
        }
        QString id = QString::number(elem["id"].toInt());
        QString name = elem["name"].toString();
        data.insert(
            key,
            StatesHistoryCasesEndpointDataInformation(
                id,
                name,
                history
            )
        );
    }
}

StatesHistoryCasesEndpointData::StatesHistoryCasesEndpointData() :
    data(),
    meta()
{

}

QDataStream &operator<<(QDataStream &out, const StatesHistoryCasesEndpointData &data)
{
    out << data.data
        << data.meta;
    return out;
}

QDataStream &operator>>(QDataStream &in, StatesHistoryCasesEndpointData &data)
{
    data = StatesHistoryCasesEndpointData();
    in >> data.data
       >> data.meta;
    return in;
}
