#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <QImage>
#include <QPixmap>
#include <QBarSet>
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
#include "endpoints/vaccinations/vaccinationsendpointdata.h"

#include "endpointdataretainer.h"
#include "endpointretainer.h"
#include "ui_mainwindow.h"
#include "eventthread.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString matrix[16][8];
    QString appPath = QCoreApplication::applicationDirPath();

public slots:
    /**
     * @brief MainWindow::receiveGermanyEndpointData slot
     * @param data
     */
    void receiveGermanyEndpointData(GermanyEndpointData *data);
    /**
     * @brief MainWindow::receiveMapDistrictsEndpointData slot
     * @param image
     */
    void receiveMapDistrictsEndpointData(QImage *image);
    /**
     * @brief MainWindow::receiveMapDistrictsLegendEndpointData slot
     * @param data
     */
    void receiveMapDistrictsLegendEndpointData(QList<LegendInfo> *data);
    /**
     * @brief MainWindow::receiveMapStatesEndpointData slot
     * @param image
     */
    void receiveMapStatesEndpointData(QImage *image);
    /**
     * @brief MainWindow::receiveMapStatesLegendEndpointData slot
     * @param data
     */
    void receiveMapStatesLegendEndpointData(QList<LegendInfo> *data);
    /**
     * @brief MainWindow::receiveGermanyHistoryIncidenceEndpointData slot
     * @param data
     */
    void receiveGermanyHistoryIncidenceEndpointData(GermanyHistoryIncidenceEndpointData *data);
    /**
     * @brief MainWindow::receiveDistrictsEndpointData slot
     * @param data
     */
    void receiveDistrictsEndpointData(DistrictsEndpointData *data);
    /**
     * @brief MainWindow::receiveStatesEndpointData slot
     * @param data
     */
    void receiveStatesEndpointData(StatesEndpointData *data);
    /**
     * @brief MainWindow::receiveVaccinationsEndpointData slot
     * @param data
     */
    void receiveVaccinationsEndpointData(VaccinationsEndpointData *data);
    /**
     * @brief MainWindow::receiveEndpointsReadyToFetchData connects all endpoints to the endpoint retainer and emits a signal
     */
    void receiveEndpointsReadyToFetchData();
    /**
     * @brief MainWindow::on_comboBox_settings_style_currentIndexChanged sets the ui style after a settings change
     * @param index
     */
    void on_comboBox_settings_style_currentIndexChanged(int index);
    /**
     * @brief MainWindow::on_comboBox_settings_state_currentTextChanged sets state after selection, relevant districts and automatically redraws graphs after change
     * @param text selected
     */
    void on_comboBox_settings_state_currentTextChanged(const QString &text);
    /**
     * @brief MainWindow::on_comboBox_settings_county_currentTextChanged sets district after selection and automatically redraws graphs after change
     * @param text selected
     */
    void on_comboBox_settings_county_currentTextChanged(const QString &text);
    /**
     * @brief MainWindow::on_comboBox_infections_DataSetSelector_currentIndexChanged rerender the infections/vaccination graph information on dataset change
     * @param index
     */
    void on_comboBox_infections_DataSetSelector_currentIndexChanged(int index);
    /**
     * @brief MainWindow::on_comboBox_infections_StateSelector_currentIndexChanged rerender the infections/vaccination graph information on state change
     * @param index
     */
    void on_comboBox_infections_StateSelector_currentIndexChanged(int index);
    /**
     * @brief MainWindow::on_comboBox_infections_DistrictSelector_currentIndexChanged rerender the infections/vaccination graph information on district change
     * @param index
     */
    void on_comboBox_infections_DistrictSelector_currentIndexChanged(int index);
    /**
     * @brief MainWindow::on_pushButton_settings_save_clicked save settings on click
     */
    void on_pushButton_settings_save_clicked();
    /**
     * @brief MainWindow::on_exportStatesAsCSVButton_clicked exports states information to csv
     */
    void on_exportStatesAsCSVButton_clicked();
    /**
     * @brief MainWindow::on_exportDistrictsAsCSVButton_clicked exports districts information to csv
     */
    void on_exportDistrictsAsCSVButton_clicked();
    /**
     * @brief MainWindow::on_comboBox_settings_language_currentIndexChanged changes language on combobox selection
     * @param index
     */
    void on_comboBox_settings_language_currentIndexChanged(int index);
    /**
     * @brief MainWindow::overviewGraphPointHovered sets the info label with the currently hovered point information
     * @param point hovered
     * @param state whether the point is currently hovered
     */
    void overviewGraphPointHovered(const QPointF &point, bool state);
    /**
     * @brief MainWindow::infectionsGraphPointHovered sets the info label with the currently hovered point information
     * @param point hovered
     * @param state whether the point is currently hovered
     */
    void infectionsGraphPointHovered(const QPointF &point, bool state);
    /**
     * @brief MainWindow::barSetHovered sets an info label with the currently hovered bar chart section
     * @param status whether bar chart section is hovered
     * @param index hovered
     * @param barset containing bar chart information
     */
    void barSetHovered(bool status, int index, QBarSet *barset);

signals:
    /**
     * @brief fetchEndpointsDataSignal notifies the endpointRetainer to fetch data from all endpoints
     */
    void fetchEndpointsDataSignal();
    /**
     * @brief sendInitEndpointsSignal notifies the endpointRetainer to initialize all endpoint information
     */
    void sendInitEndpointsSignal();

public:
    /**
     * @brief MainWindow::setOverviewGraphData draws the incidence graph for germany in the overview window
     */
    void setOverviewGraphData();
    /**
     * @brief MainWindow::setInfectionsGraphData fills the graph ui with infections/vaccination informataion depending on the selected dataset
     */
    void setInfectionsGraphData();
    /**
     * @brief MainWindow::setGraphData draws a graph with the given historydata into a chart with a graph title and y axis title
     * @param chart into which the graph is drawn
     * @param data to illustrate
     * @param graphTitle
     * @param yAxisTitle
     * @param infoLabel displays graph hover data (either "ui->label_overview_graph_info" or "ui->label_infections_graph_info", defaults to no connection)
     */
    void setGraphData(QChart *chart, QVector<HistoryData> *data, QString graphTitle, QString yAxisTitle, QLabel *infoLabel);
    /**
     * @brief MainWindow::setVaccinationGraphData draws a graph containing vaccination information into the given chart with the given state name
     * @param chart to draw the graph on
     * @param name of the state
     * @param firstVaccination information
     * @param secondVaccination information
     * @param boosterVaccination information
     */
    void setVaccinationGraphData(QChart *chart, QString name, VaccinationData *firstVaccination, VaccinationData *secondVaccination, VaccinationData *boosterVaccination);
    /**
     * @brief MainWindow::setVaccinationHistoryGraphData draws a vaccination bar chart into the given chart (ui component)
     * @param chart to contian the bar chart
     * @param data vaccination information
     * @param graphTitle
     */
    void setVaccinationHistoryGraphData(QChart *chart, QVector<VaccinationHistoryData> *data, QString graphTitle);

private:
    Ui::MainWindow *ui;
    EventThread endpointThread;
    EndpointRetainer endpointRetainer;
    EndpointDataRetainer endpointDataRetainer;
    QTranslator translator;
    /**
     * @brief MainWindow::fillTableViewDistricts fills the ui (table) for showing further information about districts
     */
    void fillTableViewDistricts();
    /**
     * @brief MainWindow::fillTableViewStates fills the ui (table) for showing further information about states
     */
    void fillTableViewStates();
    /**
     * @brief MainWindow::closeEvent
     * @param event
     */
    void closeEvent(QCloseEvent *event);
    /**
     * @brief MainWindow::resizeEvent hides chart and maps in overview screen if screen is too small
     * @param event
     */
    void resizeEvent(QResizeEvent* event);
    /**
     * @brief MainWindow::setOverviewStateInfo sets all relevant overview info about the currently selected state
     * @param data endpoint data containing the state information
     */
    void setOverviewStateInfo(StatesEndpointData *data);
    /**
     * @brief MainWindow::setOverviewStateInfo sets all relevant overview info about the vaccinations
     * @param data (endpoint data) containing the vaccination information
     */
    void setOverviewStateVaccinationInfo(VaccinationsEndpointData *data);
    /**
     * @brief MainWindow::setOverviewDistrictInfo sets all relevant overview info about the currently selected district
     * @param data (endpoint data) containing the district information
     */
    void setOverviewDistrictInfo(DistrictsEndpointData *data);
    /**
     * @brief MainWindow::serializeRetainer
     * Serialize endpointDataRetainer.
     */
    void serializeRetainer();
    /**
     * @brief MainWindow::deSerializeRetainer
     * Deserialize endpointDataRetainer and send signals with deserializeed data.
     */
    void deSerializeRetainer();
    /**
     * @brief MainWindow::exportCSV exports an item view to a csv file
     * @param view containing the ui items
     */
    void exportCSV(QAbstractItemView *view);
    /**
     * @brief MainWindow::changeLanguage changes ui language to given new language, defaults to given default language on error
     * @param newLanguage
     * @param defaultLanguage
     * @return true if given language could be set else false
     */
    bool changeLanguage(const QString &newLanguage, const QString &defaultLanguage = "en");
    /**
     * @brief MainWindow::getGraphInfoText formats a point's coordinate information
     * @param point to show information of
     * @param state whether information should be shown or empty string
     * @return coordinates or empty string
     */
    QString getGraphInfoText(const QPointF &point, bool state);

};
#endif // MAINWINDOW_H
