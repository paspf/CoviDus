#ifndef ENDPOINTDATARETAINER_H
#define ENDPOINTDATARETAINER_H

#include <QObject>

// Germany
#include "endpoints/germany/germanyendpointdata.h"
#include "endpoints/germany/germanyagegroupsendpointdata.h"
#include "endpoints/germany/germanyhistorycasesendpointdata.h"
#include "endpoints/germany/germanyhistorydeathsendpointdata.h"
#include "endpoints/germany/germanyhistoryincidenceendpointdata.h"
#include "endpoints/germany/germanyhistoryrecoveredendpointdata.h"

// Districts
#include "endpoints/districts/districtsendpointdata.h"
#include "endpoints/districts/districtshistorycasesendpointdata.h"
#include "endpoints/districts/districtshistorydeathsendpointdata.h"
#include "endpoints/districts/districtshistoryfrozenincidenceendpointdata.h"
#include "endpoints/districts/districtshistoryincidenceendpointdata.h"
#include "endpoints/districts/districtshistoryrecoveredendpointdata.h"

// States
#include "endpoints/states/statesendpointdata.h"
#include "endpoints/states/statesagegroupsendpointdata.h"
#include "endpoints/states/stateshistorycasesendpointdata.h"
#include "endpoints/states/stateshistorydeathsendpointdata.h"
#include "endpoints/states/stateshistoryincidenceendpointdata.h"
#include "endpoints/states/stateshistoryincidenceendpointdata.h"
#include "endpoints/states/stateshistoryrecoveredendpoint.h"

// Vaccinations
#include "endpoints/vaccinations/vaccinationsendpointdata.h"
#include "endpoints/vaccinations/vaccinationshistoryendpointdata.h"

// Maps
#include <QImage>
#include "endpoints/legendinfo.h"


class EndpointDataRetainer : public QObject
{
    Q_OBJECT
public:
    EndpointDataRetainer();

    // Germany
    void setGermanyEndpointData(GermanyEndpointData *data);
    void setGermanyAgeGroupsEndpointData(GermanyAgeGroupsEndpointData *data);
    void setGermanyHistoryCasesEndpointData(GermanyHistoryCasesEndpointData *data);
    void setGermanyHistoryDeathsEndpointData(GermanyHistoryDeathsEndpointData *data);
    void setGermanyHistoryIncidenceEndpointData(GermanyHistoryIncidenceEndpointData *data);
    void setGermanyHistoryRecoveredEndpointData(GermanyHistoryRecoveredEndpointData *data);
    GermanyEndpointData& getGermanyEndpointData();
    GermanyAgeGroupsEndpointData& getGermanyAgeGroupsEndpointData();
    GermanyHistoryCasesEndpointData& getGermanyHistoryCasesEndpointData();
    GermanyHistoryDeathsEndpointData& getGermanyHistoryDeathsEndpointData();
    GermanyHistoryIncidenceEndpointData& getGermanyHistoryIncidenceEndpointData();
    GermanyHistoryRecoveredEndpointData& getGermanyHistoryRecoveredEndpointData();

    // Districts
    void setDistrictsEndpointData(DistrictsEndpointData *data);
    void setDistrictsHistoryCasesEndpointData(DistrictsHistoryCasesEndpointData *data);
    void setDistrictsHistoryDeathsEndpointData(DistrictsHistoryDeathsEndpointData *data);
    void setDistrictsHistoryFrozenIncidenceEndpointData(DistrictsHistoryFrozenIncidenceEndpointData *data);
    void setDistrictsHistoryIncidenceEndpointData(DistrictsHistoryIncidenceEndpointData *data);
    void setDistrictsHistoryRecoveredEndpointData(DistrictsHistoryRecoveredEndpointData *data);
    DistrictsEndpointData& getDistrictsEndpointData();
    DistrictsHistoryCasesEndpointData& getDistrictsHistoryCasesEndpointData();
    DistrictsHistoryDeathsEndpointData& getDistrictsHistoryDeathsEndpointData();
    DistrictsHistoryFrozenIncidenceEndpointData& getDistrictsHistoryFrozenIncidenceEndpointData();
    DistrictsHistoryIncidenceEndpointData& getDistrictsHistoryIncidenceEndpointData();
    DistrictsHistoryRecoveredEndpointData& getDistrictsHistoryRecoveredEndpointData();

    // States
    void setStatesEndpointData(StatesEndpointData *data);
    void setStatesAgeGroupsEndpointData(StatesAgeGroupsEndpointData *data);
    void setStatesHistoryCasesEndpointData(StatesHistoryCasesEndpointData *data);
    void setStatesHistoryDeathsEndpointData(StatesHistoryDeathsEndpointData *data);
    void setStatesHistoryIncidenceEndpointData(StatesHistoryIncidenceEndpointData *data);
    void setStatesHistoryRecoveredEndpointData(StatesHistoryRecoveredEndpointData *data);
    StatesEndpointData& getStatesEndpointData();
    StatesAgeGroupsEndpointData& getStatesAgeGroupsEndpointData();
    StatesHistoryCasesEndpointData& getStatesHistoryCasesEndpointData();
    StatesHistoryDeathsEndpointData& getStatesHistoryDeathsEndpointData();
    StatesHistoryIncidenceEndpointData& getStatesHistoryIncidenceEndpointData();
    StatesHistoryRecoveredEndpointData& getStatesHistoryRecoveredEndpointData();

    // Maps
    void setMapDistrictsEndpoint(QImage *image);
    void setMapDistrictsLegendEndpoint(QVector<LegendInfo> *statesInfo);
    void setMapStatesEndpoint(QImage *image);
    void setMapStatesLegendEndpoint(QVector<LegendInfo> *statesInfo);
    QImage& getMapDistrictsEndpoint();
    QVector<LegendInfo>& getMapDistrictsLegendEndpoint();
    QImage& getMapStatesEndpoint();
    QVector<LegendInfo>& getMapStatesLegendEndpoint();

    // Vaccinations
    void setVaccinationsEndpointData(VaccinationsEndpointData *data);
    void setVaccinationsHistoryEndpointData(VaccinationsHistoryEndpointData *data);
    VaccinationsEndpointData& getVaccinationsEndpointData();
    VaccinationsHistoryEndpointData& getVaccinationsHistoryEndpointData();

    // Operators
    friend QDataStream &operator<<(QDataStream &out, const EndpointDataRetainer &data);
    friend QDataStream &operator>>(QDataStream &in, EndpointDataRetainer &data);

public slots:
    // Germany
    void receiveGermanyEndpointData(GermanyEndpointData *data);
    void receiveGermanyAgeGroupsEndpointData(GermanyAgeGroupsEndpointData *data);
    void receiveGermanyHistoryCasesEndpointData(GermanyHistoryCasesEndpointData *data);
    void receiveGermanyHistoryDeathsEndpointData(GermanyHistoryDeathsEndpointData *data);
    void receiveGermanyHistoryIncidenceEndpointData(GermanyHistoryIncidenceEndpointData *data);
    void receiveGermanyHistoryRecoveredEndpointData(GermanyHistoryRecoveredEndpointData *data);

    // Districts
    void receiveDistrictsEndpointData(DistrictsEndpointData *data);
    void receiveDistrictsHistoryCasesEndpointData(DistrictsHistoryCasesEndpointData *data);
    void receiveDistrictsHistoryDeathsEndpointData(DistrictsHistoryDeathsEndpointData *data);
    void receiveDistrictsHistoryFrozenIncidenceEndpointData(DistrictsHistoryFrozenIncidenceEndpointData *data);
    void receiveDistrictsHistoryIncidenceEndpointData(DistrictsHistoryIncidenceEndpointData *data);
    void receiveDistrictsHistoryRecoveredEndpointData(DistrictsHistoryRecoveredEndpointData *data);

    // States
    void receiveStatesEndpointData(StatesEndpointData *data);
    void receiveStatesAgeGroupsEndpointData(StatesAgeGroupsEndpointData *data);
    void receiveStatesHistoryCasesEndpointData(StatesHistoryCasesEndpointData *data);
    void receiveStatesHistoryDeathsEndpointData(StatesHistoryDeathsEndpointData *data);
    void receiveStatesHistoryIncidenceEndpointData(StatesHistoryIncidenceEndpointData *data);
    void receiveStatesHistoryRecoveredEndpointData(StatesHistoryRecoveredEndpointData *data);

    // Maps
    void receiveMapDistrictsEndpoint(QImage *image);
    void receiveMapDistrictsLegendEndpoint(QVector<LegendInfo> *statesInfo);
    void receiveMapStatesEndpoint(QImage *image);
    void receiveMapStatesLegendEndpoint(QVector<LegendInfo> *statesInfo);

    // Vaccinations
    void receiveVaccinationsEndpointData(VaccinationsEndpointData *data);
    void receiveVaccinationsHistoryEndpointData(VaccinationsHistoryEndpointData *data);

signals:
    // Germany
    void signalGermanyEndpointData(GermanyEndpointData *data);
    void signalGermanyAgeGroupsEndpointData(GermanyAgeGroupsEndpointData *data);
    void signalGermanyHistoryCasesEndpointData(GermanyHistoryCasesEndpointData *data);
    void signalGermanyHistoryDeathsEndpointData(GermanyHistoryDeathsEndpointData *data);
    void signalGermanyHistoryIncidenceEndpointData(GermanyHistoryIncidenceEndpointData *data);
    void signalGermanyHistoryRecoveredEndpointData(GermanyHistoryRecoveredEndpointData *data);

    // Districts
    void signalDistrictsEndpointData(DistrictsEndpointData *data);
    void signalDistrictsHistoryCasesEndpointData(DistrictsHistoryCasesEndpointData *data);
    void signalDistrictsHistoryDeathsEndpointData(DistrictsHistoryDeathsEndpointData *data);
    void signalDistrictsHistoryFrozenIncidenceEndpointData(DistrictsHistoryFrozenIncidenceEndpointData *data);
    void signalDistrictsHistoryIncidenceEndpointData(DistrictsHistoryIncidenceEndpointData *data);
    void signalDistrictsHistoryRecoveredEndpointData(DistrictsHistoryRecoveredEndpointData *data);

    // States
    void signalStatesEndpointData(StatesEndpointData *data);
    void signalStatesAgeGroupsEndpointData(StatesAgeGroupsEndpointData *data);
    void signalStatesHistoryCasesEndpointData(StatesHistoryCasesEndpointData *data);
    void signalStatesHistoryDeathsEndpointData(StatesHistoryDeathsEndpointData *data);
    void signalStatesHistoryIncidenceEndpointData(StatesHistoryIncidenceEndpointData *data);
    void signalStatesHistoryRecoveredEndpointData(StatesHistoryRecoveredEndpointData *data);

    // Maps
    void signalMapDistrictsEndpoint(QImage *image);
    void signalMapDistrictsLegendEndpoint(QVector<LegendInfo> *statesInfo);
    void signalMapStatesEndpoint(QImage *image);
    void signalMapStatesLegendEndpoint(QVector<LegendInfo> *statesInfo);

    // Vaccinations
    void signalVaccinationsEndpointData(VaccinationsEndpointData *data);
    void signalVaccinationsHistoryEndpointData(VaccinationsHistoryEndpointData *data);

private:
    // Germany
    GermanyEndpointData germanyEndpointData;
    GermanyAgeGroupsEndpointData germanyAgeGroupsEndpointData;
    GermanyHistoryCasesEndpointData germanyHistoryCasesEndpointData;
    GermanyHistoryDeathsEndpointData germanyHistoryDeathsEndpointData;
    GermanyHistoryIncidenceEndpointData germanyHistoryIncidenceEndpointData;
    GermanyHistoryRecoveredEndpointData germanyHistoryRecoveredEndpointData;

    // Districts
    DistrictsEndpointData districtsEndpointData;
    DistrictsHistoryCasesEndpointData districtsHistoryCasesEndpointData;
    DistrictsHistoryDeathsEndpointData districtsHistoryDeathsEndpointData;
    DistrictsHistoryFrozenIncidenceEndpointData districtsHistoryFrozenIncidenceEndpointData;
    DistrictsHistoryIncidenceEndpointData districtsHistoryIncidenceEndpointData;
    DistrictsHistoryRecoveredEndpointData districtsHistoryRecoveredEndpointData;

    // States
    StatesEndpointData statesEndpointData;
    StatesAgeGroupsEndpointData statesAgeGroupsEndpointData;
    StatesHistoryCasesEndpointData statesHistoryCasesEndpointData;
    StatesHistoryDeathsEndpointData statesHistoryDeathsEndpointData;
    StatesHistoryIncidenceEndpointData statesHistoryIncidenceEndpointData;
    StatesHistoryRecoveredEndpointData statesHistoryRecoveredEndpointData;

    // Maps
    QImage mapDistrictsEndpoint;
    QList<LegendInfo> mapDistricsLegendEndpoint;
    QImage mapStatesEndpoint;
    QList<LegendInfo> mapStatesLegendEndpoint;

    // Vaccinations
    VaccinationsEndpointData vaccinationsEndpointData;
    VaccinationsHistoryEndpointData vaccinationsHistoryEndpointData;

};

QDataStream &operator<<(QDataStream &out, const EndpointDataRetainer &data);
QDataStream &operator>>(QDataStream &in, EndpointDataRetainer &data);

#endif // ENDPOINTDATARETAINER_H
