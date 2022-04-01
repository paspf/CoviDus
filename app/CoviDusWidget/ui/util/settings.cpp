#include "ui/util/settings.h"
#include <QStyleFactory>

void restoreSettings(MainWindow *mainWindow)
{
    QSettings settings(appManufacturer, appName);

    settings.beginGroup("window");
    mainWindow->restoreGeometry(settings.value("geometry").toByteArray());
    mainWindow->restoreState(settings.value("windowState").toByteArray());
    settings.endGroup();
}

void restoreSettingsUser(Ui::MainWindow *ui)
{
    QSettings settings(appManufacturer, appName);
    settings.beginGroup("settings/user");
    Style s = settings.value("style", QVariant::fromValue(Style::BRIGHT)).value<Style>();
    ui->comboBox_settings_style->setCurrentIndex((int)s);

    ui->comboBox_settings_server->setCurrentText(settings.value("server", EndpointRetainer::baseUrlRKI).toString());
    settings.endGroup();
    restoreSettingsUserState(ui);
    restoreSettingsUserDistrict(ui);
    restoreSettingsUserLanguage(ui);
}

void restoreSettingsUserState(Ui::MainWindow *ui)
{
    QSettings settings(appManufacturer, appName);
    settings.beginGroup("settings/user");
    ui->comboBox_settings_state->setCurrentText(settings.value("state", "Hessen").toString());
    ui->comboBox_infections_StateSelector->setCurrentText(settings.value("state", "Hessen").toString());
    settings.endGroup();
}

void restoreSettingsUserDistrict(Ui::MainWindow *ui)
{
    QSettings settings(appManufacturer, appName);
    settings.beginGroup("settings/user");
    ui->comboBox_settings_county->setCurrentText(settings.value("county", "Gießen").toString());
    ui->comboBox_infections_DistrictSelector->setCurrentText(settings.value("county", "Gießen").toString());
    settings.endGroup();
}

void restoreSettingsUserLanguage(Ui::MainWindow *ui)
{
    QSettings settings(appManufacturer, appName);
    settings.beginGroup("settings/user");
    QString locale = settings.value("language", "0").toString();
    if (locale == "0") {
        locale = QLocale::system().name();
        QStringList localeParts = locale.split("_");
        locale = localeParts[0];
    }
    bool localeFound = false;
    // Check if language item exists within combo box
    for (int index = 0; index < ui->comboBox_settings_language->count(); index++)
        if (ui->comboBox_settings_language->itemText(index) == locale) {
            ui->comboBox_settings_language->setCurrentText(locale);
            localeFound = true;
            break;
        }
    if (!localeFound) {
        ui->comboBox_settings_language->setCurrentText("en");
    }

    settings.endGroup();
}

void saveSettingsOnClose(MainWindow *mainWindow)
{
    QSettings settings(appManufacturer, appName);
    settings.beginGroup("window");
    settings.setValue("geometry", mainWindow->saveGeometry());
    settings.setValue("windowState", mainWindow->saveState());
    settings.endGroup();
}

void saveSettingsUser(Ui::MainWindow *ui)
{
    QSettings settings(appManufacturer, appName);
    settings.beginGroup("settings/user");
    settings.setValue("state", ui->comboBox_settings_state->currentText());
    settings.setValue("county", ui->comboBox_settings_county->currentText());

    settings.setValue("style", (int) ui->comboBox_settings_style->currentData().value<Style>());
    settings.setValue("server", ui->comboBox_settings_server->currentText());
    settings.setValue("language", ui->comboBox_settings_language->currentText());
    settings.endGroup();
}

void enableQtDefaultStyle(MainWindow *mainWindow, Ui::MainWindow *ui)
{
    qApp->setStyle(QStyleFactory::create("Fusion"));
    qApp->setPalette(mainWindow->style()->standardPalette());
    qApp->setStyleSheet("");

    // GraphicViews
    ui->graphicsView_OV_1->chart()->setTheme(QChart::ChartThemeHighContrast);
    ui->graphicsView_infections_1->chart()->setTheme(QChart::ChartThemeHighContrast);

    mainWindow->setInfectionsGraphData();
    mainWindow->setOverviewGraphData();

    qApp->processEvents();
    mainWindow->repaint();
}

void enableDarkModeStyle(MainWindow *mainWindow, Ui::MainWindow *ui)
{
    qApp->setStyle(QStyleFactory::create("Fusion"));
    QPalette darkPalette;
    QColor darkColor = QColor(45,45,45);
    QColor disabledColor = QColor(127,127,127);

    darkPalette.setColor(QPalette::Window, darkColor);
    darkPalette.setColor(QPalette::WindowText, Qt::white);
    darkPalette.setColor(QPalette::Base, QColor(18,18,18));
    darkPalette.setColor(QPalette::AlternateBase, darkColor);
    darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
    darkPalette.setColor(QPalette::ToolTipText, Qt::white);
    darkPalette.setColor(QPalette::Text, Qt::white);
    darkPalette.setColor(QPalette::Disabled, QPalette::Text, disabledColor);
    darkPalette.setColor(QPalette::Button, darkColor);
    darkPalette.setColor(QPalette::ButtonText, Qt::white);
    darkPalette.setColor(QPalette::Disabled, QPalette::ButtonText, disabledColor);
    darkPalette.setColor(QPalette::BrightText, Qt::red);
    darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));

    darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::HighlightedText, Qt::black);
    darkPalette.setColor(QPalette::Disabled, QPalette::HighlightedText, disabledColor);

    qApp->setPalette(darkPalette);

    qApp->setStyleSheet("QToolTip { color: #ffffff; background-color: #2a82da; border: 1px solid white; }");

    // GraphicViews
    ui->graphicsView_OV_1->chart()->setTheme(QChart::ChartThemeDark);
    ui->graphicsView_infections_1->chart()->setTheme(QChart::ChartThemeDark);

    // TextViews
    ui->textBrowser_settings_license->setPalette(darkPalette);

    // Tables
    ui->tableViewKreis->setPalette(darkPalette);
    ui->tableViewLand->setPalette(darkPalette);

    // ComboBoxes
    ui->comboBox_infections_DataSetSelector->setPalette(darkPalette);
    ui->comboBox_infections_StateSelector->setPalette(darkPalette);
    ui->comboBox_infections_DistrictSelector->setPalette(darkPalette);
    ui->comboBox_settings_state->setPalette(darkPalette);
    ui->comboBox_settings_county->setPalette(darkPalette);
    ui->comboBox_settings_style->setPalette(darkPalette);
    ui->comboBox_settings_language->setPalette(darkPalette);
    ui->comboBox_settings_server->setPalette(darkPalette);

    mainWindow->setInfectionsGraphData();
    mainWindow->setOverviewGraphData();

    qApp->processEvents();
    mainWindow->repaint();
}
