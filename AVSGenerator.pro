#-------------------------------------------------
#
# Project created by QtCreator 2016-11-07T21:03:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AVSGenerator
TEMPLATE = app


SOURCES += main.cpp\
        principal.cpp \
    dialogocomentarios.cpp \
    dialogocorte.cpp \
    previewavs.cpp \
    dialogocontrolelegendas.cpp \
    dialogoeditarlegenda.cpp \
    dialogoadicionarlegenda.cpp \
    dadoslegenda.cpp \
    global.cpp \
    dialogopreferencias.cpp \
    dialogosobre.cpp

HEADERS  += \
    dialogocomentarios.h \
    dialogocorte.h \
    previewavs.h \
    principal.h \
    dialogocontrolelegendas.h \
    dialogoeditarlegenda.h \
    dialogoadicionarlegenda.h \
    dadoslegenda.h \
    global.h \
    dialogopreferencias.h \
    dialogosobre.h

FORMS    += principal.ui \
    dialogocomentarios.ui \
    dialogocorte.ui \
    previewavs.ui \
    dialogocontrolelegendas.ui \
    dialogoeditarlegenda.ui \
    dialogoadicionarlegenda.ui \
    dialogopreferencias.ui \
    dialogosobre.ui

RC_FILE = AVSGenerator.rc
	
DISTFILES +=

RESOURCES += \
    imgs.qrc
