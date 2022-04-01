#include "districtsendpointdatainformation.h"

DistrictsEndpointDataInformation::DistrictsEndpointDataInformation(
    QString ags,
    QString name,
    QString county,
    QString state,
    int population,
    int cases,
    int deaths,
    int casesPerWeek,
    int deathsPerWeek,
    QString stateAbbreviation,
    int recovered,
    double weekIncidence,
    double casesPer100k,
    DeltaData delta
):
    ags(ags),
    name(name),
    county(county),
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

DistrictsEndpointDataInformation::DistrictsEndpointDataInformation() :
    ags(),
    name(),
    county(),
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

QDataStream &operator<<(QDataStream &out, const DistrictsEndpointDataInformation &data)
{
    out << data.ags
        << data.name
        << data.county
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

QDataStream &operator>>(QDataStream &in, DistrictsEndpointDataInformation &data)
{
    data = DistrictsEndpointDataInformation();
    in >> data.ags
       >> data.name
       >> data.county
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
