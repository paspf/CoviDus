#include "endpointdataretainer.h"

/**
 * @brief EndpointDataRetainer::EndpointDataRetainer
 * Create EndpointDataRetainer.
 */
EndpointDataRetainer::EndpointDataRetainer() :
    germanyEndpointData(),
    germanyAgeGroupsEndpointData(),
    germanyHistoryCasesEndpointData(),
    germanyHistoryDeathsEndpointData(),
    germanyHistoryIncidenceEndpointData(),
    germanyHistoryRecoveredEndpointData(),
    districtsEndpointData(),
    districtsHistoryCasesEndpointData(),
    districtsHistoryDeathsEndpointData(),
    districtsHistoryFrozenIncidenceEndpointData(),
    districtsHistoryIncidenceEndpointData(),
    districtsHistoryRecoveredEndpointData(),
    statesEndpointData(),
    statesAgeGroupsEndpointData(),
    statesHistoryCasesEndpointData(),
    statesHistoryDeathsEndpointData(),
    statesHistoryIncidenceEndpointData(),
    statesHistoryRecoveredEndpointData()
{

}

/**
 * @brief EndpointDataRetainer::setGermanyEndpointData
 * Set the data of an endpoint an emit a signal.
 * @param data Pointer to the data object, that will be copied.
 */
void EndpointDataRetainer::setGermanyEndpointData(GermanyEndpointData *data)
{
    this->germanyEndpointData = *data;
    delete data;
    emit this->signalGermanyEndpointData(&germanyEndpointData);
}

/**
 * @brief EndpointDataRetainer::setGermanyAgeGroupsEndpointData
 * Set the data of an endpoint an emit a signal.
 * @param data Pointer to the data object, that will be copied.
 */
void EndpointDataRetainer::setGermanyAgeGroupsEndpointData(GermanyAgeGroupsEndpointData *data)
{
    this->germanyAgeGroupsEndpointData = *data;
    delete data;
    emit this->signalGermanyAgeGroupsEndpointData(&germanyAgeGroupsEndpointData);
}

/**
 * @brief EndpointDataRetainer::setGermanyHistoryCasesEndpointData
 * Set the data of an endpoint an emit a signal.
 * @param data Pointer to the data object, that will be copied.
 */
void EndpointDataRetainer::setGermanyHistoryCasesEndpointData(GermanyHistoryCasesEndpointData *data)
{
    this->germanyHistoryCasesEndpointData = *data;
    delete data;
    emit this->signalGermanyHistoryCasesEndpointData(&germanyHistoryCasesEndpointData);
}

/**
 * @brief EndpointDataRetainer::setGermanyHistoryDeathsEndpointData
 * Set the data of an endpoint an emit a signal.
 * @param data Pointer to the data object, that will be copied.
 */
void EndpointDataRetainer::setGermanyHistoryDeathsEndpointData(GermanyHistoryDeathsEndpointData *data)
{
    this->germanyHistoryDeathsEndpointData = *data;
    delete data;
    emit this->signalGermanyHistoryDeathsEndpointData(&germanyHistoryDeathsEndpointData);
}

/**
 * @brief EndpointDataRetainer::setGermanyHistoryIncidenceEndpointData
 * Set the data of an endpoint an emit a signal.
 * @param data Pointer to the data object, that will be copied.
 */
void EndpointDataRetainer::setGermanyHistoryIncidenceEndpointData(GermanyHistoryIncidenceEndpointData *data)
{
    this->germanyHistoryIncidenceEndpointData = *data;
    delete data;
    emit this->signalGermanyHistoryIncidenceEndpointData(&germanyHistoryIncidenceEndpointData);
}

/**
 * @brief EndpointDataRetainer::setGermanyHistoryRecoveredEndpointData
 * Set the data of an endpoint an emit a signal.
 * @param data Pointer to the data object, that will be copied.
 */
void EndpointDataRetainer::setGermanyHistoryRecoveredEndpointData(GermanyHistoryRecoveredEndpointData *data)
{
    this->germanyHistoryRecoveredEndpointData = *data;
    delete data;
    emit this->signalGermanyHistoryRecoveredEndpointData(&germanyHistoryRecoveredEndpointData);
}

/**
 * @brief EndpointDataRetainer::getGermanyEndpointData
 * @return Reference to stored endpoint data.
 */
GermanyEndpointData &EndpointDataRetainer::getGermanyEndpointData()
{
    return this->germanyEndpointData;
}

/**
 * @brief EndpointDataRetainer::getGermanyAgeGroupsEndpointData
 * @return Reference to stored endpoint data.
 */
GermanyAgeGroupsEndpointData &EndpointDataRetainer::getGermanyAgeGroupsEndpointData()
{
    return this->germanyAgeGroupsEndpointData;
}

/**
 * @brief EndpointDataRetainer::getGermanyHistoryCasesEndpointData
 * @return Reference to stored endpoint data.
 */
GermanyHistoryCasesEndpointData &EndpointDataRetainer::getGermanyHistoryCasesEndpointData()
{
    return this->germanyHistoryCasesEndpointData;
}

/**
 * @brief EndpointDataRetainer::getGermanyHistoryDeathsEndpointData
 * @return Reference to stored endpoint data.
 */
GermanyHistoryDeathsEndpointData &EndpointDataRetainer::getGermanyHistoryDeathsEndpointData()
{
    return this->germanyHistoryDeathsEndpointData;
}

/**
 * @brief EndpointDataRetainer::getGermanyHistoryIncidenceEndpointData
 * @return Reference to stored endpoint data.
 */
GermanyHistoryIncidenceEndpointData &EndpointDataRetainer::getGermanyHistoryIncidenceEndpointData()
{
    return this->germanyHistoryIncidenceEndpointData;
}

/**
 * @brief EndpointDataRetainer::getGermanyHistoryRecoveredEndpointData
 * @return Reference to stored endpoint data.
 */
GermanyHistoryRecoveredEndpointData &EndpointDataRetainer::getGermanyHistoryRecoveredEndpointData()
{
    return this->germanyHistoryRecoveredEndpointData;
}

/**
 * @brief EndpointDataRetainer::setDistrictsEndpointData
 * Set the data of an endpoint an emit a signal.
 * @param data Pointer to the data object, that will be copied.
 */
void EndpointDataRetainer::setDistrictsEndpointData(DistrictsEndpointData *data)
{
    this->districtsEndpointData = *data;
    delete data;
    emit this->signalDistrictsEndpointData(&districtsEndpointData);
}

/**
 * @brief EndpointDataRetainer::setDistrictsHistoryCasesEndpointData
 * Set the data of an endpoint an emit a signal.
 * @param data Pointer to the data object, that will be copied.
 */
void EndpointDataRetainer::setDistrictsHistoryCasesEndpointData(DistrictsHistoryCasesEndpointData *data)
{
    this->districtsHistoryCasesEndpointData = *data;
    delete data;
    emit this->signalDistrictsHistoryCasesEndpointData(&districtsHistoryCasesEndpointData);
}

/**
 * @brief EndpointDataRetainer::setDistrictsHistoryDeathsEndpointData
 * @param data Pointer to the data object, that will be copied.
 */
void EndpointDataRetainer::setDistrictsHistoryDeathsEndpointData(DistrictsHistoryDeathsEndpointData *data)
{
    this->districtsHistoryDeathsEndpointData = *data;
    delete data;
    emit this->signalDistrictsHistoryDeathsEndpointData(&districtsHistoryDeathsEndpointData);
}

/**
 * @brief EndpointDataRetainer::setDistrictsHistoryFrozenIncidenceEndpointData
 * Set the data of an endpoint an emit a signal.
 * @param data Pointer to the data object, that will be copied.
 */
void EndpointDataRetainer::setDistrictsHistoryFrozenIncidenceEndpointData(DistrictsHistoryFrozenIncidenceEndpointData *data)
{
    this->districtsHistoryFrozenIncidenceEndpointData = *data;
    delete data;
    emit this->signalDistrictsHistoryFrozenIncidenceEndpointData(&districtsHistoryFrozenIncidenceEndpointData);
}

/**
 * @brief EndpointDataRetainer::setDistrictsHistoryIncidenceEndpointData
 * Set the data of an endpoint an emit a signal.
 * @param data Pointer to the data object, that will be copied.
 */
void EndpointDataRetainer::setDistrictsHistoryIncidenceEndpointData(DistrictsHistoryIncidenceEndpointData *data)
{
    this->districtsHistoryIncidenceEndpointData = *data;
    delete data;
    emit this->signalDistrictsHistoryIncidenceEndpointData(&districtsHistoryIncidenceEndpointData);
}

/**
 * @brief EndpointDataRetainer::setDistrictsHistoryRecoveredEndpointData
 * Set the data of an endpoint an emit a signal.
 * @param data Pointer to the data object, that will be copied.
 */
void EndpointDataRetainer::setDistrictsHistoryRecoveredEndpointData(DistrictsHistoryRecoveredEndpointData *data)
{
    this->districtsHistoryRecoveredEndpointData = *data;
    delete data;
    emit this->signalDistrictsHistoryRecoveredEndpointData(&districtsHistoryRecoveredEndpointData);
}

/**
 * @brief EndpointDataRetainer::getDistrictsEndpointData
 * @return Reference to stored endpoint data.
 */
DistrictsEndpointData &EndpointDataRetainer::getDistrictsEndpointData()
{
    return this->districtsEndpointData;
}

/**
 * @brief EndpointDataRetainer::getDistrictsHistoryCasesEndpointData
 * @return Reference to stored endpoint data.
 */
DistrictsHistoryCasesEndpointData &EndpointDataRetainer::getDistrictsHistoryCasesEndpointData()
{
    return this->districtsHistoryCasesEndpointData;
}

/**
 * @brief EndpointDataRetainer::getDistrictsHistoryDeathsEndpointData
 * @return Reference to stored endpoint data.
 */
DistrictsHistoryDeathsEndpointData &EndpointDataRetainer::getDistrictsHistoryDeathsEndpointData()
{
    return this->districtsHistoryDeathsEndpointData;
}

/**
 * @brief EndpointDataRetainer::getDistrictsHistoryFrozenIncidenceEndpointData
 * @return Reference to stored endpoint data.
 */
DistrictsHistoryFrozenIncidenceEndpointData &EndpointDataRetainer::getDistrictsHistoryFrozenIncidenceEndpointData()
{
    return this->districtsHistoryFrozenIncidenceEndpointData;
}

/**
 * @brief EndpointDataRetainer::getDistrictsHistoryIncidenceEndpointData
 * @return Reference to stored endpoint data.
 */
DistrictsHistoryIncidenceEndpointData &EndpointDataRetainer::getDistrictsHistoryIncidenceEndpointData()
{
    return this->districtsHistoryIncidenceEndpointData;
}

/**
 * @brief EndpointDataRetainer::getDistrictsHistoryRecoveredEndpointData
 * @return Reference to stored endpoint data.
 */
DistrictsHistoryRecoveredEndpointData &EndpointDataRetainer::getDistrictsHistoryRecoveredEndpointData()
{
    return this->districtsHistoryRecoveredEndpointData;
}

/**
 * @brief EndpointDataRetainer::setStatesEndpointData
 * Set the data of an endpoint an emit a signal.
 * @param data Pointer to the data object, that will be copied.
 */
void EndpointDataRetainer::setStatesEndpointData(StatesEndpointData *data)
{
    this->statesEndpointData = *data;
    delete data;
    emit this->signalStatesEndpointData(&statesEndpointData);
}

/**
 * @brief EndpointDataRetainer::setStatesAgeGroupsEndpointData
 * Set the data of an endpoint an emit a signal.
 * @param data
 */
void EndpointDataRetainer::setStatesAgeGroupsEndpointData(StatesAgeGroupsEndpointData *data)
{
    this->statesAgeGroupsEndpointData = *data;
    delete data;
    emit this->signalStatesAgeGroupsEndpointData(&statesAgeGroupsEndpointData);
}

/**
 * @brief EndpointDataRetainer::setStatesHistoryCasesEndpointData
 * Set the data of an endpoint an emit a signal.
 * @param data Pointer to the data object, that will be copied.
 */
void EndpointDataRetainer::setStatesHistoryCasesEndpointData(StatesHistoryCasesEndpointData *data)
{
    this->statesHistoryCasesEndpointData = *data;
    delete data;
    emit this->signalStatesHistoryCasesEndpointData(&statesHistoryCasesEndpointData);
}

/**
 * @brief EndpointDataRetainer::setStatesHistoryDeathsEndpointData
 * Set the data of an endpoint an emit a signal.
 * @param data Pointer to the data object, that will be copied.
 */
void EndpointDataRetainer::setStatesHistoryDeathsEndpointData(StatesHistoryDeathsEndpointData *data)
{
    this->statesHistoryDeathsEndpointData = *data;
    delete data;
    emit this->signalStatesHistoryDeathsEndpointData(&statesHistoryDeathsEndpointData);
}

/**
 * @brief EndpointDataRetainer::setStatesHistoryIncidenceEndpointData
 * Set the data of an endpoint an emit a signal.
 * @param data Pointer to the data object, that will be copied.
 */
void EndpointDataRetainer::setStatesHistoryIncidenceEndpointData(StatesHistoryIncidenceEndpointData *data)
{
    this->statesHistoryIncidenceEndpointData = *data;
    delete data;
    emit this->signalStatesHistoryIncidenceEndpointData(&statesHistoryIncidenceEndpointData);
}

/**
 * @brief EndpointDataRetainer::setStatesHistoryRecoveredEndpointData
 * Set the data of an endpoint an emit a signal.
 * @param data Pointer to the data object, that will be copied.
 */
void EndpointDataRetainer::setStatesHistoryRecoveredEndpointData(StatesHistoryRecoveredEndpointData *data)
{
    this->statesHistoryRecoveredEndpointData = *data;
    delete data;
    emit this->signalStatesHistoryRecoveredEndpointData(&statesHistoryRecoveredEndpointData);
}

/**
 * @brief EndpointDataRetainer::getStatesEndpointData
 * @return Reference to stored endpoint data.
 */
StatesEndpointData &EndpointDataRetainer::getStatesEndpointData()
{
    return this->statesEndpointData;
}

/**
 * @brief EndpointDataRetainer::getStatesAgeGroupsEndpointData
 * @return Reference to stored endpoint data.
 */
StatesAgeGroupsEndpointData &EndpointDataRetainer::getStatesAgeGroupsEndpointData()
{
    return this->statesAgeGroupsEndpointData;
}

/**
 * @brief EndpointDataRetainer::getStatesHistoryCasesEndpointData
 * @return Reference to stored endpoint data.
 */
StatesHistoryCasesEndpointData &EndpointDataRetainer::getStatesHistoryCasesEndpointData()
{
    return this->statesHistoryCasesEndpointData;
}

/**
 * @brief EndpointDataRetainer::getStatesHistoryDeathsEndpointData
 * @return Reference to stored endpoint data.
 */
StatesHistoryDeathsEndpointData &EndpointDataRetainer::getStatesHistoryDeathsEndpointData()
{
    return this->statesHistoryDeathsEndpointData;
}

/**
 * @brief EndpointDataRetainer::getStatesHistoryIncidenceEndpointData
 * @return Reference to stored endpoint data.
 */
StatesHistoryIncidenceEndpointData &EndpointDataRetainer::getStatesHistoryIncidenceEndpointData()
{
    return this->statesHistoryIncidenceEndpointData;
}

/**
 * @brief EndpointDataRetainer::getStatesHistoryRecoveredEndpointData
 * @return Reference to stored endpoint data.
 */
StatesHistoryRecoveredEndpointData &EndpointDataRetainer::getStatesHistoryRecoveredEndpointData()
{
    return this->statesHistoryRecoveredEndpointData;
}

/**
 * @brief EndpointDataRetainer::setMapDistrictsEndpoint
 * Set the data of an endpoint an emit a signal.
 * @param image Pointer to the image object, that will be copied.
 */
void EndpointDataRetainer::setMapDistrictsEndpoint(QImage *image)
{
    this->mapDistrictsEndpoint = *image;
    delete image;
    emit this->signalMapDistrictsEndpoint(&mapDistrictsEndpoint);
}

/**
 * @brief EndpointDataRetainer::setMapDistrictsLegendEndpoint
 * Set the data of an endpoint an emit a signal.
 * @param statesInfo
 */
void EndpointDataRetainer::setMapDistrictsLegendEndpoint(QVector<LegendInfo> *statesInfo)
{
    this->mapDistricsLegendEndpoint = *statesInfo;
    delete statesInfo;
    emit this->signalMapDistrictsLegendEndpoint(&mapDistricsLegendEndpoint);
}

/**
 * @brief EndpointDataRetainer::setMapStatesEndpoint
 * Set the data of an endpoint an emit a signal.
 * @param image
 */
void EndpointDataRetainer::setMapStatesEndpoint(QImage *image)
{
    this->mapStatesEndpoint = *image;
    delete image;
    emit this->signalMapStatesEndpoint(&mapStatesEndpoint);
}

/**
 * @brief EndpointDataRetainer::setMapStatesLegendEndpoint
 * Set the data of an endpoint an emit a signal.
 * @param statesInfo Pointer to the data object, that will be copied.
 */
void EndpointDataRetainer::setMapStatesLegendEndpoint(QVector<LegendInfo> *statesInfo)
{
    this->mapStatesLegendEndpoint = *statesInfo;
    delete statesInfo;
    emit this->signalMapStatesLegendEndpoint(&mapStatesLegendEndpoint);
}

/**
 * @brief EndpointDataRetainer::getMapDistrictsEndpoint
 * @return Reference to stored endpoint data.
 */
QImage &EndpointDataRetainer::getMapDistrictsEndpoint()
{
    return this->mapDistrictsEndpoint;
}

/**
 * @brief EndpointDataRetainer::getMapDistrictsLegendEndpoint
 * @return Reference to stored endpoint data.
 */
QVector<LegendInfo> &EndpointDataRetainer::getMapDistrictsLegendEndpoint()
{
    return this->mapDistricsLegendEndpoint;
}

/**
 * @brief EndpointDataRetainer::getMapStatesEndpoint
 * @return Reference to stored endpoint data.
 */
QImage &EndpointDataRetainer::getMapStatesEndpoint()
{
    return this->mapStatesEndpoint;
}

/**
 * @brief EndpointDataRetainer::getMapStatesLegendEndpoint
 * @return Reference to stored endpoint data.
 */
QVector<LegendInfo> &EndpointDataRetainer::getMapStatesLegendEndpoint()
{
    return this->mapStatesLegendEndpoint;
}

/**
 * @brief EndpointDataRetainer::setVaccinationsEndpointData
 * Set the data of an endpoint an emit a signal.
 * @param data Pointer to the data object, that will be copied.
 */
void EndpointDataRetainer::setVaccinationsEndpointData(VaccinationsEndpointData *data)
{
    this->vaccinationsEndpointData = *data;
    delete data;
    emit this->signalVaccinationsEndpointData(&vaccinationsEndpointData);
}

/**
 * @brief EndpointDataRetainer::setVaccinationsHistoryEndpointData
 * Set the data of an endpoint an emit a signal.
 * @param data Pointer to the data object, that will be copied.
 */
void EndpointDataRetainer::setVaccinationsHistoryEndpointData(VaccinationsHistoryEndpointData *data)
{
    this->vaccinationsHistoryEndpointData = *data;
    delete data;
    emit this->signalVaccinationsHistoryEndpointData(&vaccinationsHistoryEndpointData);
}

/**
 * @brief EndpointDataRetainer::getVaccinationsEndpointData
 * @return Reference to stored endpoint data.
 */
VaccinationsEndpointData &EndpointDataRetainer::getVaccinationsEndpointData()
{
    return this->vaccinationsEndpointData;
}

/**
 * @brief EndpointDataRetainer::getVaccinationsHistoryEndpointData
 * @return Reference to stored endpoint data.
 */
VaccinationsHistoryEndpointData &EndpointDataRetainer::getVaccinationsHistoryEndpointData()
{
    return this->vaccinationsHistoryEndpointData;
}

/**
 * @brief EndpointDataRetainer::receiveGermanyEndpointData
 * Slot. Calls specific setter, setter emits signal.
 * @param data Pointer to the data object, that will be copied.
 */
void EndpointDataRetainer::receiveGermanyEndpointData(GermanyEndpointData *data)
{
    this->setGermanyEndpointData(data);
}

/**
 * @brief EndpointDataRetainer::receiveGermanyAgeGroupsEndpointData
 * Slot. Calls specific setter, setter emits signal.
 * @param data Pointer to the data object, that will be copied.
 */
void EndpointDataRetainer::receiveGermanyAgeGroupsEndpointData(GermanyAgeGroupsEndpointData *data)
{
    this->setGermanyAgeGroupsEndpointData(data);
}

/**
 * @brief EndpointDataRetainer::receiveGermanyHistoryCasesEndpointData
 * Slot. Calls specific setter, setter emits signal.
 * @param data Pointer to the data object, that will be copied.
 */
void EndpointDataRetainer::receiveGermanyHistoryCasesEndpointData(GermanyHistoryCasesEndpointData *data)
{
    this->setGermanyHistoryCasesEndpointData(data);
}

/**
 * @brief EndpointDataRetainer::receiveGermanyHistoryDeathsEndpointData
 * Slot. Calls specific setter, setter emits signal.
 * @param data Pointer to the data object, that will be copied.
 */
void EndpointDataRetainer::receiveGermanyHistoryDeathsEndpointData(GermanyHistoryDeathsEndpointData *data)
{
    this->setGermanyHistoryDeathsEndpointData(data);
}

/**
 * @brief EndpointDataRetainer::receiveGermanyHistoryIncidenceEndpointData
 * Slot. Calls specific setter, setter emits signal.
 * @param data Pointer to the data object, that will be copied.
 */
void EndpointDataRetainer::receiveGermanyHistoryIncidenceEndpointData(GermanyHistoryIncidenceEndpointData *data)
{
    this->setGermanyHistoryIncidenceEndpointData(data);
}

/**
 * @brief EndpointDataRetainer::receiveGermanyHistoryRecoveredEndpointData
 * Slot. Calls specific setter, setter emits signal.
 * @param data Pointer to the data object, that will be copied.
 */
void EndpointDataRetainer::receiveGermanyHistoryRecoveredEndpointData(GermanyHistoryRecoveredEndpointData *data)
{
    this->setGermanyHistoryRecoveredEndpointData(data);
}

/**
 * @brief EndpointDataRetainer::receiveDistrictsEndpointData
 * Slot. Calls specific setter, setter emits signal.
 * @param data Pointer to the data object, that will be copied.
 */
void EndpointDataRetainer::receiveDistrictsEndpointData(DistrictsEndpointData *data)
{
    this->setDistrictsEndpointData(data);
}

/**
 * @brief EndpointDataRetainer::receiveDistrictsHistoryCasesEndpointData
 * Slot. Calls specific setter, setter emits signal.
 * @param data Pointer to the data object, that will be copied.
 */
void EndpointDataRetainer::receiveDistrictsHistoryCasesEndpointData(DistrictsHistoryCasesEndpointData *data)
{
    this->setDistrictsHistoryCasesEndpointData(data);
}

/**
 * @brief EndpointDataRetainer::receiveDistrictsHistoryDeathsEndpointData
 * Slot. Calls specific setter, setter emits signal.
 * @param data Pointer to the data object, that will be copied.
 */
void EndpointDataRetainer::receiveDistrictsHistoryDeathsEndpointData(DistrictsHistoryDeathsEndpointData *data)
{
    this->setDistrictsHistoryDeathsEndpointData(data);
}

/**
 * @brief EndpointDataRetainer::receiveDistrictsHistoryFrozenIncidenceEndpointData
 * Slot. Calls specific setter, setter emits signal.
 * @param data Pointer to the data object, that will be copied.
 */
void EndpointDataRetainer::receiveDistrictsHistoryFrozenIncidenceEndpointData(DistrictsHistoryFrozenIncidenceEndpointData *data)
{
    this->setDistrictsHistoryFrozenIncidenceEndpointData(data);
}

/**
 * @brief EndpointDataRetainer::receiveDistrictsHistoryIncidenceEndpointData
 * Slot. Calls specific setter, setter emits signal.
 * @param data
 */
void EndpointDataRetainer::receiveDistrictsHistoryIncidenceEndpointData(DistrictsHistoryIncidenceEndpointData *data)
{
    this->setDistrictsHistoryIncidenceEndpointData(data);
}

/**
 * @brief EndpointDataRetainer::receiveDistrictsHistoryRecoveredEndpointData
 * Slot. Calls specific setter, setter emits signal.
 * @param data Pointer to the data object, that will be copied.
 */
void EndpointDataRetainer::receiveDistrictsHistoryRecoveredEndpointData(DistrictsHistoryRecoveredEndpointData *data)
{
    this->setDistrictsHistoryRecoveredEndpointData(data);
}

/**
 * @brief EndpointDataRetainer::receiveStatesEndpointData
 * Slot. Calls specific setter, setter emits signal.
 * @param data Pointer to the data object, that will be copied.
 */
void EndpointDataRetainer::receiveStatesEndpointData(StatesEndpointData *data)
{
    this->setStatesEndpointData(data);
}

/**
 * @brief EndpointDataRetainer::receiveStatesAgeGroupsEndpointData
 * Slot. Calls specific setter, setter emits signal.
 * @param data Pointer to the data object, that will be copied.
 */
void EndpointDataRetainer::receiveStatesAgeGroupsEndpointData(StatesAgeGroupsEndpointData *data)
{
    this->setStatesAgeGroupsEndpointData(data);
}

/**
 * @brief EndpointDataRetainer::receiveStatesHistoryCasesEndpointData
 * Slot. Calls specific setter, setter emits signal.
 * @param data Pointer to the data object, that will be copied.
 */
void EndpointDataRetainer::receiveStatesHistoryCasesEndpointData(StatesHistoryCasesEndpointData *data)
{
    this->setStatesHistoryCasesEndpointData(data);
}

/**
 * @brief EndpointDataRetainer::receiveStatesHistoryDeathsEndpointData
 * Slot. Calls specific setter, setter emits signal.
 * @param data Pointer to the data object, that will be copied.
 */
void EndpointDataRetainer::receiveStatesHistoryDeathsEndpointData(StatesHistoryDeathsEndpointData *data)
{
    this->setStatesHistoryDeathsEndpointData(data);
}

/**
 * @brief EndpointDataRetainer::receiveStatesHistoryIncidenceEndpointData
 * Slot. Calls specific setter, setter emits signal.
 * @param data Pointer to the data object, that will be copied.
 */
void EndpointDataRetainer::receiveStatesHistoryIncidenceEndpointData(StatesHistoryIncidenceEndpointData *data)
{
    this->setStatesHistoryIncidenceEndpointData(data);
}

/**
 * @brief EndpointDataRetainer::receiveStatesHistoryRecoveredEndpointData
 * Slot. Calls specific setter, setter emits signal.
 * @param data Pointer to the data object, that will be copied.
 */
void EndpointDataRetainer::receiveStatesHistoryRecoveredEndpointData(StatesHistoryRecoveredEndpointData *data)
{
    this->setStatesHistoryRecoveredEndpointData(data);
}

/**
 * @brief EndpointDataRetainer::receiveMapDistrictsEndpoint
 * Slot. Calls specific setter, setter emits signal.
 * @param image Pointer to the data object, that will be copied.
 */
void EndpointDataRetainer::receiveMapDistrictsEndpoint(QImage *image)
{
    this->setMapDistrictsEndpoint(image);
}

/**
 * @brief EndpointDataRetainer::receiveMapDistrictsLegendEndpoint
 * Slot. Calls specific setter, setter emits signal.
 * @param statesInfo Pointer to the data object, that will be copied.
 */
void EndpointDataRetainer::receiveMapDistrictsLegendEndpoint(QVector<LegendInfo> *statesInfo)
{
    this->setMapDistrictsLegendEndpoint(statesInfo);
}

/**
 * @brief EndpointDataRetainer::receiveMapStatesEndpoint
 * Slot. Calls specific setter, setter emits signal.
 * @param image Pointer to the image object, that will be copied.
 */
void EndpointDataRetainer::receiveMapStatesEndpoint(QImage *image)
{
    this->setMapStatesEndpoint(image);
}

/**
 * @brief EndpointDataRetainer::receiveMapStatesLegendEndpoint
 * Slot. Calls specific setter, setter emits signal.
 * @param statesInfo Pointer to the data object, that will be copied.
 */
void EndpointDataRetainer::receiveMapStatesLegendEndpoint(QVector<LegendInfo> *statesInfo)
{
    this->setMapStatesLegendEndpoint(statesInfo);
}

/**
 * @brief EndpointDataRetainer::receiveVaccinationsEndpointData
 * Slot. Calls specific setter, setter emits signal.
 * @param data Pointer to the data object, that will be copied.
 */
void EndpointDataRetainer::receiveVaccinationsEndpointData(VaccinationsEndpointData *data)
{
    this->setVaccinationsEndpointData(data);
}

/**
 * @brief EndpointDataRetainer::receiveVaccinationsHistoryEndpointData
 * Slot. Calls specific setter, setter emits signal.
 * @param data Pointer to the data object, that will be copied.
 */
void EndpointDataRetainer::receiveVaccinationsHistoryEndpointData(VaccinationsHistoryEndpointData *data)
{
    this->setVaccinationsHistoryEndpointData(data);
}

/**
 * @brief operator <<
 * Shift data from an EndpointDataRetainer object into an QDataStream object.
 * @param out QDataStream to use.
 * @param data Reference to EndpointDataRetainer.
 * @return A QDataStream.
 */
QDataStream &operator<<(QDataStream &out, const EndpointDataRetainer &data)
{
        // Germany
    out << data.germanyEndpointData
        << data.germanyAgeGroupsEndpointData
        << data.germanyHistoryCasesEndpointData
        << data.germanyHistoryDeathsEndpointData
        << data.germanyHistoryIncidenceEndpointData
        << data.germanyHistoryRecoveredEndpointData
        // Districts
        << data.districtsEndpointData
        << data.districtsHistoryCasesEndpointData
        << data.districtsHistoryDeathsEndpointData
        << data.districtsHistoryFrozenIncidenceEndpointData
        << data.districtsHistoryIncidenceEndpointData
        << data.districtsHistoryRecoveredEndpointData
        // States
        << data.statesEndpointData
        << data.statesAgeGroupsEndpointData
        << data.statesHistoryCasesEndpointData
        << data.statesHistoryDeathsEndpointData
        << data.statesHistoryIncidenceEndpointData
        << data.statesHistoryRecoveredEndpointData
        // Maps
        << data.mapDistrictsEndpoint
        << data.mapDistricsLegendEndpoint
        << data.mapStatesEndpoint
        << data.mapStatesLegendEndpoint
        // Vaccinations
        << data.vaccinationsEndpointData
        << data.vaccinationsHistoryEndpointData;
    return out;
}

/**
 * @brief operator >>
 * Shift data from a QDataStream object into an EndpointDataRetainer object.
 * @param in QDataStream to use.
 * @param data Reference to EndpointDataRetainer.
 * @return
 */
QDataStream &operator>>(QDataStream &in, EndpointDataRetainer &data)
{
    // Germany
    GermanyEndpointData *germanyEndpointData = new GermanyEndpointData();
    GermanyAgeGroupsEndpointData *germanyAgeGroupsEndpointData = new GermanyAgeGroupsEndpointData();
    GermanyHistoryCasesEndpointData *germanyHistoryCasesEndpointData = new GermanyHistoryCasesEndpointData();
    GermanyHistoryDeathsEndpointData *germanyHistoryDeathsEndpointData = new GermanyHistoryDeathsEndpointData();
    GermanyHistoryIncidenceEndpointData *germanyHistoryIncidenceEndpointData = new GermanyHistoryIncidenceEndpointData();
    GermanyHistoryRecoveredEndpointData *germanyHistoryRecoveredEndpointData = new GermanyHistoryRecoveredEndpointData();

    // Districts
    DistrictsEndpointData *districtsEndpointData = new DistrictsEndpointData();
    DistrictsHistoryCasesEndpointData *districtsHistoryCasesEndpointData = new DistrictsHistoryCasesEndpointData();
    DistrictsHistoryDeathsEndpointData *districtsHistoryDeathsEndpointData = new DistrictsHistoryDeathsEndpointData();
    DistrictsHistoryFrozenIncidenceEndpointData *districtsHistoryFrozenIncidenceEndpointData = new DistrictsHistoryFrozenIncidenceEndpointData();
    DistrictsHistoryIncidenceEndpointData *districtsHistoryIncidenceEndpointData = new DistrictsHistoryIncidenceEndpointData();
    DistrictsHistoryRecoveredEndpointData *districtsHistoryRecoveredEndpointData = new DistrictsHistoryRecoveredEndpointData();

    // States
    StatesEndpointData *statesEndpointData = new StatesEndpointData();
    StatesAgeGroupsEndpointData *statesAgeGroupsEndpointData = new StatesAgeGroupsEndpointData();
    StatesHistoryCasesEndpointData *statesHistoryCasesEndpointData = new StatesHistoryCasesEndpointData();
    StatesHistoryDeathsEndpointData *statesHistoryDeathsEndpointData = new StatesHistoryDeathsEndpointData();
    StatesHistoryIncidenceEndpointData *statesHistoryIncidenceEndpointData = new StatesHistoryIncidenceEndpointData();
    StatesHistoryRecoveredEndpointData *statesHistoryRecoveredEndpointData = new StatesHistoryRecoveredEndpointData();

    // Maps
    QImage *mapDistrictsEndpoint = new QImage();
    QList<LegendInfo> *mapDistricsLegendEndpoint = new QList<LegendInfo>();
    QImage *mapStatesEndpoint = new QImage();
    QList<LegendInfo> *mapStatesLegendEndpoint = new QList<LegendInfo>();

    // Vaccinations
    VaccinationsEndpointData *vaccinationsEndpointData = new VaccinationsEndpointData();
    VaccinationsHistoryEndpointData *vaccinationsHistoryEndpointData = new VaccinationsHistoryEndpointData();

        // Germany
    in >> *germanyEndpointData
       >> *germanyAgeGroupsEndpointData
       >> *germanyHistoryCasesEndpointData
       >> *germanyHistoryDeathsEndpointData
       >> *germanyHistoryIncidenceEndpointData
       >> *germanyHistoryRecoveredEndpointData
       // Districts
       >> *districtsEndpointData
       >> *districtsHistoryCasesEndpointData
       >> *districtsHistoryDeathsEndpointData
       >> *districtsHistoryFrozenIncidenceEndpointData
       >> *districtsHistoryIncidenceEndpointData
       >> *districtsHistoryRecoveredEndpointData
       // States
       >> *statesEndpointData
       >> *statesAgeGroupsEndpointData
       >> *statesHistoryCasesEndpointData
       >> *statesHistoryDeathsEndpointData
       >> *statesHistoryIncidenceEndpointData
       >> *statesHistoryRecoveredEndpointData
       // Maps
       >> *mapDistrictsEndpoint
       >> *mapDistricsLegendEndpoint
       >> *mapStatesEndpoint
       >> *mapStatesLegendEndpoint
       // Vaccinations
       >> *vaccinationsEndpointData
       >> *vaccinationsHistoryEndpointData;

    // Germany
    data.setGermanyEndpointData(germanyEndpointData);
    data.setGermanyAgeGroupsEndpointData(germanyAgeGroupsEndpointData);
    data.setGermanyHistoryCasesEndpointData(germanyHistoryCasesEndpointData);
    data.setGermanyHistoryDeathsEndpointData(germanyHistoryDeathsEndpointData);
    data.setGermanyHistoryIncidenceEndpointData(germanyHistoryIncidenceEndpointData);
    data.setGermanyHistoryRecoveredEndpointData(germanyHistoryRecoveredEndpointData);

    // Districts
    data.setDistrictsEndpointData(districtsEndpointData);
    data.setDistrictsHistoryCasesEndpointData(districtsHistoryCasesEndpointData);
    data.setDistrictsHistoryDeathsEndpointData(districtsHistoryDeathsEndpointData);
    data.setDistrictsHistoryFrozenIncidenceEndpointData(districtsHistoryFrozenIncidenceEndpointData);
    data.setDistrictsHistoryIncidenceEndpointData(districtsHistoryIncidenceEndpointData);
    data.setDistrictsHistoryRecoveredEndpointData(districtsHistoryRecoveredEndpointData);

    // States
    data.setStatesEndpointData(statesEndpointData);
    data.setStatesAgeGroupsEndpointData(statesAgeGroupsEndpointData);
    data.setStatesHistoryCasesEndpointData(statesHistoryCasesEndpointData);
    data.setStatesHistoryDeathsEndpointData(statesHistoryDeathsEndpointData);
    data.setStatesHistoryIncidenceEndpointData(statesHistoryIncidenceEndpointData);
    data.setStatesHistoryRecoveredEndpointData(statesHistoryRecoveredEndpointData);

    // Maps
    data.setMapDistrictsEndpoint(mapDistrictsEndpoint);
    data.setMapDistrictsLegendEndpoint(mapDistricsLegendEndpoint);
    data.setMapStatesEndpoint(mapStatesEndpoint);
    data.setMapStatesLegendEndpoint(mapStatesLegendEndpoint);

    // Vaccinations
    data.setVaccinationsEndpointData(vaccinationsEndpointData);
    data.setVaccinationsHistoryEndpointData(vaccinationsHistoryEndpointData);
    return in;
}
