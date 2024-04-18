#include "jsonparser.h"

JsonParser::JsonParser() {}

bool JsonParser::keywordIn(QString orderValue)
{
    QString bufferObject = readJsonFile();
    return bufferObject.contains(orderValue);
}

QString JsonParser::readJsonFile()
{
    QFile file(":/Resources/lexer.json");
    file.open(QIODevice::ReadOnly);
    QString fileData = file.readAll();
    return fileData;
}

QString JsonParser::valueFromJson(QString orderValue)
{
    QJsonDocument bufferDocument = QJsonDocument::fromJson(readJsonFile().toUtf8());
    QJsonObject bufferObject = bufferDocument.object();
    QJsonValue value = bufferObject.value(QString("%1").arg(orderValue));
    return value.toString();
}
