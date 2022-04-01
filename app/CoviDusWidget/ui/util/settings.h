#ifndef SETTINGS_H
#define SETTINGS_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <QSettings>
#include "ui/Style.h"
#include "endpointretainer.h"

inline static const QString appName = "CoviDus";
inline static const QString appManufacturer = "JJP";

/**
 * @brief MainWindow::restoreSettings
 * @param mainWindow
 * Restore window settings.
 */
void restoreSettings(MainWindow *mainWindow);
/**
 * @brief MainWindow::restoreSettingsUser
 * @param ui mainwindow
 * Restore user settings.
 */
void restoreSettingsUser(Ui::MainWindow *ui);/**
 * @brief MainWindow::restoreSettingsUserState reads and applies saved selected state (from registry settings)
 * @param ui mainwindow
 */
void restoreSettingsUserState(Ui::MainWindow *ui);
/**
 * @brief MainWindow::restoreSettingsUserDistrict reads and applies saved selected district (from registry settings)
 * @param ui mainwindow
 */
void restoreSettingsUserDistrict(Ui::MainWindow *ui);
/**
 * @brief MainWindow::restoreSettingsUserLanguage reads and applies saved UI language (from registry settings)
 * @param ui mainwindow
 */
void restoreSettingsUserLanguage(Ui::MainWindow *ui);
/**
 * @brief MainWindow::saveSettings
 * @param ui mainwindow
 * Save Window state, geometry and position.
 */
void saveSettingsOnClose(MainWindow *mainWindow);
/**
 * @brief MainWindow::saveSettingsUser
 * @param mainWindow
 * Save user settings.
 */
void saveSettingsUser(Ui::MainWindow *ui);
/**
 * @brief MainWindow::enableQtDefaultStyle enables standard UI style
 * @param mainWindow
 * @param ui mainwindow
 */
void enableQtDefaultStyle(MainWindow *mainWindow, Ui::MainWindow *ui);
/**
 * @brief MainWindow::enableDarkModeStyle enables dark UI mode
 * @param ui mainwindow
 */
void enableDarkModeStyle(MainWindow *mainWindow, Ui::MainWindow *ui);

#endif // SETTINGS_H
