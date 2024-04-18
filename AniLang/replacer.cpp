#include "replacer.h"

Replacer::Replacer() {
    this->allJsonKeys = jsonManager->getAllKeys();
}

QString Replacer::readLangFile()
{
    QFile file(filePath);
    file.open(QIODevice::ReadOnly);
    QString fileData = file.readAll();
    file.close();
    return fileData;
}

bool Replacer::keywordIn(QString orderValue)
{
    return allJsonKeys.contains(orderValue);
}


void Replacer::threadReplace()
{
    for (QString langKey : allJsonKeys) {
        if(keywordIn(langKey) == true) {
            // Create a thread with replace function
            ThreadObject *processTheard = new ThreadObject(filePath, langKey, jsonManager->valueFromJson(langKey), readLangFile());
            processTheard->start();
        }
    }
}

void Replacer::toCpp()
{

}

void Replacer::cppCompile()
{

}
