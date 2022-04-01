#include "mainwindow.h"
#include <QThread>
#include <qtconcurrentrun.h>
#include <float.h>
#include <QLineSeries>
#include <QDateTimeAxis>
#include <QValueAxis>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QStackedBarSeries>
#include <QBarSeries>
#include <QBarCategoryAxis>
#include <QFileDialog>
#include <QMessageBox>
#include <QLegendMarker>

#include "ui/util/comboboxes.h"
#include "ui/util/settings.h"

#define QT_SORT_ROLE Qt::UserRole + 1

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , endpointThread(this)
    , endpointRetainer()
    , endpointDataRetainer()
{
    ui->setupUi(this);
    enableQtDefaultStyle(this, ui);
    // connect all signals and slots
    // sender, signal, receiver, method

    // connect data retainer with ui
    connect(&endpointDataRetainer, &EndpointDataRetainer::signalGermanyEndpointData, this, &MainWindow::receiveGermanyEndpointData);
    connect(&endpointDataRetainer, &EndpointDataRetainer::signalGermanyHistoryIncidenceEndpointData, this, &MainWindow::receiveGermanyHistoryIncidenceEndpointData);
    connect(&endpointDataRetainer, &EndpointDataRetainer::signalDistrictsEndpointData, this, &MainWindow::receiveDistrictsEndpointData);
    connect(&endpointDataRetainer, &EndpointDataRetainer::signalStatesEndpointData, this, &MainWindow::receiveStatesEndpointData);
    connect(&endpointDataRetainer, &EndpointDataRetainer::signalMapDistrictsEndpoint, this, &MainWindow::receiveMapDistrictsEndpointData);
    connect(&endpointDataRetainer, &EndpointDataRetainer::signalMapStatesEndpoint, this, &MainWindow::receiveMapStatesEndpointData);
    connect(&endpointDataRetainer, &EndpointDataRetainer::signalVaccinationsEndpointData, this, &MainWindow::receiveVaccinationsEndpointData);
    connect(&endpointDataRetainer, &EndpointDataRetainer::signalMapDistrictsLegendEndpoint, this, &MainWindow::receiveMapDistrictsLegendEndpointData);
    connect(&endpointDataRetainer, &EndpointDataRetainer::signalMapStatesLegendEndpoint, this, &MainWindow::receiveMapStatesLegendEndpointData);

    // connect endpoint retainer with ui
    connect(&endpointRetainer, &EndpointRetainer::signalEndpointsReadyToFetchData, this, &MainWindow::receiveEndpointsReadyToFetchData);

    // connect ui with endpoint retainer
    connect(this, &MainWindow::fetchEndpointsDataSignal, &endpointRetainer, &EndpointRetainer::receiveFetchEndpointsDataSignal);
    connect(this, &MainWindow::sendInitEndpointsSignal, &endpointRetainer, &EndpointRetainer::receiveInitEndpointsSignal);

    // Add recommended servers
    ui->comboBox_settings_server->addItem(EndpointRetainer::baseUrlRKI);
    ui->comboBox_settings_server->addItem("http://localhost:8080");

    // Add styles
    setStyleItems(ui);

    // add supported languages
    ui->comboBox_settings_language->blockSignals(true);
    ui->comboBox_settings_language->addItem("en");
    ui->comboBox_settings_language->addItem("de");
    ui->comboBox_settings_language->blockSignals(false);

    // restore settings
    restoreSettings(this);
    restoreSettingsUser(ui);
    endpointRetainer.setBaseUrl(ui->comboBox_settings_server->currentText());
    endpointRetainer.enablePeriodicFetch();

    // initially set correct application language
    QString currentLanguage = ui->comboBox_settings_language->currentText();
    changeLanguage(currentLanguage);

    // get endpoints in another thread
    endpointRetainer.moveToThread(&endpointThread);
    endpointThread.start();

    // init data
    ui->pushButton_settings_Icon->setIcon(QIcon(":/images/CoviDusIcon.ico"));
    deSerializeRetainer();

    // Add graph options
    setDataSetItems(ui);

    on_comboBox_settings_state_currentTextChanged(ui->comboBox_settings_state->currentText());
    on_comboBox_settings_county_currentTextChanged(ui->comboBox_settings_county->currentText());

    // initialize data pull from server
    emit sendInitEndpointsSignal();
}

void MainWindow::setOverviewStateInfo(StatesEndpointData *data)
{
    QString currentState = ui->comboBox_settings_state->currentText();
    const auto &stateData = data->data.find(currentState);
    if (stateData != data->data.end())
    {
        ui->label_OV_B_Name->setText(stateData->name);
        ui->label_OV_B_Incidence->setText(QString::number(stateData->weekIncidence));
        ui->label_OV_B_CasesPer100K->setText(QString::number(stateData->casesPer100k));
        ui->label_OV_B_CasesPerWeek->setText(QString::number(stateData->casesPerWeek));
        ui->label_OV_B_Cases->setText(QString::number(stateData->cases));
        ui->label_OV_B_Deaths->setText(QString::number(stateData->deaths));
        ui->label_OV_B_Recovered->setText(QString::number(stateData->recovered));
    }
}

void MainWindow::setOverviewStateVaccinationInfo(VaccinationsEndpointData *data)
{
    ui->label_OV_B_SingleShot->setText(QString::number(data->states[ui->comboBox_settings_state->currentText()].firstVaccination.quote * 100, 'f', 1) + "%");
    ui->label_OV_B_DoubleShot->setText(QString::number(data->states[ui->comboBox_settings_state->currentText()].secondVaccination.quote * 100, 'f', 1) + "%");
    ui->label_OV_B_BoosterShot->setText(QString::number(data->states[ui->comboBox_settings_state->currentText()].boosterVaccination.quote * 100, 'f', 1) + "%");
}

void MainWindow::setOverviewDistrictInfo(DistrictsEndpointData *data)
{
    QString currentDistrictAgs = ui->comboBox_settings_county->currentData().toString();
    const auto &districtData = data->data.find(currentDistrictAgs);
    if (districtData != data->data.end())
    {
        ui->label_OV_L_Name->setText(districtData->name);
        ui->label_OV_L_Incidence->setText(QString::number(districtData->weekIncidence));
        ui->label_OV_L_CasesPer100K->setText(QString::number(districtData->casesPer100k));
        ui->label_OV_L_CasesPerWeek->setText(QString::number(districtData->casesPerWeek));
        ui->label_OV_L_Cases->setText(QString::number(districtData->cases));
        ui->label_OV_L_Deaths->setText(QString::number(districtData->deaths));
        ui->label_OV_L_Recovered->setText(QString::number(districtData->recovered));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::receiveGermanyEndpointData(GermanyEndpointData *data)
{
    if (data == nullptr)
    {
        return;
    }
    // current covid stats
    ui->label_OV_D_Incidence->setText(QString::number(data->weekIncidence, 'f', 2));
    ui->label_OV_D_CasesPer100K->setText(QString::number(data->casesPer100k, 'f', 2));
    ui->label_OV_D_CasesPerWeek->setText(QString::number(data->casesPerWeek));
    ui->label_OV_D_RValue->setText(QString::number(data->r.value, 'g', 2));

    // overall covid stats
    ui->label_OV_D_Cases->setText(QString::number(data->cases));
    ui->label_OV_D_Deaths->setText(QString::number(data->deaths));
    ui->label_OV_D_Recovered->setText(QString::number(data->recovered));

    // last update
    QDateTime dateTimeList = data->meta.lastUpdate;
    if (!dateTimeList.isNull())
    {
        //ui->label_OV_D_LastUpdate->setText(dateTimeList.toString(Qt::DateFormat::TextDate));
        ui->label_OV_D_LastUpdate->setText(dateTimeList.toString(tr("dd.MM.yyyy hh:mm")));
    }
    else
    {
        ui->label_OV_D_LastUpdate->setText(tr("Datenfehler"));
    }
}

void MainWindow::receiveStatesEndpointData(StatesEndpointData *data)
{
    if (data == nullptr) {
        return;
    }
    fillTableViewStates();
    QString currentState = ui->comboBox_settings_state->currentText();
    QString currentDistrict = ui->comboBox_settings_county->currentText();
    setStateItems(ui, data, currentState);
    setDistrictItems(ui, endpointDataRetainer, ui->comboBox_settings_county, currentState, currentDistrict);
    setDistrictItems(ui, endpointDataRetainer, ui->comboBox_infections_DistrictSelector, currentState, currentDistrict);

    restoreSettingsUserDistrict(ui);
    restoreSettingsUserState(ui);
    setOverviewStateInfo(data);
}

void MainWindow::receiveVaccinationsEndpointData(VaccinationsEndpointData *data)
{
    this->ui->label_OV_D_SingleShot->setText(QString::number(data->firstVaccination.quote * 100, 'f', 1) + "%");
    this->ui->label_OV_D_DoubleShot->setText(QString::number(data->secondVaccination.quote * 100, 'f', 1) + "%");
    this->ui->label_OV_D_BoosterShot->setText(QString::number(data->boosterVaccination.quote * 100, 'f', 1) + "%");
    setOverviewStateVaccinationInfo(data);
}

void MainWindow::receiveEndpointsReadyToFetchData()
{
    // germany
    QObject::connect(endpointRetainer.germanyEndpoint, &GermanyEndpoint::dataReceived, &endpointDataRetainer, &EndpointDataRetainer::receiveGermanyEndpointData);
    QObject::connect(endpointRetainer.germanyHistoryCasesEndpoint, &GermanyHistoryCasesEndpoint::dataReceived, &endpointDataRetainer, &EndpointDataRetainer::receiveGermanyHistoryCasesEndpointData);
    QObject::connect(endpointRetainer.germanyHistoryIncidenceEndpoint, &GermanyHistoryIncidenceEndpoint::dataReceived, &endpointDataRetainer, &EndpointDataRetainer::receiveGermanyHistoryIncidenceEndpointData);
    QObject::connect(endpointRetainer.germanyHistoryDeathsEndpoint, &GermanyHistoryDeathsEndpoint::dataReceived, &endpointDataRetainer, &EndpointDataRetainer::receiveGermanyHistoryDeathsEndpointData);
    QObject::connect(endpointRetainer.germanyHistoryRecoveredEndpoint, &GermanyHistoryRecoveredEndpoint::dataReceived, &endpointDataRetainer, &EndpointDataRetainer::receiveGermanyHistoryRecoveredEndpointData);
    QObject::connect(endpointRetainer.germanyAgeGroupsEndpoint, &GermanyAgeGroupsEndpoint::dataReceived, &endpointDataRetainer, &EndpointDataRetainer::receiveGermanyAgeGroupsEndpointData);
    // districts
    QObject::connect(endpointRetainer.districtsEndpoint, &DistrictsEndpoint::dataReceived, &endpointDataRetainer, &EndpointDataRetainer::receiveDistrictsEndpointData);
    QObject::connect(endpointRetainer.districtsHistoryCasesEndpoint, &DistrictsHistoryCasesEndpoint::dataReceived, &endpointDataRetainer, &EndpointDataRetainer::receiveDistrictsHistoryCasesEndpointData);
    QObject::connect(endpointRetainer.districtsHistoryDeathsEndpoint, &DistrictsHistoryDeathsEndpoint::dataReceived, &endpointDataRetainer, &EndpointDataRetainer::receiveDistrictsHistoryDeathsEndpointData);
    QObject::connect(endpointRetainer.districtsHistoryFrozenIncidenceEndpoint, &DistrictsHistoryFrozenIncidenceEndpoint::dataReceived, &endpointDataRetainer, &EndpointDataRetainer::receiveDistrictsHistoryFrozenIncidenceEndpointData);
    QObject::connect(endpointRetainer.districtsHistoryIncidenceEndpoint, &DistrictsHistoryIncidenceEndpoint::dataReceived, &endpointDataRetainer, &EndpointDataRetainer::receiveDistrictsHistoryIncidenceEndpointData);
    QObject::connect(endpointRetainer.districtsHistoryRecoveredEndpoint, &DistrictsHistoryRecoveredEndpoint::dataReceived, &endpointDataRetainer, &EndpointDataRetainer::receiveDistrictsHistoryRecoveredEndpointData);
    // states
    QObject::connect(endpointRetainer.statesEndpoint, &StatesEndpoint::dataReceived, &endpointDataRetainer, &EndpointDataRetainer::receiveStatesEndpointData);
    QObject::connect(endpointRetainer.statesAgeGroupsEndpoint, &StatesAgeGroupsEndpoint::dataReceived, &endpointDataRetainer, &EndpointDataRetainer::receiveStatesAgeGroupsEndpointData);
    QObject::connect(endpointRetainer.statesHistoryCasesEndpoint, &StatesHistoryCasesEndpoint::dataReceived, &endpointDataRetainer, &EndpointDataRetainer::receiveStatesHistoryCasesEndpointData);
    QObject::connect(endpointRetainer.statesHistoryDeathsEndpoint, &StatesHistoryDeathsEndpoint::dataReceived, &endpointDataRetainer, &EndpointDataRetainer::receiveStatesHistoryDeathsEndpointData);
    QObject::connect(endpointRetainer.statesHistoryIncidenceEndpoint, &StatesHistoryIncidenceEndpoint::dataReceived, &endpointDataRetainer, &EndpointDataRetainer::receiveStatesHistoryIncidenceEndpointData);
    QObject::connect(endpointRetainer.statesHistoryRecoveredEndpoint, &StatesHistoryRecoveredEndpoint::dataReceived, &endpointDataRetainer, &EndpointDataRetainer::receiveStatesHistoryRecoveredEndpointData);
    // maps
    QObject::connect(endpointRetainer.mapDistrictsEndpoint, &MapDistrictsEndpoint::dataReceived, &endpointDataRetainer, &EndpointDataRetainer::receiveMapDistrictsEndpoint);
    QObject::connect(endpointRetainer.mapDistrictsLegendEndpoint, &MapDistrictsLegendEndpoint::dataReceived, &endpointDataRetainer, &EndpointDataRetainer::receiveMapDistrictsLegendEndpoint);
    QObject::connect(endpointRetainer.mapStatesEndpoint, &MapStatesEndpoint::dataReceived, &endpointDataRetainer, &EndpointDataRetainer::receiveMapStatesEndpoint);
    QObject::connect(endpointRetainer.mapStatesLegendEndpoint, &MapStatesLegendEndpoint::dataReceived, &endpointDataRetainer, &EndpointDataRetainer::receiveMapStatesLegendEndpoint);
    // vaccinations
    QObject::connect(endpointRetainer.vaccinationsEndpoint, &VaccinationsEndpoint::dataReceived, &endpointDataRetainer, &EndpointDataRetainer::receiveVaccinationsEndpointData);
    QObject::connect(endpointRetainer.vaccinationsHistoryEndpoint, &VaccinationsHistoryEndpoint::dataReceived, &endpointDataRetainer, &EndpointDataRetainer::receiveVaccinationsHistoryEndpointData);

    emit fetchEndpointsDataSignal();
}

void MainWindow::receiveDistrictsEndpointData(DistrictsEndpointData *data)
{
    if (data == nullptr) {
        return;
    }
    fillTableViewDistricts();
    QString currentState = ui->comboBox_settings_state->currentText();
    QString currentDistrict = ui->comboBox_settings_county->currentText();
    setDistrictItems(ui, endpointDataRetainer, ui->comboBox_settings_county, currentState, currentDistrict);
    setDistrictItems(ui, endpointDataRetainer, ui->comboBox_infections_DistrictSelector, currentState, currentDistrict);
    setOverviewDistrictInfo(data);
}

void MainWindow::on_comboBox_settings_style_currentIndexChanged(int index)
{
    qDebug() << "Style index:" << index;
    if (ui->comboBox_settings_style->currentData().value<Style>() == Style::DARK) {
        enableDarkModeStyle(this, ui);
    }
    else {
        enableQtDefaultStyle(this, ui);
    }
}

void MainWindow::receiveMapStatesEndpointData(QImage *image)
{
    if (image == nullptr)
    {
        return;
    }

    if (image->isNull())
    {
        qDebug() << "Error retrieving states map";
    }
    ui->label_18->setPixmap(QPixmap::fromImage(*image));
}

void MainWindow::receiveMapStatesLegendEndpointData(QList<LegendInfo> *data)
{
    if (data == nullptr)
    {
        return;
    }
    ui->label_18->setLegend(*data);
}

void MainWindow::receiveMapDistrictsEndpointData(QImage *image)
{
    if (image == nullptr)
    {
        return;
    }

    if (image->isNull())
    {
        qDebug() << "Error retrieving districts map";
    }
    ui->label_19->setPixmap(QPixmap::fromImage(*image));
}

void MainWindow::receiveMapDistrictsLegendEndpointData(QList<LegendInfo> *data)
{
    if (data == nullptr)
    {
        return;
    }
    ui->label_19->setLegend(*data);
}

QString MainWindow::getGraphInfoText(const QPointF &point, bool state)
{
    return state ? QString("(%1 | %2)").arg(QDateTime::fromMSecsSinceEpoch(point.x()).toString(tr("dd.MM.yyyy"))).arg(QString::number(point.y(), 'f', 0)) : "";
}

void MainWindow::overviewGraphPointHovered(const QPointF &point, bool state)
{
    ui->label_overview_graph_info->setText(getGraphInfoText(point, state));
}

void MainWindow::infectionsGraphPointHovered(const QPointF &point, bool state)
{
    ui->label_infections_graph_info->setText(getGraphInfoText(point, state));
}

void MainWindow::setGraphData(QChart *chart, QVector<HistoryData> *data, QString graphTitle, QString yAxisTitle, QLabel *infoLabel)
{
    if (data == nullptr || chart == nullptr)
    {
        return;
    }

    chart->removeAllSeries();
    const auto chartAxes = chart->axes();
    for (auto it = chartAxes.begin(); it != chartAxes.end(); ++it)
    {
        chart->removeAxis(*it);
    }

    QLineSeries *series = new QLineSeries();
    QDateTimeAxis *xAxis = new QDateTimeAxis();
    QValueAxis *yAxis = new QValueAxis();
    double minVal = DBL_MAX;
    double maxVal = DBL_MIN;

    QDateTime minDateTime;
    QDateTime maxDateTime;

    for (const auto &d : *data)
    {
        *series << QPointF(d.date.toMSecsSinceEpoch(), d.value);
        minVal = d.value < minVal ? d.value : minVal;
        maxVal = d.value > maxVal ? d.value : maxVal;
        minDateTime =  minDateTime.isNull() || d.date < minDateTime ? QDateTime::fromMSecsSinceEpoch(d.date.toMSecsSinceEpoch()) : minDateTime;
        maxDateTime = maxDateTime.isNull() || d.date > maxDateTime ? QDateTime::fromMSecsSinceEpoch(d.date.toMSecsSinceEpoch()) : maxDateTime;
    }

    xAxis->setRange(minDateTime, maxDateTime);
    xAxis->setFormat(tr("dd.MM.yyyy"));
    xAxis->setTitleText(tr("Datum"));
    yAxis->setLabelFormat("%'d");
    yAxis->setRange(minVal, maxVal);
    yAxis->applyNiceNumbers();
    yAxis->setTickCount(11);
    yAxis->setMinorTickCount(0);
    yAxis->setTitleText(tr(yAxisTitle.toStdString().c_str()));

    QPen pen(0x80ba24);
    pen.setWidth(3);
    series->setPen(pen);

    chart->setTitle(tr(graphTitle.toStdString().c_str()));
    chart->addSeries(series);
    chart->addAxis(xAxis, Qt::AlignBottom);
    chart->addAxis(yAxis, Qt::AlignLeft);
    chart->legend()->markers(series).at(0)->setVisible(false);

    series->attachAxis(xAxis);
    series->attachAxis(yAxis);


    if (infoLabel->objectName().compare(ui->label_overview_graph_info->objectName(), Qt::CaseSensitivity::CaseSensitive) == 0)
    {
        connect(series, &QLineSeries::hovered, this, &MainWindow::overviewGraphPointHovered);
    }
    else if (infoLabel->objectName().compare(ui->label_infections_graph_info->objectName(), Qt::CaseSensitivity::CaseSensitive) == 0)
    {
        connect(series, &QLineSeries::hovered, this, &MainWindow::infectionsGraphPointHovered);
    }
}

void MainWindow::receiveGermanyHistoryIncidenceEndpointData(GermanyHistoryIncidenceEndpointData *data)
{
    Q_UNUSED(data);
    setOverviewGraphData();
}

void MainWindow::setOverviewGraphData()
{
    GermanyHistoryIncidenceEndpointData &data = endpointDataRetainer.getGermanyHistoryIncidenceEndpointData();
    setGraphData(ui->graphicsView_OV_1->chart(), &data.data, tr("Inzidenzverlauf Deutschland"), tr("Inzidenz"), ui->label_overview_graph_info);
}

void MainWindow::fillTableViewDistricts()
{
    QStandardItemModel *csvModel;
    csvModel = new QStandardItemModel(this);

    QMap<QString, DistrictsEndpointDataInformation>* dataMap = &endpointDataRetainer.getDistrictsEndpointData().data;
    for (auto it = dataMap->begin(); it != dataMap->end(); ++it)
    {
        QList<QStandardItem *> standardItemsList;

        QStandardItem *item = new QStandardItem();
        item->setText(it->name);
        item->setData(it->name, QT_SORT_ROLE);
        standardItemsList.append(item);

        item = new QStandardItem();
        item->setText(QString::number(it->weekIncidence, 'f', 2));
        item->setData(it->weekIncidence, QT_SORT_ROLE);
        standardItemsList.append(item);

        item = new QStandardItem();
        item->setText(QString::number(it->casesPerWeek));
        item->setData(it->casesPerWeek, QT_SORT_ROLE);
        standardItemsList.append(item);

        item = new QStandardItem();
        item->setText(QString::number(it->cases));
        item->setData(it->cases, QT_SORT_ROLE);
        standardItemsList.append(item);

        item = new QStandardItem();
        item->setText(QString::number(it->delta.cases));
        item->setData(it->delta.cases, QT_SORT_ROLE);
        standardItemsList.append(item);

        item = new QStandardItem();
        item->setText(QString::number(it->deaths));
        item->setData(it->deaths, QT_SORT_ROLE);
        standardItemsList.append(item);

        item = new QStandardItem();
        item->setText(it->state);
        item->setData(it->state, QT_SORT_ROLE);
        standardItemsList.append(item);

        csvModel->insertRow(csvModel->rowCount(), standardItemsList);
        standardItemsList.clear();
    }

    int col = 0;
    csvModel->setHeaderData(0, Qt::Horizontal, QObject::tr("Landkreis"));
    csvModel->setHeaderData(++col, Qt::Horizontal, QObject::tr("weekIncidence"));
    csvModel->setHeaderData(++col, Qt::Horizontal, QObject::tr("casesPerWeek"));
    csvModel->setHeaderData(++col, Qt::Horizontal, QObject::tr("cases"));
    csvModel->setHeaderData(++col, Qt::Horizontal, QObject::tr("deltaCases"));
    csvModel->setHeaderData(++col, Qt::Horizontal, QObject::tr("deaths"));
    csvModel->setHeaderData(++col, Qt::Horizontal, QObject::tr("Bundesland"));

    csvModel->setSortRole(QT_SORT_ROLE);

    ui->tableViewKreis->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableViewKreis->setModel(csvModel);
    ui->tableViewKreis->verticalHeader()->hide();
}

void MainWindow::fillTableViewStates()
{
    QStandardItemModel *csvModel;
    csvModel = new QStandardItemModel(this);

    QMap<QString, StatesEndpointDataInformation>* dataMap = &endpointDataRetainer.getStatesEndpointData().data;
    for (auto it = dataMap->begin(); it != dataMap->end(); ++it)
    {
        QList<QStandardItem *> standardItemsList;

        QStandardItem *item = new QStandardItem();
        item->setText(it->name);
        item->setData(it->name, QT_SORT_ROLE);
        standardItemsList.append(item);

        item = new QStandardItem();
        item->setText(QString::number(it->weekIncidence, 'f', 2));
        item->setData(it->weekIncidence, QT_SORT_ROLE);
        standardItemsList.append(item);

        item = new QStandardItem();
        item->setText(QString::number(it->casesPerWeek));
        item->setData(it->casesPerWeek, QT_SORT_ROLE);
        standardItemsList.append(item);

        item = new QStandardItem();
        item->setText(QString::number(it->cases));
        item->setData(it->cases, QT_SORT_ROLE);
        standardItemsList.append(item);

        item = new QStandardItem();
        item->setText(QString::number(it->delta.cases));
        item->setData(it->delta.cases, QT_SORT_ROLE);
        standardItemsList.append(item);

        item = new QStandardItem();
        item->setText(QString::number(it->deaths));
        item->setData(it->deaths, QT_SORT_ROLE);
        standardItemsList.append(item);

        csvModel->insertRow(csvModel->rowCount(), standardItemsList);
        standardItemsList.clear();
    }

    int col = 0;
    csvModel->setHeaderData(0, Qt::Horizontal, QObject::tr("Bundesland"));
    csvModel->setHeaderData(++col, Qt::Horizontal, QObject::tr("weekIncidence"));
    csvModel->setHeaderData(++col, Qt::Horizontal, QObject::tr("casesPerWeek"));
    csvModel->setHeaderData(++col, Qt::Horizontal, QObject::tr("cases"));
    csvModel->setHeaderData(++col, Qt::Horizontal, QObject::tr("deltaCases"));
    csvModel->setHeaderData(++col, Qt::Horizontal, QObject::tr("deaths"));

    csvModel->setSortRole(QT_SORT_ROLE);

    ui->tableViewLand->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableViewLand->setModel(csvModel);
    ui->tableViewLand->verticalHeader()->hide();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (endpointThread.isRunning()) {
        endpointThread.exit();
    }

    saveSettingsOnClose(this);
    serializeRetainer();
    showMinimized();
    if (endpointThread.isRunning()) {
        endpointThread.requestInterruption();
        endpointThread.wait();
    }
    QMainWindow::closeEvent(event);
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
   QMainWindow::resizeEvent(event);
   // hide charts
   if (height() < 600)
   {
       ui->graphicsView_OV_1->setVisible(false);
       ui->label_18->setVisible(false);
       ui->label_19->setVisible(false);
   }
   else
   {
       ui->graphicsView_OV_1->setVisible(true);
       ui->label_18->setVisible(true);
       ui->label_19->setVisible(true);
   }
}

void MainWindow::serializeRetainer()
{
    // https://stackoverflow.com/questions/2570679/serialization-with-qt
    // https://forum.qt.io/topic/78161/custom-class-serialize-with-qdatastream/2
    // https://doc.qt.io/qt-6/qdatastream.html
    QFile file(appPath + "/" + "dataRetainer.dat");
    file.open(QIODevice::WriteOnly);
    // we will serialize the data into the file
    QDataStream out(&file);
    // serialize data retainer
    out << endpointDataRetainer;
}

void MainWindow::deSerializeRetainer()
{
    qDebug() << appPath;
    if (!QFile::exists(appPath + "/" + "dataRetainer.dat")) {
        return;
    }
    QFile file(appPath + "/" + "dataRetainer.dat");
    file.open(QIODevice::ReadOnly);
    // deserialize file into data retainer
    QDataStream in(&file);
    in >> endpointDataRetainer;
}

void MainWindow::on_comboBox_settings_state_currentTextChanged(const QString &text)
{
    StatesEndpointData *data = &endpointDataRetainer.getStatesEndpointData();
    VaccinationsEndpointData *vacData = &endpointDataRetainer.getVaccinationsEndpointData();

    QString currentState = ui->comboBox_settings_state->currentText();
    QString currentDistrict = ui->comboBox_settings_county->currentText();
    setStateItems(ui, data, currentState);
    ui->comboBox_settings_state->blockSignals(true);
    ui->comboBox_settings_state->setCurrentText(text);
    ui->comboBox_infections_StateSelector->blockSignals(true);
    ui->comboBox_infections_StateSelector->setCurrentText(text);
    setDistrictItems(ui, endpointDataRetainer, ui->comboBox_settings_county, currentState, currentDistrict);
    setDistrictItems(ui, endpointDataRetainer, ui->comboBox_infections_DistrictSelector, currentState, currentDistrict);
    setOverviewStateInfo(data);
    setOverviewStateVaccinationInfo(vacData);
    on_comboBox_settings_county_currentTextChanged(ui->comboBox_settings_county->currentText());

    ui->comboBox_settings_state->blockSignals(false);
    ui->comboBox_infections_StateSelector->blockSignals(false);
}

void MainWindow::on_comboBox_settings_county_currentTextChanged(const QString &text)
{
    DistrictsEndpointData *data = &endpointDataRetainer.getDistrictsEndpointData();
    ui->comboBox_infections_DistrictSelector->blockSignals(true);

    QString currentState = ui->comboBox_settings_state->currentText();
    ui->comboBox_settings_county->blockSignals(true);
    ui->comboBox_settings_county->setCurrentText(text);
    ui->comboBox_infections_DistrictSelector->setCurrentText(text);
    setOverviewDistrictInfo(data);
    setInfectionsGraphData();

    ui->comboBox_settings_county->blockSignals(false);
    ui->comboBox_infections_DistrictSelector->blockSignals(false);
}

void MainWindow::setInfectionsGraphData()
{
    QString currentState = ui->comboBox_infections_StateSelector->currentText();
    QString currentStateData = ui->comboBox_infections_StateSelector->currentData().toString();
    QString currentStateAbbreviation = ui->comboBox_infections_StateSelector->currentData().toString();
    QString currentDistrictName = ui->comboBox_infections_DistrictSelector->currentText();
    QString currentDistrictAgs = ui->comboBox_infections_DistrictSelector->currentData().toString();
    QString currentSelectedGraphDataSetText = ui->comboBox_infections_DataSetSelector->currentText();
    DataSetValue currentSelectedGraphDataSet = ui->comboBox_infections_DataSetSelector->currentData().value<DataSetValue>();
    QList<HistoryData> *historyData = nullptr;

    VaccinationsHistoryEndpointData vaccinationHistory = endpointDataRetainer.getVaccinationsHistoryEndpointData();
    if (currentStateData == "---(Deutschland)") {
        VaccinationsEndpointData vaccinationsGermany = endpointDataRetainer.getVaccinationsEndpointData();
        switch (currentSelectedGraphDataSet)
        {
            case DataSetValue::INCIDENCE:
                historyData = &endpointDataRetainer.getGermanyHistoryIncidenceEndpointData().data;
                break;
            case DataSetValue::INFECTED:
                historyData = &endpointDataRetainer.getGermanyHistoryCasesEndpointData().data;
                break;
            case DataSetValue::RECOVERED:
                historyData = &endpointDataRetainer.getGermanyHistoryRecoveredEndpointData().data;
                break;
            case DataSetValue::DECEASED:
                historyData = &endpointDataRetainer.getGermanyHistoryDeathsEndpointData().data;
                break;
            case DataSetValue::VACCINATED:
                historyData = nullptr;
                setVaccinationGraphData(ui->graphicsView_infections_1->chart(), tr("Impfverteilung Deutschland"), &vaccinationsGermany.firstVaccination, &vaccinationsGermany.secondVaccination, &vaccinationsGermany.boosterVaccination);
                break;
            case DataSetValue::VACCINATED_HISTORY:
                historyData = nullptr;
                setVaccinationHistoryGraphData(ui->graphicsView_infections_1->chart(), &vaccinationHistory.history, tr("Impfverlauf Deutschland"));
                break;
            default:
                return;
        }
    }
    else if (currentDistrictAgs == "---(Alle Kreise)")
    {
        switch (currentSelectedGraphDataSet)
        {
            case DataSetValue::INCIDENCE:
                historyData = &endpointDataRetainer.getStatesHistoryIncidenceEndpointData().data[currentStateAbbreviation].data;
                break;
            case DataSetValue::INFECTED:
                historyData = &endpointDataRetainer.getStatesHistoryCasesEndpointData().data[currentStateAbbreviation].data;
                break;
            case DataSetValue::RECOVERED:
                historyData = &endpointDataRetainer.getStatesHistoryRecoveredEndpointData().data[currentStateAbbreviation].data;
                break;
            case DataSetValue::DECEASED:
                historyData = &endpointDataRetainer.getStatesHistoryDeathsEndpointData().data[currentStateAbbreviation].data;
                break;
            case DataSetValue::VACCINATED:
                historyData = nullptr;
                break;
            case DataSetValue::VACCINATED_HISTORY:
                historyData = nullptr;
                setVaccinationHistoryGraphData(ui->graphicsView_infections_1->chart(), &vaccinationHistory.history, tr("Impfverlauf Deutschland"));
                break;
            default:
                return;
        }
    }
    else
    {
        VaccinationsEndpointDataInformation *vaccinations = &endpointDataRetainer.getVaccinationsEndpointData().states[currentState];
        switch (currentSelectedGraphDataSet)
        {
            case DataSetValue::INCIDENCE:
                historyData = &endpointDataRetainer.getDistrictsHistoryIncidenceEndpointData().data[currentDistrictAgs].history;
                break;
            case DataSetValue::INFECTED:
                historyData = &endpointDataRetainer.getDistrictsHistoryCasesEndpointData().data[currentDistrictAgs].history;
                break;
            case DataSetValue::RECOVERED:
                historyData = &endpointDataRetainer.getDistrictsHistoryRecoveredEndpointData().data[currentDistrictAgs].history;
                break;
            case DataSetValue::DECEASED:
                historyData = &endpointDataRetainer.getDistrictsHistoryDeathsEndpointData().data[currentDistrictAgs].history;
                break;
            case DataSetValue::VACCINATED:
                historyData = nullptr;
                setVaccinationGraphData(ui->graphicsView_infections_1->chart(), vaccinations->name, &vaccinations->firstVaccination, &vaccinations->secondVaccination, &vaccinations->boosterVaccination);
                break;
            case DataSetValue::VACCINATED_HISTORY:
                historyData = nullptr;
                setVaccinationHistoryGraphData(ui->graphicsView_infections_1->chart(), &vaccinationHistory.history, tr("Impfverlauf Deutschland"));
                break;
            default:
                return;
        }
    }

    if (historyData != nullptr)
    {
        setGraphData(ui->graphicsView_infections_1->chart(), historyData, tr("%1 von %2 aus %3").arg(currentSelectedGraphDataSetText).arg(currentDistrictName).arg(currentState), currentSelectedGraphDataSetText, ui->label_infections_graph_info);
    }
}

void MainWindow::setVaccinationGraphData(QChart *chart, QString name, VaccinationData *firstVaccination, VaccinationData *secondVaccination, VaccinationData *boosterVaccination)
{
    if (chart == nullptr || firstVaccination == nullptr || secondVaccination == nullptr)
    {
        return;
    }

    chart->removeAllSeries();
    const auto chartAxes = chart->axes();
    for (auto it = chartAxes.begin(); it != chartAxes.end(); ++it)
    {
        chart->removeAxis(*it);
    }

    QBarSet *astraZeneca = new QBarSet("AstraZeneca");
    QBarSet *biontech = new QBarSet("Biontech");
    QBarSet *janssen = new QBarSet("Johnson & Johnson");
    QBarSet *moderna = new QBarSet("Moderna");
    QBarSet *novavax = new QBarSet("Novavax");

    *astraZeneca << firstVaccination->astraZeneca << secondVaccination->astraZeneca << boosterVaccination->astraZeneca;
    *biontech << firstVaccination->biontech << secondVaccination->biontech << boosterVaccination->biontech;
    *janssen << firstVaccination->janssen << secondVaccination->janssen << boosterVaccination->janssen;
    *moderna << firstVaccination->moderna << secondVaccination->moderna << boosterVaccination->moderna;
    *novavax << firstVaccination->novavax << secondVaccination->novavax << boosterVaccination->novavax;

    QStackedBarSeries *stackedBarSeries = new QStackedBarSeries();
    stackedBarSeries->append(astraZeneca);
    stackedBarSeries->append(biontech);
    stackedBarSeries->append(janssen);
    stackedBarSeries->append(moderna);
    stackedBarSeries->append(novavax);
    QBarSeries *barSeries = new QBarSeries();
    barSeries->append(astraZeneca);
    barSeries->append(biontech);
    barSeries->append(janssen);
    barSeries->append(moderna);
    barSeries->append(novavax);

    chart->addSeries(stackedBarSeries);
    chart->addSeries(barSeries);

    // Add line with total population
    qreal population = (double) firstVaccination->vaccinated / firstVaccination->quote;
    QLineSeries *lineseries = new QLineSeries();
    lineseries->setName(tr("total population"));
    lineseries->append(QPoint(-1, population));
    lineseries->append(QPoint(3, population));
    chart->addSeries(lineseries);

    chart->setTitle(QString(tr("Impfstatistik für %1").arg(name)));

    QStringList categories;
    categories << tr("first vaccinations (%1%)").arg(QString::number(firstVaccination->quote * 100))
               << tr("second vaccinations (%1%)").arg(QString::number(secondVaccination->quote * 100))
               << tr("booster vaccinations");

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);

    QValueAxis *axisY = new QValueAxis();
    axisY->setLabelFormat("%'d");
    axisY->setMax(population);
    chart->addAxis(axisY, Qt::AlignLeft);
    stackedBarSeries->attachAxis(axisX);
    stackedBarSeries->attachAxis(axisY);
    barSeries->attachAxis(axisX);
    barSeries->attachAxis(axisY);
    lineseries->attachAxis(axisX);
    lineseries->attachAxis(axisY);
    axisY->applyNiceNumbers();
    axisY->setTickCount(11);
    axisY->setMinorTickCount(0);

    chart->legend()->setVisible(true);
    // turn off duplicate legend due to barSeries
    QList<QLegendMarker*> barSeriesMarkers = chart->legend()->markers(barSeries);
    for (int i = 0; i < barSeriesMarkers.size(); ++i)
    {
        barSeriesMarkers.at(i)->setVisible(false);
    }
    chart->legend()->setAlignment(Qt::AlignBottom);

    connect(stackedBarSeries, &QStackedBarSeries::hovered, this, &MainWindow::barSetHovered);
    connect(barSeries, &QBarSeries::hovered, this, &MainWindow::barSetHovered);
}

void MainWindow::barSetHovered(bool status, int index, QBarSet *barset)
{
    ui->label_infections_graph_info->setText(status ? QString::number(barset->at(index), 'f', 0) + " " + tr("Geimpfte") : "");
}

void MainWindow::on_comboBox_infections_DataSetSelector_currentIndexChanged(int index)
{
    Q_UNUSED(index);
    setInfectionsGraphData();
    DataSetValue currentSelectedGraphDataSet = ui->comboBox_infections_DataSetSelector->currentData().value<DataSetValue>();
    ui->comboBox_infections_DistrictSelector->setEnabled(currentSelectedGraphDataSet != DataSetValue::VACCINATED && currentSelectedGraphDataSet != DataSetValue::VACCINATED_HISTORY);
    ui->comboBox_infections_StateSelector->setEnabled(currentSelectedGraphDataSet != DataSetValue::VACCINATED_HISTORY);
}

void MainWindow::on_comboBox_infections_StateSelector_currentIndexChanged(int index)
{
    Q_UNUSED(index);
    QString currentState = ui->comboBox_infections_StateSelector->currentText();
    QString currentDistrict = ui->comboBox_settings_county->currentText();
    setDistrictItems(ui, endpointDataRetainer, ui->comboBox_infections_DistrictSelector, currentState, currentDistrict);
    setInfectionsGraphData();
}

void MainWindow::on_comboBox_infections_DistrictSelector_currentIndexChanged(int index)
{
    Q_UNUSED(index);
    setInfectionsGraphData();
}

void MainWindow::on_pushButton_settings_save_clicked()
{
    saveSettingsUser(ui);
}

void MainWindow::exportCSV(QAbstractItemView *view)
{
    QString csv;
    QAbstractItemModel *model = view->model();
    int rows = model->rowCount();
    int columns = model->columnCount();
    QString inlineSeparator = ";";
    QString lineSeparator = "\n";

    for (int c = 0; c < columns; ++c)
    {
        csv += model->headerData(c, Qt::Orientation::Horizontal, Qt::EditRole).toString();
        if (c != columns - 1)
            csv += inlineSeparator;
    }
    csv += lineSeparator;

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            csv += model->data(model->index(i, j)).toString();
            if (j != columns - 1)
                csv += inlineSeparator;
        }
        if (i != rows - 1)
            csv += lineSeparator;
    }
    QString defaultFileName(tr("Informationen"));
    if (view->objectName().compare(ui->tableViewLand->objectName()) == 0)
    {
        defaultFileName = tr("Bundesländer");
    } else if (view->objectName().compare(ui->tableViewKreis->objectName()) == 0)
    {
        defaultFileName = tr("Landkreise");
    }
    defaultFileName += "_" + QDate::currentDate().toString("yyyy_MM_dd");
    QString fileName = QFileDialog::getSaveFileName(this, tr("Datei zum Speichers auswählen"), defaultFileName, tr("Comma-separated file (*.csv)"));

    if (fileName.isEmpty())
        return;
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::information(this, tr("Datei kann nicht gespeichert werden"), file.errorString());
        return;
    }
    QTextStream out(&file);
    out.setEncoding(QStringConverter::Encoding::Utf8);
    out << csv;
}

void MainWindow::on_exportStatesAsCSVButton_clicked()
{
    exportCSV(ui->tableViewLand);
}

void MainWindow::on_exportDistrictsAsCSVButton_clicked()
{
    exportCSV(ui->tableViewKreis);
}

void MainWindow::setVaccinationHistoryGraphData(QChart *chart, QVector<VaccinationHistoryData> *data, QString graphTitle)
{
    if (data == nullptr || chart == nullptr)
    {
        return;
    }

    chart->removeAllSeries();
    const auto chartAxes = chart->axes();
    for (auto it = chartAxes.begin(); it != chartAxes.end(); ++it)
    {
        chart->removeAxis(*it);
    }

    QLineSeries *totalVaccinated = new QLineSeries();
    QLineSeries *secondVaccinated = new QLineSeries();
    QLineSeries *boosterVaccinated = new QLineSeries();
    QDateTimeAxis *xAxis = new QDateTimeAxis();
    QValueAxis *yAxis = new QValueAxis();
    double minVaccinated = DBL_MAX;
    double maxVaccinated = DBL_MIN;

    QDateTime minDateTime;
    QDateTime maxDateTime;

    int totalVaccinations = 0;
    int secondVaccinations = 0;
    int boosterVaccinations = 0;

    for (const auto &d : *data)
    {
        totalVaccinations += d.firstVaccination;
        secondVaccinations += d.secondVaccination;
        boosterVaccinations += d.boosterVaccination;
        *totalVaccinated << QPointF(d.date.toMSecsSinceEpoch(), totalVaccinations);
        *secondVaccinated << QPointF(d.date.toMSecsSinceEpoch(), secondVaccinations);
        *boosterVaccinated << QPointF(d.date.toMSecsSinceEpoch(), boosterVaccinations);
        minVaccinated = totalVaccinations < minVaccinated ? totalVaccinations : minVaccinated;
        maxVaccinated = totalVaccinations > maxVaccinated ? totalVaccinations : maxVaccinated;
        minDateTime =  minDateTime.isNull() || d.date < minDateTime ? QDateTime::fromMSecsSinceEpoch(d.date.toMSecsSinceEpoch()) : minDateTime;
        maxDateTime = maxDateTime.isNull() || d.date > maxDateTime ? QDateTime::fromMSecsSinceEpoch(d.date.toMSecsSinceEpoch()) : maxDateTime;
    }

    totalVaccinated->setName(tr("Geimpfte insgesamt"));
    secondVaccinated->setName(tr("Zweitgeimpfte"));
    boosterVaccinated->setName(tr("Booster-Impfungen"));

    xAxis->setRange(minDateTime, maxDateTime);
    xAxis->setFormat(tr("dd.MM.yyyy"));
    xAxis->setTitleText(tr("Datum"));
    yAxis->setLabelFormat("%'d");
    yAxis->setRange(minVaccinated, maxVaccinated);
    yAxis->applyNiceNumbers();
    yAxis->setTickCount(11);
    yAxis->setMinorTickCount(0);
    yAxis->setTitleText(tr("Personen"));

    QPen pen(0x80ba24);
    pen.setWidth(3);
    totalVaccinated->setPen(pen);

    chart->setTitle(tr(graphTitle.toStdString().c_str()));
    chart->addSeries(totalVaccinated);
    chart->addSeries(secondVaccinated);
    chart->addSeries(boosterVaccinated);
    chart->addAxis(xAxis, Qt::AlignBottom);
    chart->addAxis(yAxis, Qt::AlignLeft);


    totalVaccinated->attachAxis(xAxis);
    totalVaccinated->attachAxis(yAxis);
    secondVaccinated->attachAxis(xAxis);
    secondVaccinated->attachAxis(yAxis);
    boosterVaccinated->attachAxis(xAxis);
    boosterVaccinated->attachAxis(yAxis);

    connect(totalVaccinated, &QLineSeries::hovered, this, &MainWindow::infectionsGraphPointHovered);
    connect(secondVaccinated, &QLineSeries::hovered, this, &MainWindow::infectionsGraphPointHovered);
    connect(boosterVaccinated, &QLineSeries::hovered, this, &MainWindow::infectionsGraphPointHovered);
}

void MainWindow::on_comboBox_settings_language_currentIndexChanged(int index)
{
    Q_UNUSED(index);
    // translate application
    QString currentLanguage = ui->comboBox_settings_language->currentText();
    bool success = changeLanguage(currentLanguage);
    // redraw UI to use changed language
    if (success)
    {
        setOverviewGraphData();
        setInfectionsGraphData();
        fillTableViewDistricts();
        fillTableViewStates();
        QString state = ui->comboBox_settings_state->currentText();
        if (!state.isEmpty())
            ui->label_OV_B_Name->setText(state);
        QString district = ui->comboBox_settings_county->currentText();
        if (!district.isEmpty())
            ui->label_OV_L_Name->setText(district);
        setStyleItems(ui);
        setStateItems(ui, &endpointDataRetainer.getStatesEndpointData(), state);
        setDistrictItems(ui, endpointDataRetainer, ui->comboBox_infections_DistrictSelector, state, district);
        setDistrictItems(ui, endpointDataRetainer, ui->comboBox_infections_DistrictSelector, state, district);
        setDataSetItems(ui);
        receiveGermanyEndpointData(&endpointDataRetainer.getGermanyEndpointData());
    }
}

bool MainWindow::changeLanguage(const QString &newLanguage, const QString &defaultLanguage)
{
    // load translation if available
    qApp->removeTranslator(&translator);
    bool success = translator.load(QString("://CoviDusWidget_") + newLanguage, qApp->applicationDirPath());
    if (success)
    {
        qApp->installTranslator(&translator);
        qApp->processEvents();
        qDebug()<< "Change language: " + newLanguage + " success!";
        this->ui->retranslateUi(this);
    }
    else
    {
        qDebug()<< "Change language: " + newLanguage + " failed, setting back to " + defaultLanguage;
        changeLanguage(defaultLanguage, defaultLanguage);
    }
    return success;
}
