#-------------------------------------------------
#
# Project created by QtCreator 2016-07-28T05:57:07
#
#-------------------------------------------------

QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Pong
TEMPLATE = app


SOURCES += main.cpp \
    paddle1class.cpp \
    pongball.cpp \
    paddle2class.cpp \
    playerscore.cpp \
    computerscore.cpp

HEADERS  += \
    paddle1class.h \
    pongball.h \
    paddle2class.h \
    playerscore.h \
    computerscore.h

FORMS    +=

DISTFILES += \
    ../../../../../Downloads/Original Tetris theme (Tetris Soundtrack).mp3

RESOURCES += \
    res.qrc
