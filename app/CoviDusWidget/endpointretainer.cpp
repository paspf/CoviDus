#include "endpointretainer.h"
#include <QTimer>

/**
 * @brief EndpointRetainer::EndpointRetainer
 * Create EndpointRetainer.
 * @param baseUrl Base Server url.
 */
EndpointRetainer::EndpointRetainer(const QString baseUrl) :
    baseUrl(baseUrl),
    endpointsFetched(0),
    periodicFetchEnabled(false),
    periodicFetchTimerEnabled(false)
{

}

/**
 * @brief EndpointRetainer::EndpointRetainer
 * Default constructor.
 */
EndpointRetainer::EndpointRetainer() :
    baseUrl(""),
    endpointsFetched(0),
    periodicFetchEnabled(false),
    periodicFetchTimerEnabled(false)
{

}

/**
 * @brief EndpointRetainer::~EndpointRetainer
 * Destructor.
 */
EndpointRetainer::~EndpointRetainer()
{
    delete germanyEndpoint;
    delete germanyHistoryCasesEndpoint;
    delete germanyHistoryIncidenceEndpoint;
    delete germanyHistoryDeathsEndpoint;
    delete germanyHistoryRecoveredEndpoint;
    delete germanyAgeGroupsEndpoint;
    delete districtsEndpoint;
    delete districtsHistoryCasesEndpoint;
    delete districtsHistoryDeathsEndpoint;
    delete districtsHistoryFrozenIncidenceEndpoint;
    delete districtsHistoryIncidenceEndpoint;
    delete districtsHistoryRecoveredEndpoint;
    delete mapDistrictsEndpoint;
    delete mapStatesEndpoint;
    delete mapDistrictsLegendEndpoint;
    delete mapStatesLegendEndpoint;
    delete statesAgeGroupsEndpoint;
    delete statesEndpoint;
    delete statesHistoryCasesEndpoint;
    delete statesHistoryDeathsEndpoint;
    delete statesHistoryIncidenceEndpoint;
    delete statesHistoryRecoveredEndpoint;
    delete vaccinationsEndpoint;
    delete vaccinationsHistoryEndpoint;
}

/**
 * @brief EndpointRetainer::setBaseUrl
 * Set the base Url.
 * @param baseUrl Base Server url.
 */
void EndpointRetainer::setBaseUrl(const QString &baseUrl)
{
    this->baseUrl = baseUrl;
}

/**
 * @brief EndpointRetainer::initEndpoints
 * Initialize all endpoint objects.
 */
void EndpointRetainer::initEndpoints()
{
    if (baseUrl == "") {
        return;
    }    
    // germany
    germanyEndpoint = new GermanyEndpoint(baseUrl);
    germanyHistoryCasesEndpoint = new GermanyHistoryCasesEndpoint(baseUrl);
    germanyHistoryIncidenceEndpoint = new GermanyHistoryIncidenceEndpoint(baseUrl);
    germanyHistoryDeathsEndpoint = new GermanyHistoryDeathsEndpoint(baseUrl);
    germanyHistoryRecoveredEndpoint = new GermanyHistoryRecoveredEndpoint(baseUrl);
    germanyAgeGroupsEndpoint = new GermanyAgeGroupsEndpoint(baseUrl);
    // districts
    districtsEndpoint = new DistrictsEndpoint(baseUrl);
    districtsHistoryCasesEndpoint = new DistrictsHistoryCasesEndpoint(baseUrl);
    districtsHistoryDeathsEndpoint = new DistrictsHistoryDeathsEndpoint(baseUrl);
    districtsHistoryFrozenIncidenceEndpoint = new DistrictsHistoryFrozenIncidenceEndpoint(baseUrl);
    districtsHistoryIncidenceEndpoint = new DistrictsHistoryIncidenceEndpoint(baseUrl);
    districtsHistoryRecoveredEndpoint = new DistrictsHistoryRecoveredEndpoint(baseUrl);
    // maps
    mapDistrictsEndpoint = new MapDistrictsEndpoint(baseUrl);
    mapStatesEndpoint = new MapStatesEndpoint(baseUrl);
    mapDistrictsLegendEndpoint = new MapDistrictsLegendEndpoint(baseUrl);
    mapStatesLegendEndpoint = new MapStatesLegendEndpoint(baseUrl);
    // states
    statesAgeGroupsEndpoint = new StatesAgeGroupsEndpoint(baseUrl);
    statesEndpoint = new StatesEndpoint(baseUrl);
    statesHistoryCasesEndpoint = new StatesHistoryCasesEndpoint(baseUrl);
    statesHistoryDeathsEndpoint = new StatesHistoryDeathsEndpoint(baseUrl);
    statesHistoryIncidenceEndpoint = new StatesHistoryIncidenceEndpoint(baseUrl);
    statesHistoryRecoveredEndpoint = new StatesHistoryRecoveredEndpoint(baseUrl);
    // vaccinations
    vaccinationsEndpoint = new VaccinationsEndpoint(baseUrl);
    vaccinationsHistoryEndpoint = new VaccinationsHistoryEndpoint(baseUrl);

    // germany
    QObject::connect(germanyEndpoint, &GermanyEndpoint::signalEndpointFetched, this, &EndpointRetainer::receiveSingleEndpointFetched);
    QObject::connect(germanyHistoryCasesEndpoint, &GermanyHistoryCasesEndpoint::signalEndpointFetched, this, &EndpointRetainer::receiveSingleEndpointFetched);
    QObject::connect(germanyHistoryIncidenceEndpoint, &GermanyHistoryIncidenceEndpoint::signalEndpointFetched, this, &EndpointRetainer::receiveSingleEndpointFetched);
    QObject::connect(germanyHistoryDeathsEndpoint, &GermanyHistoryDeathsEndpoint::signalEndpointFetched, this, &EndpointRetainer::receiveSingleEndpointFetched);
    QObject::connect(germanyHistoryRecoveredEndpoint, &GermanyHistoryRecoveredEndpoint::signalEndpointFetched, this, &EndpointRetainer::receiveSingleEndpointFetched);
    QObject::connect(germanyAgeGroupsEndpoint, &GermanyAgeGroupsEndpoint::signalEndpointFetched, this, &EndpointRetainer::receiveSingleEndpointFetched);
    // districts
    QObject::connect(districtsEndpoint, &DistrictsEndpoint::signalEndpointFetched, this, &EndpointRetainer::receiveSingleEndpointFetched);
    QObject::connect(districtsHistoryCasesEndpoint, &DistrictsHistoryCasesEndpoint::signalEndpointFetched, this, &EndpointRetainer::receiveSingleEndpointFetched);
    QObject::connect(districtsHistoryDeathsEndpoint, &DistrictsHistoryDeathsEndpoint::signalEndpointFetched, this, &EndpointRetainer::receiveSingleEndpointFetched);
    QObject::connect(districtsHistoryFrozenIncidenceEndpoint, &DistrictsHistoryFrozenIncidenceEndpoint::signalEndpointFetched, this, &EndpointRetainer::receiveSingleEndpointFetched);
    QObject::connect(districtsHistoryIncidenceEndpoint, &DistrictsHistoryIncidenceEndpoint::signalEndpointFetched, this, &EndpointRetainer::receiveSingleEndpointFetched);
    QObject::connect(districtsHistoryRecoveredEndpoint, &DistrictsHistoryRecoveredEndpoint::signalEndpointFetched, this, &EndpointRetainer::receiveSingleEndpointFetched);
    // states
    QObject::connect(statesEndpoint, &StatesEndpoint::signalEndpointFetched, this, &EndpointRetainer::receiveSingleEndpointFetched);
    QObject::connect(statesAgeGroupsEndpoint, &StatesAgeGroupsEndpoint::signalEndpointFetched, this, &EndpointRetainer::receiveSingleEndpointFetched);
    QObject::connect(statesHistoryCasesEndpoint, &StatesHistoryCasesEndpoint::signalEndpointFetched, this, &EndpointRetainer::receiveSingleEndpointFetched);
    QObject::connect(statesHistoryDeathsEndpoint, &StatesHistoryDeathsEndpoint::signalEndpointFetched, this, &EndpointRetainer::receiveSingleEndpointFetched);
    QObject::connect(statesHistoryIncidenceEndpoint, &StatesHistoryIncidenceEndpoint::signalEndpointFetched, this, &EndpointRetainer::receiveSingleEndpointFetched);
    QObject::connect(statesHistoryRecoveredEndpoint, &StatesHistoryRecoveredEndpoint::signalEndpointFetched, this, &EndpointRetainer::receiveSingleEndpointFetched);
    // maps
    QObject::connect(mapDistrictsEndpoint, &MapDistrictsEndpoint::signalEndpointFetched, this, &EndpointRetainer::receiveSingleEndpointFetched);
    QObject::connect(mapDistrictsLegendEndpoint, &MapDistrictsLegendEndpoint::signalEndpointFetched, this, &EndpointRetainer::receiveSingleEndpointFetched);
    QObject::connect(mapStatesEndpoint, &MapStatesEndpoint::signalEndpointFetched, this, &EndpointRetainer::receiveSingleEndpointFetched);
    QObject::connect(mapStatesLegendEndpoint, &MapStatesLegendEndpoint::signalEndpointFetched, this, &EndpointRetainer::receiveSingleEndpointFetched);
    // vaccinations
    QObject::connect(vaccinationsEndpoint, &VaccinationsEndpoint::signalEndpointFetched, this, &EndpointRetainer::receiveSingleEndpointFetched);
    QObject::connect(vaccinationsHistoryEndpoint, &VaccinationsHistoryEndpoint::signalEndpointFetched, this, &EndpointRetainer::receiveSingleEndpointFetched);

    emit signalEndpointsReadyToFetchData();
}

/**
 * @brief EndpointRetainer::fetchEndpoints
 * Fetch all endpoints.
 * @param periodicFetch true: periodically fetch endpoints.
 */
void EndpointRetainer::fetchEndpoints(bool periodicFetch)
{
    this->periodicFetchEnabled = periodicFetch;
    if (periodicFetch) {
        fetchEndpointsPeriodic();
    }
    else {
        fetchEndpointsNow();
    }
}

/**
 * @brief EndpointRetainer::disablePeriodicFetch
 * Disable periodic endpoint fetching.
 */
void EndpointRetainer::disablePeriodicFetch()
{
    this->periodicFetchEnabled = false;
}

/**
 * @brief EndpointRetainer::enablePeriodicFetch
 * Enable perioric endpoint fetching.
 */
void EndpointRetainer::enablePeriodicFetch()
{
    this->periodicFetchEnabled = true;
}

/**
 * @brief EndpointRetainer::fetchEndpointsNow
 * Fetch data from server.
 */
void EndpointRetainer::fetchEndpointsNow()
{
    qDebug() << "---------------- fetch endpoints now!";
    // get germany endpoints
    germanyEndpoint->get();
    germanyHistoryCasesEndpoint->get();
    germanyHistoryIncidenceEndpoint->get();
    germanyHistoryDeathsEndpoint->get();
    germanyHistoryRecoveredEndpoint->get();
    germanyAgeGroupsEndpoint->get();

    // check for external interrupt request -> exit thread
    if(QThread::currentThread()->isInterruptionRequested()) {
        return;
    }

    // get district endpoints
    districtsEndpoint->get();
    districtsHistoryCasesEndpoint->get();
    districtsHistoryDeathsEndpoint->get();
    districtsHistoryFrozenIncidenceEndpoint->get();
    districtsHistoryIncidenceEndpoint->get();
    districtsHistoryRecoveredEndpoint->get();

    // check for external interrupt request -> exit thread
    if(QThread::currentThread()->isInterruptionRequested()) {
        return;
    }

    // get maps
    mapDistrictsEndpoint->get();
    mapStatesEndpoint->get();
    mapDistrictsLegendEndpoint->get();
    mapStatesLegendEndpoint->get();

    // check for external interrupt request -> exit thread
    if(QThread::currentThread()->isInterruptionRequested()) {
        return;
    }

    // get states
    statesEndpoint->get();
    statesAgeGroupsEndpoint->get();
    statesHistoryCasesEndpoint->get();
    statesHistoryDeathsEndpoint->get();
    statesHistoryIncidenceEndpoint->get();
    statesHistoryRecoveredEndpoint->get();

    // check for external interrupt request -> exit thread
    if(QThread::currentThread()->isInterruptionRequested()) {
        return;
    }

    // get vaccinations
    vaccinationsEndpoint->get();
    vaccinationsHistoryEndpoint->get();
}

/**
 * @brief EndpointRetainer::fetchEndpointsPeriodic
 * Fetch endpoints periodically.
 */
void EndpointRetainer::fetchEndpointsPeriodic()
{
    periodicFetchTimerEnabled = false;
    fetchEndpointsNow();

    if (this->periodicFetchEnabled && !periodicFetchTimerEnabled) {
        // 1800000 ms = 30min
        // 14400000 ms = 4h
        qDebug() << "----set new fetch timer!!!";
        periodicFetchTimerEnabled = true;
        QTimer::singleShot(14400000, this, &EndpointRetainer::fetchEndpointsNow);
    }
}

/**
 * @brief EndpointRetainer::receiveInitEndpointsSignal
 * Receive signal that requests the initialization of all endpoint objects.
 */
void EndpointRetainer::receiveInitEndpointsSignal()
{
    initEndpoints();
}

/**
 * @brief EndpointRetainer::receiveFetchEndpointsDataSignal
 * Receive signal that requests to fetch all data from the endpoints.
 */
void EndpointRetainer::receiveFetchEndpointsDataSignal()
{
    fetchEndpointsNow();
}

/**
 * @brief EndpointRetainer::receiveSingleEndpointFetched
 * Receive signal that a single endpoint has been fetched.
 */
void EndpointRetainer::receiveSingleEndpointFetched()
{
    endpointsFetched++;
    qDebug() << endpointsFetched;
    if(endpointsFetched >= NUM_OF_ENDPOINTS) {
        qDebug() << "AllDataFetched!";
        emit signalAllDataFetched();
    }
}
