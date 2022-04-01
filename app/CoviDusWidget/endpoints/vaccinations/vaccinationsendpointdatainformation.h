#ifndef VACCINATIONSENDPOINTDATAINFORMATION_H
#define VACCINATIONSENDPOINTDATAINFORMATION_H

#include<QString>
#include "../vaccinationdata.h"

class VaccinationsEndpointDataInformation
{
public:
    VaccinationsEndpointDataInformation(QString name, QString stateAbbreviation, VaccinationData firstVaccination, VaccinationData secondVaccination, VaccinationData boosterVaccination);
    VaccinationsEndpointDataInformation();
    QString name;
    QString stateAbbreviation;
    VaccinationData firstVaccination;
    VaccinationData secondVaccination;
    VaccinationData boosterVaccination;
    friend QDataStream &operator<<(QDataStream &out, const VaccinationsEndpointDataInformation &data);
    friend QDataStream &operator>>(QDataStream &in, VaccinationsEndpointDataInformation &data);
};

QDataStream &operator<<(QDataStream &out, const VaccinationsEndpointDataInformation &data);
QDataStream &operator>>(QDataStream &in, VaccinationsEndpointDataInformation &data);

#endif // VACCINATIONSENDPOINTDATAINFORMATION_H
