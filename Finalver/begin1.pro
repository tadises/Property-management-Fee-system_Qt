QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    create_w.cpp \
    fileop.cpp \
    logging.cpp \
    main.cpp \
    mujuan.cpp \
    pay.cpp \
    personalinform.cpp \
    rootc.cpp \
    widget.cpp

HEADERS += \
    create_w.h \
    logging.h \
    main.h \
    mujuan.h \
    pay.h \
    personalinform.h \
    rootc.h \
    widget.h

FORMS += \
    create_w.ui \
    logging.ui \
    mujuan.ui \
    pay.ui \
    personalinform.ui \
    rootc.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES += \
    mujuan2.JPG
