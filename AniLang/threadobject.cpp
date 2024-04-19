#include "threadobject.h"


ThreadObject::ThreadObject(QVector<QString> fileData, int integer)
{
    this->fileData = fileData;
    this->integer = integer;
}

void ThreadObject::run()
{
    QString newText = fileData[integer];
    JsonParser *parser = new JsonParser();
    QVector<QString> allKeys = parser->getAllKeys();
    for (QString key : allKeys) {
    newText = newText.replace(key, parser->valueFromJson(key));
    }
}
