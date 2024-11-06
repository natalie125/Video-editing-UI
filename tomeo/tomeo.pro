QT += core gui widgets multimedia multimediawidgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    effects.cpp \
    button_exit.cpp \
    button_upload.cpp \
    main.cpp \
    previewcontrols.cpp \
    previewer.cpp \
    projectcontrols.cpp \
    timeline.cpp \
    tomeo.cpp \
    toolbar.cpp \
    videoselector.cpp

HEADERS += \
    button_exit.h \
    button_upload.h \
    constants.h \
    dynamiclabel.h \
    effects.h \
    previewcontrols.h \
    previewer.h \
    projectcontrols.h \
    timeline.h \
    tomeo.h \
    toolbar.h \
    video.h \
    videoselector.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc

FORMS += \
    mainwindow.ui
