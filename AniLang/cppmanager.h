#ifndef CPPMANAGER_H
#define CPPMANAGER_H

#include <QFile>

#include <QJsonDocument>
#include <QString>

class CppManager
{
public:
    CppManager();
    void cppCompile(QString pathWithoutFile, QString fileName);
    void toCpp(QString fileData, QString pathWithoutFile, QString fileName);
    void deleteCpp(QString pathWithoutFile, QString fileName);
};

#endif // CPPMANAGER_H
