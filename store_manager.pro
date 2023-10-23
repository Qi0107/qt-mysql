QT       += core gui sql testlib



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    button.cpp \
    findpassword.cpp \
    main.cpp \
    new_stock.cpp \
    power_warnning.cpp \
    question.cpp \
    stock_system.cpp \
    store_manager.cpp \
    test64.cpp

HEADERS += \
    button.h \
    findpassword.h \
    new_stock.h \
    power_warnning.h \
    question.h \
    stock_system.h \
    store_manager.h \
    test64.h

FORMS += \
    button.ui \
    findpassword.ui \
    new_stock.ui \
    power_warnning.ui \
    question.ui \
    stock_system.ui \
    store_manager.ui \
    test64.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    login.qrc
