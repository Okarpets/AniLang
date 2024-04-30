#include "cppmanager.h"

CppManager::CppManager() {}

void CppManager::toCpp(QString fileData, QString pathWithoutFile, QString fileName)
{
    QFile file(QString("%1%2.cpp").arg(pathWithoutFile).arg(fileName));
    file.open(QIODevice::WriteOnly);
    QTextStream out(&file);
    QString bufferss;
    out << fileData;
    file.close();
}

void CppManager::deleteCpp(QString pathWithoutFile, QString fileName)
{
    QFile file(QString("%1%2.cpp").arg(pathWithoutFile).arg(fileName));
    file.remove();
}

void CppManager::cppCompile(QString pathWithoutFile, QString fileName)
{
    QString objectFile = QString("g++ %1%2.cpp -o %3%4.o").arg(pathWithoutFile).arg(fileName).arg(pathWithoutFile).arg(fileName);
    QString executFile = QString("g++ %1%2.cpp -o %3%4.exe").arg(pathWithoutFile).arg(fileName).arg(pathWithoutFile).arg(fileName);
    QString openExe = QString("%1%2.exe").arg(pathWithoutFile).arg(fileName);
    system(objectFile.toLatin1());
    system(executFile.toLatin1());
    deleteCpp(pathWithoutFile, fileName);
    system(openExe.toLatin1());
}
