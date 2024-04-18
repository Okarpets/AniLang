QT = core
QT += widgets

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        jsonparser.cpp \
        main.cpp \
        replacer.cpp \
        threadobject.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    LexerExpression.h \
    jsonparser.h \
    replacer.h \
    threadobject.h

DISTFILES += \
    JSON.txt \
    bn.txt \
    test

RESOURCES += \
    Res.qrc \
    Resources.qrc \
    files.qrc \
    res.qrc

FORMS +=
