#include "replacer.h"

Replacer::Replacer() {}

QString Replacer::readLangFile()
{
    QFile file(":/Resources/lang.lpp");
    file.open(QIODevice::ReadOnly);
    QString fileData = file.readAll();
    return fileData;
}

void Replacer::threadReplace()
{

}

void Replacer::toCpp()
{

}

void Replacer::cppCompile()
{

}
