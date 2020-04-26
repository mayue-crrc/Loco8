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
    mvbcx/MVBC02C/BBD_C02C.c \
    mvbcx/MVBC02C/bus_opt.c \
    mvbcx/MVBC02C/os_hal.c \
    mvbcx/c_mvbsock.cpp \
    cxExtDev/blacklightthread.cpp \
    cxExtDev/externaldevicelib.cpp \
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
    data/data_bcu.cpp

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
    mvbcx/MVBC02C/BBD_C02C.h \
    mvbcx/MVBC02C/bus_opt.h \
    mvbcx/MVBC02C/C02C_Def.h \
    mvbcx/MVBC02C/mue_pd_full.h \
    mvbcx/MVBC02C/os_hal.h \
    mvbcx/MVBC02C/tcn_def.h \
    mvbcx/c_mvbsock.h \
    cxExtDev/blacklightthread.h \
    cxExtDev/externaldevicelib.h \
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
    data/data_bcu.h

FORMS    += widget.ui \
    header.ui \
    navigator.ui \
    vehiclerunstatepage.ui \
    maindata_trainoutline.ui \
    settng_bypass.ui \
    simulation.ui \
    datainputwheelpage.ui \
    datainputdatetimepage.ui \
    datainputother.ui \
    datainputidpage.ui\
    devicedata_online.ui

RESOURCES += \
    Resource.qrc

OTHER_FILES += \
    log4qt/log4qt.pri \
    log4qt/Log4Qt.pri
