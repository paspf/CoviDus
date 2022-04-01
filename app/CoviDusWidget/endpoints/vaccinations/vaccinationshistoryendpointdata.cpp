#include "vaccinationshistoryendpointdata.h"

VaccinationsHistoryEndpointData::VaccinationsHistoryEndpointData(QJsonDocument json):
    history(),
    meta(json["meta"].toObject())
{
    QJsonObject infos = json["data"].toObject();
    for (auto info : infos["history"].toArray())
    {
        QJsonObject histData = info.toObject();
        QString date = histData["date"].toString();
        VaccinationHistoryData hdat = VaccinationHistoryData(
            date,
            histData["vaccinated"].toInt(),
            histData["firstVaccination"].toInt(),
            histData["secondVaccination"].toInt(),
            histData["boosterVaccination"].toInt()
            );
        history.push_back(hdat);
    }
}

VaccinationsHistoryEndpointData::VaccinationsHistoryEndpointData() :
    history(),
    meta()
{

}

QDataStream &operator<<(QDataStream &out, const VaccinationsHistoryEndpointData &data)
{
    out << data.history
        << data.meta;
    return out;
}

QDataStream &operator>>(QDataStream &in, VaccinationsHistoryEndpointData &data)
{
    data = VaccinationsHistoryEndpointData();
    in >> data.history
       >> data.meta;
    return in;
}
