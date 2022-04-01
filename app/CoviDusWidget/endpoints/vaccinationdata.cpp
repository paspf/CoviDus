#include "vaccinationdata.h"

VaccinationData::VaccinationData(
        int vaccinated,
        int biontech,
        int moderna,
        int astraZeneca,
        int janssen,
        int novavax,
        int delta,
        double quote
    ):
    vaccinated(vaccinated),
    biontech(biontech),
    moderna(moderna),
    astraZeneca(astraZeneca),
    janssen(janssen),
    novavax(novavax),
    delta(delta),
    quote(quote)
{

}

VaccinationData::VaccinationData() :
    vaccinated(0),
    biontech(0),
    moderna(0),
    astraZeneca(0),
    janssen(0),
    novavax(0),
    delta(),
    quote()
{

}

QDataStream &operator<<(QDataStream &out, const VaccinationData &data)
{
    out << QString::number(data.vaccinated)
        << QString::number(data.biontech)
        << QString::number(data.moderna)
        << QString::number(data.astraZeneca)
        << QString::number(data.janssen)
        << QString::number(data.novavax)
        << QString::number(data.delta)
        << QString::number(data.quote);

    return out;
}

QDataStream &operator>>(QDataStream &in, VaccinationData &data)
{
    data = VaccinationData();
    QString vaccinated;
    QString biontech;
    QString moderna;
    QString astraZeneca;
    QString janssen;
    QString novavax;
    QString delta;
    QString quote;

    in >> vaccinated
       >> biontech
       >> moderna
       >> astraZeneca
       >> janssen
       >> novavax
       >> delta
       >> quote;
    data.vaccinated = vaccinated.toInt();
    data.biontech = biontech.toInt();
    data.moderna = moderna.toInt();
    data.astraZeneca = astraZeneca.toInt();
    data.janssen = janssen.toInt();
    data.novavax = novavax.toInt();
    data.delta = delta.toDouble();
    data.quote = quote.toDouble();
    return in;
}
