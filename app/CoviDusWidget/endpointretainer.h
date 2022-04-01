#ifndef ENDPOINTRETAINER_H
#define ENDPOINTRETAINER_H


#include <QThread>
#include "endpoints/germany/germanyendpoint.h"
#include "endpoints/germany/germanyhistorycasesendpoint.h"
#include "endpoints/germany/germanyhistoryincidenceendpoint.h"
#include "endpoints/germany/germanyhistorydeathsendpoint.h"
#include "endpoints/germany/germanyhistoryrecoveredendpoint.h"
#include "endpoints/germany/germanyagegroupsendpoint.h"
#include "endpoints/districts/districtsendpoint.h"
#include "endpoints/districts/districtshistorycasesendpoint.h"
#include "endpoints/districts/districtshistorydeathsendpoint.h"
#include "endpoints/districts/districtshistoryfrozenincidenceendpoint.h"
#include "endpoints/districts/districtshistoryincidenceendpoint.h"
#include "endpoints/districts/districtshistoryrecoveredendpoint.h"
#include "endpoints/map/mapdistrictsendpoint.h"
#include "endpoints/map/mapstatesendpoint.h"
#include "endpoints/map/mapdistrictslegendendpoint.h"
#include "endpoints/map/mapstateslegendendpoint.h"
#include "endpoints/states/statesagegroupsendpoint.h"
#include "endpoints/states/statesendpoint.h"
#include "endpoints/states/stateshistorycasesendpoint.h"
#include "endpoints/states/stateshistorydeathsendpoint.h"
#include "endpoints/states/stateshistoryincidenceendpoint.h"
#include "endpoints/states/stateshistoryrecoveredendpoint.h"
#include "endpoints/vaccinations/vaccinationsendpoint.h"
#include "endpoints/vaccinations/vaccinationshistoryendpoint.h"

class EndpointRetainer : public QObject
{
    Q_OBJECT
public:
    explicit EndpointRetainer(const QString baseUrl);
    explicit EndpointRetainer();
    ~EndpointRetainer();

    inline static const QString baseUrlRKI = "https://api.corona-zahlen.org";
    const quint8 NUM_OF_ENDPOINTS = 24;
    GermanyEndpoint* germanyEndpoint = nullptr;
    GermanyHistoryCasesEndpoint* germanyHistoryCasesEndpoint = nullptr;
    GermanyHistoryIncidenceEndpoint* germanyHistoryIncidenceEndpoint = nullptr;
    GermanyHistoryDeathsEndpoint* germanyHistoryDeathsEndpoint = nullptr;
    GermanyHistoryRecoveredEndpoint* germanyHistoryRecoveredEndpoint = nullptr;
    GermanyAgeGroupsEndpoint* germanyAgeGroupsEndpoint = nullptr;
    DistrictsEndpoint* districtsEndpoint = nullptr;
    DistrictsHistoryCasesEndpoint* districtsHistoryCasesEndpoint = nullptr;
    DistrictsHistoryDeathsEndpoint* districtsHistoryDeathsEndpoint = nullptr;
    DistrictsHistoryFrozenIncidenceEndpoint* districtsHistoryFrozenIncidenceEndpoint = nullptr;
    DistrictsHistoryIncidenceEndpoint* districtsHistoryIncidenceEndpoint = nullptr;
    DistrictsHistoryRecoveredEndpoint* districtsHistoryRecoveredEndpoint = nullptr;
    MapDistrictsEndpoint* mapDistrictsEndpoint = nullptr;
    MapStatesEndpoint* mapStatesEndpoint = nullptr;
    MapDistrictsLegendEndpoint* mapDistrictsLegendEndpoint = nullptr;
    MapStatesLegendEndpoint* mapStatesLegendEndpoint = nullptr;
    StatesAgeGroupsEndpoint* statesAgeGroupsEndpoint = nullptr;
    StatesEndpoint* statesEndpoint = nullptr;
    StatesHistoryCasesEndpoint* statesHistoryCasesEndpoint = nullptr;
    StatesHistoryDeathsEndpoint* statesHistoryDeathsEndpoint = nullptr;
    StatesHistoryIncidenceEndpoint* statesHistoryIncidenceEndpoint = nullptr;
    StatesHistoryRecoveredEndpoint* statesHistoryRecoveredEndpoint = nullptr;
    VaccinationsEndpoint* vaccinationsEndpoint = nullptr;
    VaccinationsHistoryEndpoint* vaccinationsHistoryEndpoint = nullptr;

    void setBaseUrl(const QString &baseUrl);
    void initEndpoints();

    void fetchEndpoints(bool periodicFetch);
    void disablePeriodicFetch();
    void enablePeriodicFetch();

public slots:
    void receiveInitEndpointsSignal();
    void receiveFetchEndpointsDataSignal();
    void receiveSingleEndpointFetched();


signals:
    void signalEndpointsReadyToFetchData();
    void signalAllDataFetched();

private:
    void fetchEndpointsNow();
    void fetchEndpointsPeriodic();
    QString baseUrl;
    quint8 endpointsFetched;
    bool periodicFetchEnabled;
    bool periodicFetchTimerEnabled;
};

#endif // ENDPOINTRETAINER_H
