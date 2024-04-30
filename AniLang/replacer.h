#ifndef REPLACER_H
#define REPLACER_H

#include <QFile>

#include <QString>
#include <QObject>

#include <QProcess>

#include "jsonparser.h"
#include "cppmanager.h"

class Replacer
{
public:
    Replacer(QString pathOfLppFile);
    QString readLangFile();
    void replace();
    QString fileData;

private:
    QString pathWithoutFile;
    QString filePath;
    QString fileName;
    QVector<QString> allJsonKeys;

    JsonParser *jsonManager;
    CppManager *cppManager;


};

#endif // REPLACER_H
