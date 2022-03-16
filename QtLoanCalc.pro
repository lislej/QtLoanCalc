QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    amortsched.cpp \
    loancalc_main.cpp \
    loancalcservicehandler.cpp \
    loancalcstruct.cpp \
    loancalculator.cpp \
    loancalcworker.cpp \
    loancalcwin.cpp \
    versionhandler.cpp \
    versionworker.cpp \
    wsdl_LoanCalcService.cpp \
    wsdl_LoanCalcVerify.cpp

HEADERS += \
    amortsched.h \
    loancalcservicehandler.h \
    loancalcstruct.h \
    loancalculator.h \
    loancalcwin.h \
    loancalcworker.h \
    versionhandler.h \
    versionworker.h \
    wsdl_LoanCalcService.h \
    wsdl_LoanCalcVerify.h

FORMS += \
    loancalcwin.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../dvlp/KDSoap/build/lib/release/ -lkdsoap2d
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../dvlp/KDSoap/build/lib/debug/ -lkdsoap2d

INCLUDEPATH += $$PWD/../../../../../../dvlp/KDSoap/src
DEPENDPATH += $$PWD/../../../../../../dvlp/KDSoap/src

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../dvlp/KDSoap/build/lib/release/kdsoap2d.lib
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../dvlp/KDSoap/build/lib/debug/kdsoap2d.lib

DISTFILES += \
    LoanCalcService.wsdl \
    LoanCalcVerify.wsdl
