#include "ui/util/comboboxes.h"
#include <stdbool.h>

void setStateItems(Ui::MainWindow *ui, StatesEndpointData *data, QString currentState)
{
    ui->comboBox_settings_state->blockSignals(true);

    ui->comboBox_settings_state->clear();
    ui->comboBox_infections_StateSelector->clear();
    for (auto it = data->data.cbegin(), end = data->data.cend(); it != end; ++it)
    {
        ui->comboBox_settings_state->addItem(it->state, it->stateAbbreviation);
        ui->comboBox_infections_StateSelector->addItem(it->state, it->stateAbbreviation);
    }

    ui->comboBox_settings_state->setCurrentText(currentState);
    ui->comboBox_infections_StateSelector->setCurrentText(currentState);

    // add "Germany" as state for tab infections
    ui->comboBox_infections_StateSelector->addItem(QObject::tr("---(Deutschland)"), "---(Deutschland)");
    ui->comboBox_settings_state->blockSignals(false);
    ui->comboBox_infections_StateSelector->blockSignals(false);
}

void setDistrictItems(Ui::MainWindow *ui, EndpointDataRetainer &endpointDataRetainer, QComboBox *comboBox, QString currentState, QString currentDistrict)
{
    comboBox->blockSignals(true);

    comboBox->clear();
    QList<DistrictsEndpointDataInformation> values = endpointDataRetainer.getDistrictsEndpointData().data.values();
    std::sort(values.begin(), values.end(), [](DistrictsEndpointDataInformation &lhs, DistrictsEndpointDataInformation &rhs){
        return QString::compare(lhs.name, rhs.name, Qt::CaseInsensitive) < 0;
    });
    for (auto it = values.cbegin(), end = values.cend(); it != end; ++it)
    {
        bool stateIsCurrentState = QString::compare(it->state, currentState, Qt::CaseInsensitive) == 0;
        if (currentState.length() == 0 || stateIsCurrentState)
        {
            comboBox->addItem(it->name, it->ags);
        }
    }

    comboBox->setCurrentText(currentDistrict);

    ui->comboBox_infections_DistrictSelector->addItem(QObject::tr("---(Alle Kreise)"), "---(Alle Kreise)");
    comboBox->blockSignals(false);
}


void setDataSetItems(Ui::MainWindow *ui)
{
    ui->comboBox_infections_DataSetSelector->clear();
    // set all types of dataset
    for (auto it = dataSetValues.keyBegin(), end = dataSetValues.keyEnd(); it != end; ++it)
    {
        ui->comboBox_infections_DataSetSelector->addItem(QObject::tr((*it).toStdString().c_str()), QVariant::fromValue(dataSetValues[*it]));
    }
    ui->comboBox_infections_DataSetSelector->setCurrentText(QObject::tr(startDataSetValue.toStdString().c_str()));
}

void setStyleItems(Ui::MainWindow *ui)
{
    // Remember already used style
    ui->comboBox_settings_style->blockSignals(true);
    Style s = QVariant::fromValue(ui->comboBox_settings_style->currentData()).value<Style>();
    ui->comboBox_settings_style->clear();
    // Add Styles
    ui->comboBox_settings_style->addItem(QObject::tr("Bright"), QVariant::fromValue(Style::BRIGHT));
    ui->comboBox_settings_style->addItem(QObject::tr("Dark"), QVariant::fromValue(Style::DARK));
    ui->comboBox_settings_style->setCurrentIndex((int)s);
    ui->comboBox_settings_style->blockSignals(false);
}
