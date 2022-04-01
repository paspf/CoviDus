#include "vaccinationsendpointdata.h"

VaccinationsEndpointData::VaccinationsEndpointData(QJsonDocument json):
    administeredVaccinations(json["data"].toObject()["administeredVaccinations"].toInt()),
    firstVaccination(
        json["data"].toObject()["vaccinated"].toInt(),
        json["data"].toObject()["vaccination"].toObject()["biontech"].toInt(),
        json["data"].toObject()["vaccination"].toObject()["moderna"].toInt(),
        json["data"].toObject()["vaccination"].toObject()["astraZeneca"].toInt(),
        json["data"].toObject()["vaccination"].toObject()["janssen"].toInt(),
        json["data"].toObject()["vaccination"].toObject()["novavax"].toInt(),
        json["data"].toObject()["delta"].toInt(),
        json["data"].toObject()["quote"].toDouble()
    ),
    secondVaccination(
        json["data"].toObject()["secondVaccination"].toObject()["vaccinated"].toInt(),
        json["data"].toObject()["secondVaccination"].toObject()["vaccination"].toObject()["biontech"].toInt(),
        json["data"].toObject()["secondVaccination"].toObject()["vaccination"].toObject()["moderna"].toInt(),
        json["data"].toObject()["secondVaccination"].toObject()["vaccination"].toObject()["astraZeneca"].toInt(),
        json["data"].toObject()["secondVaccination"].toObject()["vaccination"].toObject()["janssen"].toInt(),
        json["data"].toObject()["secondVaccination"].toObject()["vaccination"].toObject()["novavax"].toInt(),
        json["data"].toObject()["secondVaccination"].toObject()["delta"].toInt(),
        json["data"].toObject()["secondVaccination"].toObject()["quote"].toDouble()
    ),
    boosterVaccination(
        json["data"].toObject()["boosterVaccination"].toObject()["vaccinated"].toInt(),
        json["data"].toObject()["boosterVaccination"].toObject()["vaccination"].toObject()["biontech"].toInt(),
        json["data"].toObject()["boosterVaccination"].toObject()["vaccination"].toObject()["moderna"].toInt(),
        json["data"].toObject()["boosterVaccination"].toObject()["vaccination"].toObject()["astraZeneca"].toInt(),
        json["data"].toObject()["boosterVaccination"].toObject()["vaccination"].toObject()["janssen"].toInt(),
        json["data"].toObject()["boosterVaccination"].toObject()["vaccination"].toObject()["novavax"].toInt(),
        json["data"].toObject()["boosterVaccination"].toObject()["delta"].toInt(),
        json["data"].toObject()["boosterVaccination"].toObject()["quote"].toDouble() // not available, will be 0
    ),
    latestDailyVaccinations(
        json["data"].toObject()["latestDailyVaccinations"].toObject()["date"].toString(),
        json["data"].toObject()["latestDailyVaccinations"].toObject()["vaccinated"].toInt(),
        json["data"].toObject()["latestDailyVaccinations"].toObject()["firstVaccination"].toInt(),
        json["data"].toObject()["latestDailyVaccinations"].toObject()["secondVaccination"].toInt(),
        json["data"].toObject()["latestDailyVaccinations"].toObject()["bosterVaccination"].toInt()
    ),
    states(),
    meta(json["meta"].toObject())
{

    QJsonObject infos = json["data"].toObject()["states"].toObject();
    for (QString &key : infos.keys())
    {
        QJsonObject info = infos[key].toObject();
        states.insert(
            info["name"].toString(),
            VaccinationsEndpointDataInformation(
                info["name"].toString(),
                key,
                VaccinationData(
                    info["vaccinated"].toInt(),
                    info["vaccination"].toObject()["biontech"].toInt(),
                    info["vaccination"].toObject()["moderna"].toInt(),
                    info["vaccination"].toObject()["astraZeneca"].toInt(),
                    info["vaccination"].toObject()["janssen"].toInt(),
                    info["vaccination"].toObject()["novavax"].toInt(),
                    info["delta"].toInt(),
                    info["quote"].toDouble()
                ),
                VaccinationData(
                    info["secondVaccination"].toObject()["vaccinated"].toInt(),
                    info["secondVaccination"].toObject()["vaccination"].toObject()["biontech"].toInt(),
                    info["secondVaccination"].toObject()["vaccination"].toObject()["moderna"].toInt(),
                    info["secondVaccination"].toObject()["vaccination"].toObject()["astraZeneca"].toInt(),
                    info["secondVaccination"].toObject()["vaccination"].toObject()["janssen"].toInt(),
                    info["secondVaccination"].toObject()["vaccination"].toObject()["novavax"].toInt(),
                    info["secondVaccination"].toObject()["delta"].toInt(),
                    info["secondVaccination"].toObject()["quote"].toDouble()
                ),
                VaccinationData(
                    info["boosterVaccination"].toObject()["vaccinated"].toInt(),
                    info["boosterVaccination"].toObject()["vaccination"].toObject()["biontech"].toInt(),
                    info["boosterVaccination"].toObject()["vaccination"].toObject()["moderna"].toInt(),
                    info["boosterVaccination"].toObject()["vaccination"].toObject()["astraZeneca"].toInt(),
                    info["boosterVaccination"].toObject()["vaccination"].toObject()["janssen"].toInt(),
                    info["boosterVaccination"].toObject()["vaccination"].toObject()["novavax"].toInt(),
                    info["boosterVaccination"].toObject()["delta"].toInt(),
                    info["boosterVaccination"].toObject()["quote"].toDouble() // not available, will be 0
                )
            )
        );
    }
}

VaccinationsEndpointData::VaccinationsEndpointData() :
    administeredVaccinations(),
    firstVaccination(),
    secondVaccination(),
    latestDailyVaccinations(),
    states(),
    meta()

{

}

QDataStream &operator<<(QDataStream &out, const VaccinationsEndpointData &data)
{
    out << data.administeredVaccinations
        << data.firstVaccination
        << data.secondVaccination
        << data.boosterVaccination
        << data.latestDailyVaccinations
        << data.states
        << data.meta;

    return out;
}

QDataStream &operator>>(QDataStream &in, VaccinationsEndpointData &data)
{
    data = VaccinationsEndpointData();
    in >> data.administeredVaccinations
       >> data.firstVaccination
       >> data.secondVaccination
       >> data.boosterVaccination
       >> data.latestDailyVaccinations
       >> data.states
       >> data.meta;
    return in;
}
