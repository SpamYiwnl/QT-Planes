#-------------------------------------------------
#
# Project created by QtCreator 2019-12-21T17:02:19
#
#-------------------------------------------------

QT       += core gui
QT += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = myProject
TEMPLATE = app


SOURCES += main.cpp \
    bullet.cpp \
    addhealth.cpp \
    enemy.cpp \
    game.cpp \
    gameover.cpp \
    gameui.cpp \
    health.cpp \
    player.cpp \
    score.cpp

HEADERS  += \
    bullet.h \
    addhealth.h \
    enemy.h \
    game.h \
    gameover.h \
    gameui.h \
    health.h \
    player.h \
    score.h

FORMS    += \
    gameover.ui \
    gameui.ui

RESOURCES += \
    resources.qrc
