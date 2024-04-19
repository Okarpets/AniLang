#ifndef REPLACER_H
#define REPLACER_H

#include <QFile>

#include <QString>
#include <QObject>

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
    QVector<QString> fileData;
    QVector<QString> newDataInit;

private:
    bool checkKey(QString, int);
    void newData();

    QString filePath = "C:/Users/User/AniLang/AniLang/lang.lpp";
    JsonParser *jsonManager;
    QVector<QString> allJsonKeys;

};

#endif // REPLACER_H
