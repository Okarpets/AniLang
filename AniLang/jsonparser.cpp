#include "jsonparser.h"

JsonParser::JsonParser() {}

QVector<QString> JsonParser::getAllKeys()
{
    QVector<QString> keys = readJsonFile().keys();
    return keys;
}

QJsonObject JsonParser::readJsonFile()
{
    QFile file(":/Resources/lexer.json");
    file.open(QIODevice::ReadOnly);
    QString fileData = file.readAll();
    file.close();
    QJsonDocument bufferDocument = QJsonDocument::fromJson(fileData.toUtf8());
    QJsonObject bufferJsonObject = bufferDocument.object();
    return bufferJsonObject;
}

QString JsonParser::valueFromJson(QString orderValue)
{
    QJsonValue value = readJsonFile().value(orderValue);
    return value.toString();
}


