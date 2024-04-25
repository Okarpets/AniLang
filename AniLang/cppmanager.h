#ifndef CPPMANAGER_H
#define CPPMANAGER_H

#include <QFile>

#include <QJsonDocument>
#include <QString>

class CppManager
{
public:
    CppManager();
    void deleteCpp(QString pathWithoutFile);
    void cppCompile(QString pathWithoutFile, QString fileName);
    void toCpp(QVector<QString> fileData, QString pathWithoutFile);
};

#endif // CPPMANAGER_H
