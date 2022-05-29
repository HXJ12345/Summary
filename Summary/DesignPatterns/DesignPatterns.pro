QT -= gui

CONFIG += c++17 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        Bridge/Bridge.cpp \
        Bridge/NoBridge.cpp \
        Decorator/Decorator.cpp \
        Decorator/NotDecorator.cpp \
        Decorator/PerfectDecorator.cpp \
        Factory/Factory.cpp \
        Factory/NoFactroy.cpp \
        Observer/Observer.cpp \
        Observer/ObserverExample.cpp \
        Observer/Subject.cpp \
        Prototype/Prototype.cpp \
        Strategy/Strategy.cpp \
        TemplateMethod/Templatemethod.cpp \
        main.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Explain

HEADERS += \
    Bridge/Bridge.h \
    Decorator/Decorator.h \
    Factory/Factory.h \
    Observer/Observer.h \
    Observer/Subject.h \
    Prototype/Prototype.h \
    Strategy/Strategy.h \
    TemplateMethod/Templatemethod.h

