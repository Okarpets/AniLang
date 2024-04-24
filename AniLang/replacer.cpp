#include "replacer.h"

Replacer::Replacer(QString pathOfLppFile) {
    this->allJsonKeys = jsonManager->getAllKeys();
    this->filePath = pathOfLppFile;
    this->fileData = readLangFile();
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

            //ThreadObject *processTheard = new ThreadObject(fileData, index);
            //processTheard->start();


            // Timely code:
            for (QString data : fileData) {
                for (QString value : allJsonKeys) {
                    data.replace(value, jsonManager->valueFromJson(value));
                }
                fileData[index] = data;
            }
        }
    QFile file(QString("%1lang.cpp").arg(pathWithoutFile));
    qDebug() << "TESTTTT";
    file.open(QIODevice::WriteOnly);
    QTextStream out(&file);
    QString bufferss;
    for (int index = 0; index < fileData.size(); index++) {
        bufferss += fileData[index];
    }
    qDebug() << "DATTTATAAAAA:    ";
    qDebug() << bufferss;
    out << bufferss;
    file.close();

    //toCpp();
    //deleteAllBufferFile();
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
    QFile file(QString("%1lang.cpp").arg(pathWithoutFile));
    file.open(QIODevice::WriteOnly);
    QTextStream out(&file);
    out << buffer;
    file.close();
}

void Replacer::deleteCpp()
{
    QFile file(QString("%1lang.cpp").arg(pathWithoutFile));
    file.remove();
}

void Replacer::cppCompile()
{
    QString objectFile = QString("g++ %1lang.cpp -o %2%3.o").arg(pathWithoutFile).arg(pathWithoutFile).arg(fileName);
    QString executFile = QString("g++ %1lang.cpp -o %2%3.exe").arg(pathWithoutFile).arg(pathWithoutFile).arg(fileName);
    QString openExe = QString("%1%2.exe").arg(pathWithoutFile).arg(fileName);
    system(objectFile.toLatin1());
    system(executFile.toLatin1());
    system(openExe.toLatin1());
    deleteCpp();
}

void Replacer::newData()
{
    QVector<QString> buffer(fileData.size());
    this->newDataInit = buffer;
}


