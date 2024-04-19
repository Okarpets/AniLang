#ifndef REPLACER_H
#define REPLACER_H

#include <QFile>

#include <QString>
#include <QObject>

#include <QProcess>

#include "jsonparser.h"
#include "threadobject.h"

class Replacer
{
public:
    Replacer();
    QVector<QString> readLangFile();
    void threadReplace();
    void toCpp();
    void cppCompile();
    void deleteAllBufferFile();
    QVector<QString> fileData;
    QVector<QString> newDataInit;

private:
    void newData();

    QString filePath = "C:/Users/User/AniLang/AniLang/lang.lpp";
    JsonParser *jsonManager;
    QVector<QString> allJsonKeys;

};

#endif // REPLACER_H
