#include "cppmanager.h"

CppManager::CppManager() {}

void CppManager::toCpp(QVector<QString> fileData, QString pathWithoutFile)
{
    QString buffer;
    for (int index = 0; index < fileData.size(); index++) {
        QFile file(QString("./BufferFile%1.txt").arg(index));
        file.open(QIODevice::ReadOnly);
        while (true) {
            if (file.isOpen() == false)
            {
                file.open(QIODevice::ReadOnly);
            }
            else break;
        }
        buffer = buffer + file.readAll();
        file.close();
    }
    QFile file(QString("%1lang.cpp").arg(pathWithoutFile));
    file.open(QIODevice::WriteOnly);
    QTextStream out(&file);
    out << buffer;
    file.close();
}

void CppManager::deleteCpp(QString pathWithoutFile)
{
    QFile file(QString("%1lang.cpp").arg(pathWithoutFile));
    file.remove();
}

void CppManager::cppCompile(QString pathWithoutFile, QString fileName)
{
    QString objectFile = QString("g++ %1lang.cpp -o %2%3.o").arg(pathWithoutFile).arg(pathWithoutFile).arg(fileName);
    QString executFile = QString("g++ %1lang.cpp -o %2%3.exe").arg(pathWithoutFile).arg(pathWithoutFile).arg(fileName);
    QString openExe = QString("%1%2.exe").arg(pathWithoutFile).arg(fileName);
    system(objectFile.toLatin1());
    system(executFile.toLatin1());
    system(openExe.toLatin1());
}
