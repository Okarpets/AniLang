#ifndef REPLACER_H
#define REPLACER_H

#include <QString>
#include <QFile>

#include "jsonparser.h"

class Replacer
{
public:
    Replacer();
    QString readLangFile();
    void threadReplace();
    void toCpp();
    void cppCompile();
};

#endif // REPLACER_H
