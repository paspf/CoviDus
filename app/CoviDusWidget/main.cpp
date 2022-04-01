#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // open main window
    MainWindow w;
    w.show();
    return a.exec();
}
