#-------------------------------------------------
#
# Project created by QtCreator 2017-07-25T15:35:43
#
#-------------------------------------------------
TRANSLATIONS += language_en.ts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
DEFINES += USER_DEBUG_MODE

QT       += core gui
QT += sql
QT += network
TARGET = Loco8
TEMPLATE = app


LIBS += -L$$PWD/../../../lib/ -lsqlite3
INCLUDEPATH += $$PWD/../../../
DEPENDPATH += $$PWD/../../../

INCLUDEPATH += ./ss2xdd_2/drvkits/libs/linux_x86/inc


DEPENDPATH += . log4qt log4qt/helpers log4qt/spi log4qt/varia
INCLUDEPATH += . log4qt log4qt/helpers log4qt/spi log4qt/varia

SOURCES += main.cpp\
        widget.cpp \
    mybase.cpp \
    database.cpp \
    header.cpp \
    MainGetDefaultPara.cpp \
    navigator.cpp \
    vehiclerunstatepage.cpp \
    log4qt/writerappender.cpp \
    log4qt/ttcclayout.cpp \
    log4qt/simplelayout.cpp \
    log4qt/rollingfileappender.cpp \
    log4qt/propertyconfigurator.cpp \
    log4qt/patternlayout.cpp \
    log4qt/ndc.cpp \
    log4qt/mdc.cpp \
    log4qt/logmanager.cpp \
    log4qt/loggingevent.cpp \
    log4qt/loggerrepository.cpp \
    log4qt/logger.cpp \
    log4qt/log4qt.cpp \
    log4qt/level.cpp \
    log4qt/layout.cpp \
    log4qt/hierarchy.cpp \
    log4qt/fileappender.cpp \
    log4qt/dailyrollingfileappender.cpp \
    log4qt/consoleappender.cpp \
    log4qt/basicconfigurator.cpp \
    log4qt/appenderskeleton.cpp \
    log4qt/helpers/properties.cpp \
    log4qt/helpers/patternformatter.cpp \
    log4qt/helpers/optionconverter.cpp \
    log4qt/helpers/logobjectptr.cpp \
    log4qt/helpers/logobject.cpp \
    log4qt/helpers/logerror.cpp \
    log4qt/helpers/initialisationhelper.cpp \
    log4qt/helpers/factory.cpp \
    log4qt/helpers/datetime.cpp \
    log4qt/helpers/configuratorhelper.cpp \
    log4qt/helpers/classlogger.cpp \
    log4qt/spi/filter.cpp \
    log4qt/varia/stringmatchfilter.cpp \
    log4qt/varia/nullappender.cpp \
    log4qt/varia/listappender.cpp \
    log4qt/varia/levelrangefilter.cpp \
    log4qt/varia/levelmatchfilter.cpp \
    log4qt/varia/denyallfilter.cpp \
    log4qt/varia/debugappender.cpp \
    crrcfaultmapper.cpp \
    crrcfault.cpp \
    crrcmvb.cpp \
    faulttypebean.cpp \
    faultbean.cpp \
    log4qt/log4qt_init.cpp \
    data/data_ccu.cpp \
    maindata_trainoutline.cpp \
    settng_bypass.cpp \
    data/data_tcn.cpp \
    data/trainbean.cpp \
    simulation.cpp \
    datainputwheelpage.cpp \
    datainputdatetimepage.cpp \
    datainputother.cpp \
    datainputidpage.cpp\
    devicedata_online.cpp\
    data/data_tcu.cpp \
    data/data_riom.cpp \
    data/data_acu.cpp \
    data/data_bcu.cpp \
    devicedata_acu.cpp \
    devicedata_mainconv.cpp \
    devicedata_breaker.cpp \
    devicedata_version.cpp \
    devicedata_io.cpp \
    settng_test.cpp \
    settng_panto.cpp \
    settng_distance.cpp\
    datainputcalibratepage.cpp \
    datainputlubricatepage.cpp \
    datainputsplitlinepage.cpp \
    buttonrectutil.cpp\
    widgets/ctrlcontrolvoltage.cpp \
    widgets/ctrlnetcurrent.cpp \
    widgets/ctrlnetvoltage.cpp \
    widgets/ctrltracbrake.cpp \
    widgets/ctrltrainoutline.cpp \
    widgets/ctrltrainoutlinereverse.cpp \
    devicedata_trainoutline.cpp \
    fault_history.cpp \
    main_allportdata.cpp\
    main_simulate.cpp \
    main_lubrication.cpp \
    main_assistantdevice.cpp \
    main_380.cpp \
    main_separation.cpp \
    main_doublepanto.cpp \
    widgets/ctrldialog.cpp \
    devicedata_tracbrakeoutline.cpp \
    fault_current.cpp \
    fault_detail.cpp \
    mvb_cls.cpp

HEADERS  += widget.h \
    mybase.h \
    database.h \
    global.h \
    header.h \
    MainGetDefaultPara.h \
    navigator.h \
    vehiclerunstatepage.h \
    log4qt/writerappender.h \
    log4qt/ttcclayout.h \
    log4qt/simplelayout.h \
    log4qt/rollingfileappender.h \
    log4qt/propertyconfigurator.h \
    log4qt/patternlayout.h \
    log4qt/ndc.h \
    log4qt/mdc.h \
    log4qt/logmanager.h \
    log4qt/loggingevent.h \
    log4qt/loggerrepository.h \
    log4qt/logger.h \
    log4qt/log4qt.h \
    log4qt/level.h \
    log4qt/layout.h \
    log4qt/hierarchy.h \
    log4qt/fileappender.h \
    log4qt/dailyrollingfileappender.h \
    log4qt/consoleappender.h \
    log4qt/basicconfigurator.h \
    log4qt/appenderskeleton.h \
    log4qt/appender.h \
    log4qt/helpers/properties.h \
    log4qt/helpers/patternformatter.h \
    log4qt/helpers/optionconverter.h \
    log4qt/helpers/logobjectptr.h \
    log4qt/helpers/logobject.h \
    log4qt/helpers/logerror.h \
    log4qt/helpers/initialisationhelper.h \
    log4qt/helpers/factory.h \
    log4qt/helpers/datetime.h \
    log4qt/helpers/configuratorhelper.h \
    log4qt/helpers/classlogger.h \
    log4qt/spi/filter.h \
    log4qt/varia/stringmatchfilter.h \
    log4qt/varia/nullappender.h \
    log4qt/varia/listappender.h \
    log4qt/varia/levelrangefilter.h \
    log4qt/varia/levelmatchfilter.h \
    log4qt/varia/denyallfilter.h \
    log4qt/varia/debugappender.h \
    crrcfaultmapper.h \
    crrcfault.h \
    crrcmvb.h \
    faulttypebean.h \
    faultbean.h \
    log4qt/custom.h \
    data/data_ccu.h \
    maindata_trainoutline.h \
    settng_bypass.h \
    data/data_tcn.h \
    data/trainbean.h \
    simulation.h \
    datainputwheelpage.h \
    datainputdatetimepage.h \
    datainputother.h \
    datainputidpage.h\
    devicedata_online.h\
    data/data_tcu.h \
    data/data_riom.h \
    data/data_acu.h \
    data/data_bcu.h \
    devicedata_acu.h \
    devicedata_mainconv.h \
    devicedata_breaker.h \
    devicedata_version.h \
    devicedata_io.h \
    settng_test.h \
    settng_panto.h \
    settng_distance.h\
    datainputcalibratepage.h \
    datainputlubricatepage.h \
    datainputsplitlinepage.h \
    buttonrectutil.h\
    widgets/ctrlcontrolvoltage.h \
    widgets/ctrlnetcurrent.h \
    widgets/ctrlnetvoltage.h \
    widgets/ctrltracbrake.h \
    widgets/ctrltrainoutline.h \
    widgets/ctrltrainoutlinereverse.h \
    devicedata_trainoutline.h \
    fault_history.h \
    main_allportdata.h\
    main_simulate.h \
    main_lubrication.h \
    main_assistantdevice.h \
    main_380.h \
    main_separation.h \
    main_doublepanto.h \
    widgets/ctrldialog.h \
    devicedata_tracbrakeoutline.h \
    fault_current.h \
    fault_detail.h \
    mvb_cls.h

FORMS    += widget.ui \
header.ui \
    navigator.ui \
    vehiclerunstatepage.ui \
    maindata_trainoutline.ui \
    settng_bypass.ui \
    simulation.ui \
    devicedata_online.ui \
    devicedata_acu.ui \
    devicedata_mainconv.ui \
    devicedata_breaker.ui \
    devicedata_version.ui \
    devicedata_io.ui \
    settng_test.ui \
    settng_panto.ui \
    settng_distance.ui\
    datainputwheelpage.ui \
    datainputdatetimepage.ui \
    datainputother.ui \
    datainputidpage.ui\
    devicedata_online.ui \
    datainputcalibratepage.ui \
    datainputlubricatepage.ui \
    datainputsplitlinepage.ui \
    buttonrectutil.ui\
    widgets/ctrlcontrolvoltage.ui \
    widgets/ctrlnetcurrent.ui \
    widgets/ctrlnetvoltage.ui \
    widgets/ctrltracbrake.ui \
    widgets/ctrltrainoutline.ui \
    widgets/ctrltrainoutlinereverse.ui \
    devicedata_trainoutline.ui \
    fault_history.ui \
    main_allportdata.ui\
    main_simulate.ui \
    main_lubrication.ui \
    main_assistantdevice.ui \
    main_380.ui \
    main_separation.ui \
    main_doublepanto.ui \
    widgets/ctrldialog.ui \
    devicedata_tracbrakeoutline.ui \
    fault_current.ui \
    fault_detail.ui

RESOURCES += \
    Resource.qrc

OTHER_FILES += \
    log4qt/log4qt.pri \
    log4qt/Log4Qt.pri

if(!contains(DEFINES, USER_DEBUG_MODE)){

unix:!macx: LIBS += -L$$PWD/ss2xdd_2/lib/ -lclt_drv

INCLUDEPATH += $$PWD/ss2xdd_2
DEPENDPATH += $$PWD/ss2xdd_2

unix:!macx: PRE_TARGETDEPS += $$PWD/ss2xdd_2/lib/libclt_drv.a

unix:!macx: LIBS += -L$$PWD/ss2xdd_2/lib/ -lssmv2xdd_linux

INCLUDEPATH += $$PWD/ss2xdd_2
DEPENDPATH += $$PWD/ss2xdd_2

unix:!macx: PRE_TARGETDEPS += $$PWD/ss2xdd_2/lib/libssmv2xdd_linux.a
LIBS += -lcurses

}






