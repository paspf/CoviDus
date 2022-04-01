#include "vaccinationhistorydata.h"

VaccinationHistoryData::VaccinationHistoryData(QString date, int vaccinated, int firstVaccination, int secondVaccination, int boosterVaccination):
    date(QDateTime::fromString(date, "yyyy-MM-ddTHH:mm:ss.zzzZ")),
    vaccinated(vaccinated),
    firstVaccination(firstVaccination),
    secondVaccination(secondVaccination),
    boosterVaccination(boosterVaccination)
{

}

VaccinationHistoryData::VaccinationHistoryData() :
    date(QDateTime::currentDateTime()),
    vaccinated(),
    firstVaccination(),
    secondVaccination(),
    boosterVaccination()
{

}

QDataStream &operator<<(QDataStream &out, const VaccinationHistoryData &data)
{
    out << data.date
        << data.vaccinated
        << data.firstVaccination
        << data.secondVaccination
        << data.boosterVaccination;
    return out;
}

QDataStream &operator>>(QDataStream &in, VaccinationHistoryData &data)
{
    data = VaccinationHistoryData();
    in >> data.date
       >> data.vaccinated
       >> data.firstVaccination
       >> data.secondVaccination
       >> data.boosterVaccination;
    return in;
}
