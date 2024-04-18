#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <QFile>

#include <QJsonDocument>
#include <QJsonObject>

class JsonParser
{
public:
    JsonParser();
    bool keywordIn(QString);
    QString valueFromJson(QString orderValue);

private:
    QString readJsonFile();
};

#endif // JSONPARSER_H
