#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <QFile>

#include <QJsonDocument>
#include <QJsonObject>

class JsonParser
{
public:
    JsonParser();
    QVector<QString> getAllKeys();
    QString valueFromJson(QString);
private:
    QJsonObject readJsonFile();

};

#endif // JSONPARSER_H
