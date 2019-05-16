#-------------------------------------------------
#
# Project created by QtCreator 2019-03-18T20:11:27
#
#-------------------------------------------------

QT       +=  gui \   #원래 core gui  였음
         multimedia \
        #gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Dungeon_and_Studies
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11 \
        resources_big \

SOURCES += \
        main.cpp \
    player.cpp \
    startingpage.cpp \
    navigation.cpp \
    game.cpp \
    battle_scene.cpp \
    enemy.cpp \
    a_study.cpp \
    b_group.cpp \
    c_overnight.cpp \
    d_run.cpp \
    prologue.cpp \
    game_over.cpp

HEADERS += \
    player.h \
    startingpage.h \
    navigation.h \
    game.h \
    battle_scene.h \
    enemy.h \
    a_study.h \
    b_group.h \
    c_overnight.h \
    d_run.h \
    prologue.h \
    game_over.h

FORMS += \
    startingpage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
