QT       += core gui

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
    business/Auxiliary.cpp \
    business/Facade.cpp \
    business/FacadeOperationResult.cpp \
    business/Figure.cpp \
    business/FileReader.cpp \
    business/NormalizationParameters.cpp \
    business/Point3D.cpp \
    business/QtSceneDrawer.cpp \
    business/Scene.cpp \
    business/TransformMatrix.cpp \
    business/TransformMatrixBuilder.cpp \
    business/Vertex.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    business/Auxiliary.h \
    business/BaseFileReader.h \
    business/Facade.h \
    business/FacadeOperationResult.h \
    business/Figure.h \
    business/FileReader.h \
    business/NormalizationParameters.h \
    business/Point3D.h \
    business/QtSceneDrawer.h \
    business/Scene.h \
    business/SceneDrawerBase.h \
    business/SceneObject.h \
    business/TransformMatrix.h \
    business/TransformMatrixBuilder.h \
    business/Vertex.h \
    business/myexception.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
