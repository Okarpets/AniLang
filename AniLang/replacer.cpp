#include "replacer.h"

Replacer::Replacer(QString pathOfLppFile) {
    this->allJsonKeys = jsonManager->getAllKeys();
    this->fileData = readLangFile();
    this->filePath = pathOfLppFile;
    QString pathWithoutFile = pathOfLppFile.left(pathOfLppFile.lastIndexOf('\\') + 1);
    this->pathWithoutFile = pathWithoutFile;
    QString fileName = pathOfLppFile.remove(pathWithoutFile).remove(".lpp").remove(".cpp");
    this->fileName = fileName;
    newData();
}

QVector<QString> Replacer::readLangFile()
{
    QString bufferData;
    QVector<QString> bufferFileData;
    QFile file(filePath);
    file.open(QIODevice::ReadOnly);
    while (!file.atEnd()) {
        for (int index = 0; index < 15; index++) {
            QString buffer = file.readLine();
            bufferData += buffer;
        }
        bufferFileData.append(bufferData);
        bufferData.clear();
    }
    file.close();
    return bufferFileData;
}

void Replacer::threadReplace()
{
    for (int index = 0; index < fileData.size(); index++) {
            // Create a thread with replace function

            ThreadObject *processTheard = new ThreadObject(fileData, index);
            processTheard->start();

        }
    toCpp();
    deleteAllBufferFile();
    cppCompile();
}

void Replacer::deleteAllBufferFile()
{
    for (int index = 0; index < fileData.size(); index++) {
        QFile file(QString("./BufferFile%1.txt").arg(index));
        file.remove();
    }
}

void Replacer::toCpp()
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
    QFile file("./lang.cpp");
    file.open(QIODevice::WriteOnly);
    QTextStream out(&file);
    out << buffer;
    file.close();
}

void Replacer::cppCompile()
{
    QString objectFile = QString("g++ %1 -o %2%3.o").arg(filePath).arg(pathWithoutFile).arg(fileName);
    QString executFile = QString("g++ %1 -o %2%3.exe").arg(filePath).arg(pathWithoutFile).arg(fileName);
    system(objectFile.toLatin1());
    system(executFile.toLatin1());

}

void Replacer::newData()
{
    QVector<QString> buffer(fileData.size());
    this->newDataInit = buffer;
}


