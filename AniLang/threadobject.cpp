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
    QFile file(QString("./BufferFile%1.txt").arg(integer));
    file.open(QIODevice::WriteOnly);
    QTextStream out(&file);
    out << newText;
    file.close();
    delete parser;
}
