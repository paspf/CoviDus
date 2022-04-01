#include "vaccinationsendpointdatainformation.h"

VaccinationsEndpointDataInformation::VaccinationsEndpointDataInformation(
        QString name,
        QString stateAbbreviation,
        VaccinationData firstVaccination,
        VaccinationData secondVaccination,
        VaccinationData boosterVaccination
):
    name(name),
    stateAbbreviation(stateAbbreviation),
    firstVaccination(firstVaccination),
    secondVaccination(secondVaccination),
    boosterVaccination(boosterVaccination)
{

}

VaccinationsEndpointDataInformation::VaccinationsEndpointDataInformation() :
    name(),
    stateAbbreviation(),
    firstVaccination(),
    secondVaccination(),
    boosterVaccination()
{

}

QDataStream &operator<<(QDataStream &out, const VaccinationsEndpointDataInformation &data)
{
    out << data.name
        << data.stateAbbreviation
        << data.firstVaccination
        << data.secondVaccination
        << data.boosterVaccination;
    return out;
}

QDataStream &operator>>(QDataStream &in, VaccinationsEndpointDataInformation &data)
{
    data = VaccinationsEndpointDataInformation();
    in >> data.name
       >> data.stateAbbreviation
       >> data.firstVaccination
       >> data.secondVaccination
       >> data.boosterVaccination;
    return in;
}
