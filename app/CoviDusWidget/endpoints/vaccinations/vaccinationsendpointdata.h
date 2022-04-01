#ifndef VACCINATIONSENDPOINTDATA_H
#define VACCINATIONSENDPOINTDATA_H

#include "../metadata.h"
#include "../vaccinationdata.h"
#include "../vaccinationhistorydata.h"
#include "vaccinationsendpointdatainformation.h"
#include <QJsonDocument>

class VaccinationsEndpointData
{
public:
    explicit VaccinationsEndpointData(QJsonDocument json);
    VaccinationsEndpointData();
    int administeredVaccinations;
    VaccinationData firstVaccination;
    VaccinationData secondVaccination;
    VaccinationData boosterVaccination;
    VaccinationHistoryData latestDailyVaccinations;
    QMap<QString, VaccinationsEndpointDataInformation> states;
    MetaData meta;
    friend QDataStream &operator<<(QDataStream &out, const VaccinationsEndpointData &data);
    friend QDataStream &operator>>(QDataStream &in, VaccinationsEndpointData &data);
};

QDataStream &operator<<(QDataStream &out, const VaccinationsEndpointData &data);
QDataStream &operator>>(QDataStream &in, VaccinationsEndpointData &data);

#endif // VACCINATIONSENDPOINTDATA_H
