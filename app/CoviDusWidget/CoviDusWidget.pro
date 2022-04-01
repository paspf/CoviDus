QT += core gui
QT += charts
QT += network
QT += concurrent

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    endpointdataretainer.cpp \
    endpointretainer.cpp \
    endpoints/agegroupdata.cpp \
    endpoints/deltadata.cpp \
    endpoints/districts/districtsendpoint.cpp \
    endpoints/districts/districtsendpointdata.cpp \
    endpoints/districts/districtsendpointdatainformation.cpp \
    endpoints/districts/districtshistorycasesendpoint.cpp \
    endpoints/districts/districtshistorycasesendpointdata.cpp \
    endpoints/districts/districtshistorycasesendpointdatainformation.cpp \
    endpoints/districts/districtshistorydeathsendpoint.cpp \
    endpoints/districts/districtshistorydeathsendpointdata.cpp \
    endpoints/districts/districtshistorydeathsendpointdatainformation.cpp \
    endpoints/districts/districtshistoryfrozenincidenceendpoint.cpp \
    endpoints/districts/districtshistoryfrozenincidenceendpointdata.cpp \
    endpoints/districts/districtshistoryfrozenincidenceendpointdatainformation.cpp \
    endpoints/districts/districtshistoryincidenceendpoint.cpp \
    endpoints/districts/districtshistoryincidenceendpointdata.cpp \
    endpoints/districts/districtshistoryincidenceendpointdatainformation.cpp \
    endpoints/districts/districtshistoryrecoveredendpoint.cpp \
    endpoints/districts/districtshistoryrecoveredendpointdata.cpp \
    endpoints/districts/districtshistoryrecoveredendpointdatainformation.cpp \
    endpoints/endpoint.cpp \
    endpoints/germany/germanyagegroupsendpoint.cpp \
    endpoints/germany/germanyagegroupsendpointdata.cpp \
    endpoints/germany/germanyagegroupsendpointdatainformation.cpp \
    endpoints/germany/germanyendpoint.cpp \
    endpoints/germany/germanyendpointdata.cpp \
    endpoints/germany/germanyhistorycasesendpoint.cpp \
    endpoints/germany/germanyhistorycasesendpointdata.cpp \
    endpoints/germany/germanyhistorydeathsendpoint.cpp \
    endpoints/germany/germanyhistorydeathsendpointdata.cpp \
    endpoints/germany/germanyhistoryincidenceendpoint.cpp \
    endpoints/germany/germanyhistoryincidenceendpointdata.cpp \
    endpoints/germany/germanyhistoryrecoveredendpoint.cpp \
    endpoints/germany/germanyhistoryrecoveredendpointdata.cpp \
    endpoints/historydata.cpp \
    endpoints/legendinfo.cpp \
    endpoints/map/mapdistrictsendpoint.cpp \
    endpoints/map/mapdistrictslegendendpoint.cpp \
    endpoints/map/mapstatesendpoint.cpp \
    endpoints/map/mapstateslegendendpoint.cpp \
    endpoints/states/statesagegroupsendpoint.cpp \
    endpoints/states/statesagegroupsendpointdata.cpp \
    endpoints/states/statesagegroupsendpointdatainformation.cpp \
    endpoints/states/statesendpoint.cpp \
    endpoints/states/statesendpointdata.cpp \
    endpoints/states/statesendpointdatainformation.cpp \
    endpoints/states/stateshistorycasesendpoint.cpp \
    endpoints/states/stateshistorycasesendpointdata.cpp \
    endpoints/states/stateshistorycasesendpointdatainformation.cpp \
    endpoints/states/stateshistorydeathsendpoint.cpp \
    endpoints/states/stateshistorydeathsendpointdata.cpp \
    endpoints/states/stateshistorydeathsendpointdatainformation.cpp \
    endpoints/states/stateshistoryincidenceendpoint.cpp \
    endpoints/states/stateshistoryincidenceendpointdata.cpp \
    endpoints/states/stateshistoryincidenceendpointdatainformation.cpp \
    endpoints/states/stateshistoryrecoveredendpoint.cpp \
    endpoints/states/stateshistoryrecoveredendpointdata.cpp \
    endpoints/states/stateshistoryrecoveredendpointdatainformation.cpp \
    endpoints/vaccinationdata.cpp \
    endpoints/vaccinationhistorydata.cpp \
    endpoints/vaccinations/vaccinationsendpoint.cpp \
    endpoints/vaccinations/vaccinationsendpointdata.cpp \
    endpoints/vaccinations/vaccinationsendpointdatainformation.cpp \
    endpoints/vaccinations/vaccinationshistoryendpoint.cpp \
    endpoints/vaccinations/vaccinationshistoryendpointdata.cpp \
    eventthread.cpp \
    main.cpp \
    mainwindow.cpp \
    endpoints/metadata.cpp \
    endpoints/rdata.cpp \
    qimagelabel.cpp \
    qimagewithlegend.cpp \
    ui/util/comboboxes.cpp \
    ui/util/settings.cpp

HEADERS += \
    endpointdataretainer.h \
    endpointretainer.h \
    endpoints/agegroupdata.h \
    endpoints/deltadata.h \
    endpoints/districts/districtsendpoint.h \
    endpoints/districts/districtsendpointdata.h \
    endpoints/districts/districtsendpointdatainformation.h \
    endpoints/districts/districtshistorycasesendpoint.h \
    endpoints/districts/districtshistorycasesendpointdata.h \
    endpoints/districts/districtshistorycasesendpointdatainformation.h \
    endpoints/districts/districtshistorydeathsendpoint.h \
    endpoints/districts/districtshistorydeathsendpointdata.h \
    endpoints/districts/districtshistorydeathsendpointdatainformation.h \
    endpoints/districts/districtshistoryfrozenincidenceendpoint.h \
    endpoints/districts/districtshistoryfrozenincidenceendpointdata.h \
    endpoints/districts/districtshistoryfrozenincidenceendpointdatainformation.h \
    endpoints/districts/districtshistoryincidenceendpoint.h \
    endpoints/districts/districtshistoryincidenceendpointdata.h \
    endpoints/districts/districtshistoryincidenceendpointdatainformation.h \
    endpoints/districts/districtshistoryrecoveredendpoint.h \
    endpoints/districts/districtshistoryrecoveredendpointdata.h \
    endpoints/districts/districtshistoryrecoveredendpointdatainformation.h \
    endpoints/endpoint.h \
    endpoints/germany/germanyagegroupsendpoint.h \
    endpoints/germany/germanyagegroupsendpointdata.h \
    endpoints/germany/germanyagegroupsendpointdatainformation.h \
    endpoints/germany/germanyendpoint.h \
    endpoints/germany/germanyendpointdata.h \
    endpoints/germany/germanyhistorycasesendpoint.h \
    endpoints/germany/germanyhistorycasesendpointdata.h \
    endpoints/germany/germanyhistorydeathsendpoint.h \
    endpoints/germany/germanyhistorydeathsendpointdata.h \
    endpoints/germany/germanyhistoryincidenceendpoint.h \
    endpoints/germany/germanyhistoryincidenceendpointdata.h \
    endpoints/germany/germanyhistoryrecoveredendpoint.h \
    endpoints/germany/germanyhistoryrecoveredendpointdata.h \
    endpoints/historydata.h \
    endpoints/legendinfo.h \
    endpoints/map/mapdistrictsendpoint.h \
    endpoints/map/mapdistrictslegendendpoint.h \
    endpoints/map/mapstatesendpoint.h \
    endpoints/map/mapstateslegendendpoint.h \
    endpoints/states/statesagegroupsendpoint.h \
    endpoints/states/statesagegroupsendpointdata.h \
    endpoints/states/statesagegroupsendpointdatainformation.h \
    endpoints/states/statesendpoint.h \
    endpoints/states/statesendpointdata.h \
    endpoints/states/statesendpointdatainformation.h \
    endpoints/states/stateshistorycasesendpoint.h \
    endpoints/states/stateshistorycasesendpointdata.h \
    endpoints/states/stateshistorycasesendpointdatainformation.h \
    endpoints/states/stateshistorydeathsendpoint.h \
    endpoints/states/stateshistorydeathsendpointdata.h \
    endpoints/states/stateshistorydeathsendpointdatainformation.h \
    endpoints/states/stateshistoryincidenceendpoint.h \
    endpoints/states/stateshistoryincidenceendpointdata.h \
    endpoints/states/stateshistoryincidenceendpointdatainformation.h \
    endpoints/states/stateshistoryrecoveredendpoint.h \
    endpoints/states/stateshistoryrecoveredendpointdata.h \
    endpoints/states/stateshistoryrecoveredendpointdatainformation.h \
    endpoints/vaccinationdata.h \
    endpoints/vaccinationhistorydata.h \
    endpoints/vaccinations/vaccinationsendpoint.h \
    endpoints/vaccinations/vaccinationsendpointdata.h \
    endpoints/vaccinations/vaccinationsendpointdatainformation.h \
    endpoints/vaccinations/vaccinationshistoryendpoint.h \
    endpoints/vaccinations/vaccinationshistoryendpointdata.h \
    eventthread.h \
    mainwindow.h \
    endpoints/metadata.h \
    endpoints/rdata.h \
    qimagelabel.h \
    qimagewithlegend.h \
    ui/DataSetValue.h \
    ui/Style.h \
    ui/util/comboboxes.h \
    ui/util/settings.h

FORMS += \
    mainwindow.ui \
    qimagewithlegend.ui

TRANSLATIONS += \
    CoviDusWidget_de.ts \
    CoviDusWidget_en.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    CoviDusWidget_de.ts \
    CoviDusWidget_en.ts

RESOURCES += \
    images.qrc \
    translations.qrc

RC_ICONS = CoviDusIcon.ico
