#ifndef VACCINATIONDATA_H
#define VACCINATIONDATA_H

#include <QString>

class VaccinationData
{
public:
    VaccinationData(int vaccinated, int biontech, int moderna, int astraZeneca, int janssen, int novavax,int delta, double quote);
    VaccinationData();
    int vaccinated;
    int biontech;
    int moderna;
    int astraZeneca;
    int janssen;
    int novavax;
    int delta;
    double quote;
    friend QDataStream &operator<<(QDataStream &out, const VaccinationData &data);
    friend QDataStream &operator>>(QDataStream &in, VaccinationData &data);
};

QDataStream &operator<<(QDataStream &out, const VaccinationData &data);
QDataStream &operator>>(QDataStream &in, VaccinationData &data);

#endif // VACCINATIONDATA_H
