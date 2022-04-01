#ifndef DATASETVALUE_H
#define DATASETVALUE_H

#include <QMainWindow>
#include <QObject>
#include <QMap>

/**
 * @brief The DataSetValue enum depicts the different types of line graphs
 */
enum class DataSetValue {
    INCIDENCE,
    INFECTED,
    RECOVERED,
    DECEASED,
    VACCINATED,
    VACCINATED_HISTORY
};

const QString startDataSetValue = QObject::tr("Inzidenz");

const QMap<QString, DataSetValue> dataSetValues({
    {startDataSetValue, DataSetValue::INCIDENCE},
    {QObject::tr("Infizierte"), DataSetValue::INFECTED},
    {QObject::tr("Genesene"), DataSetValue::RECOVERED},
    {QObject::tr("Verstorbene"), DataSetValue::DECEASED},
    {QObject::tr("Geimpfte"), DataSetValue::VACCINATED},
    {QObject::tr("Impfverlauf"), DataSetValue::VACCINATED_HISTORY}
});

#endif // DATASETVALUE_H
