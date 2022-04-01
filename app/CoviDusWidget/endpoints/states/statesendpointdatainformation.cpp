#include "statesendpointdatainformation.h"

StatesEndpointDataInformation::StatesEndpointDataInformation(
        QString &id,
        QString &state,
        int population,
        int cases,
        int deaths,
        double casesPerWeek,
        double deathsPerWeek,
        QString &stateAbbreviation,
        int recovered,
        double weekIncidence,
        double casesPer100k,
        DeltaData delta
    ):
    id(id),
    name(state),
    state(state),
    population(population),
    cases(cases),
    deaths(deaths),
    casesPerWeek(casesPerWeek),
    deathsPerWeek(deathsPerWeek),
    stateAbbreviation(stateAbbreviation),
    recovered(recovered),
    weekIncidence(weekIncidence),
    casesPer100k(casesPer100k),
    delta(delta)
{

}

StatesEndpointDataInformation::StatesEndpointDataInformation() :
    id(),
    name(),
    state(),
    population(),
    cases(),
    deaths(),
    casesPerWeek(),
    deathsPerWeek(),
    stateAbbreviation(),
    recovered(),
    weekIncidence(),
    casesPer100k(),
    delta()
{

}

QDataStream &operator<<(QDataStream &out, const StatesEndpointDataInformation &data)
{
    out << data.id
        << data.name
        << data.state
        << data.population
        << data.cases
        << data.deaths
        << data.casesPerWeek
        << data.deathsPerWeek
        << data.stateAbbreviation
        << data.recovered
        << data.weekIncidence
        << data.casesPer100k
        << data.delta;
    return out;
}

QDataStream &operator>>(QDataStream &in, StatesEndpointDataInformation &data)
{
    data = StatesEndpointDataInformation();
    in >> data.id
       >> data.name
       >> data.state
       >> data.population
       >> data.cases
       >> data.deaths
       >> data.casesPerWeek
       >> data.deathsPerWeek
       >> data.stateAbbreviation
       >> data.recovered
       >> data.weekIncidence
       >> data.casesPer100k
       >> data.delta;
    return in;
}
