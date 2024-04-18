#ifndef REPLACER_H
#define REPLACER_H

#include <QFile>

#include <QString>

#include "jsonparser.h"
#include "threadobject.h"

class Replacer
{
public:
    Replacer();
    QString readLangFile();
    void threadReplace();
    void toCpp();
    void cppCompile();

private:
    bool keywordIn(QString);
    void replaceInFile(QString);

    QString filePath = ":/Resources/lang.lpp";
    JsonParser *jsonManager;
    QVector<QString> allJsonKeys;
};

#endif // REPLACER_H
