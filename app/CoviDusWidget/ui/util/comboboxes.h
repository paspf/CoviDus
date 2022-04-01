#ifndef COMBOBOXES_H
#define COMBOBOXES_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include <QObject>
#include "endpointdataretainer.h"
#include "ui/Style.h"
#include "ui/DataSetValue.h"

/**
 * @brief MainWindow::setStateItems inserts all available states into the state comboboxes, clears them beforehand
 * @param ui mainwindow
 * @param data endpoint data containing the states
 * @param currentState currently selected state
 */
void setStateItems(Ui::MainWindow *ui, StatesEndpointData *data, QString currentState);
/**
 * @brief MainWindow::setDistrictItems inserts all available (and state-relevant) districts into the combobox, clears it beforehand
 * @param ui mainwindow
 * @param comboBox for district selection
 * @param currentState currently selected state (for filtering only districts that belong to the state)
 * @param currentDistrict currently selected district
 */
void setDistrictItems(Ui::MainWindow *ui, EndpointDataRetainer &endpointDataRetainer, QComboBox *comboBox, QString currentState, QString currentDistrict);
/**
 * @brief MainWindow::setDataSetItems sets the DataSet combobox items for selecting graph display mode
 * @param ui mainwindow
 */
void setDataSetItems(Ui::MainWindow *ui);
/**
 * @brief MainWindow::setStyleItems adds (translated) style combobox items
 * @param ui mainwindow
 */
void setStyleItems(Ui::MainWindow *ui);

#endif // COMBOBOXES_H
