#include "replacer.h"

Replacer::Replacer(QString pathOfFile) {
    this->allJsonKeys = jsonManager->getAllKeys();
    this->fileData = readLangFile();
    this->filePath = pathOfFile;
    QString pathWithoutFile = pathOfFile.left(pathOfFile.lastIndexOf('\\') + 1);
    this->pathWithoutFile = pathWithoutFile;
    qDebug() << pathOfFile;
    qDebug() << pathWithoutFile;
    QString fileName = pathOfFile.remove(pathWithoutFile).remove(".lpp");
    this->fileName = fileName;
    qDebug() << fileName;
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
    QString objectFile = QString("%1%2.cpp -o %3%4.o").arg(pathWithoutFile).arg(fileName).arg(pathWithoutFile).arg(fileName);
    QString executFile = QString("%1%2.cpp -o %3%4.exe").arg(pathWithoutFile).arg(fileName).arg(pathWithoutFile).arg(fileName);
    system(objectFile.toLatin1());
    system(objectFile.toLatin1());

}

void Replacer::newData()
{
    QVector<QString> buffer(fileData.size());
    this->newDataInit = buffer;
}


