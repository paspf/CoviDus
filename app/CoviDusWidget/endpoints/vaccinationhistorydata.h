#ifndef VACCINATIONHISTORYDATA_H
#define VACCINATIONHISTORYDATA_H

#include<QDateTime>

class VaccinationHistoryData
{
public:
    VaccinationHistoryData(QString date, int vaccinated, int firstVaccination, int secondVaccination, int boosterVaccination);
    VaccinationHistoryData();
    QDateTime date;
    int vaccinated;
    int firstVaccination;
    int secondVaccination;
    int boosterVaccination;
    friend QDataStream &operator<<(QDataStream &out, const VaccinationHistoryData &data);
    friend QDataStream &operator>>(QDataStream &in, VaccinationHistoryData &data);
};

QDataStream &operator<<(QDataStream &out, const VaccinationHistoryData &data);
QDataStream &operator>>(QDataStream &in, VaccinationHistoryData &data);

#endif // VACCINATIONHISTORYDATA_H
