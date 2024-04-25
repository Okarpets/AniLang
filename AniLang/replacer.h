#ifndef REPLACER_H
#define REPLACER_H

#include <QFile>

#include <QString>
#include <QObject>

#include <QProcess>

#include "jsonparser.h"
#include "cppmanager.h"
#include "threadobject.h"

class Replacer
{
public:
    Replacer(QString pathOfLppFile);
    QVector<QString> readLangFile();
    void threadReplace();
    void deleteAllBufferFile();
    QVector<QString> fileData;
    QVector<QString> newDataInit;

private:
    void newData();

    QString pathWithoutFile;
    QString filePath;
    QString fileName;
    QVector<QString> allJsonKeys;

    JsonParser *jsonManager;
    CppManager *cppManager;


};

#endif // REPLACER_H
