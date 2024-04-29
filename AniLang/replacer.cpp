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
            QString bufferData = fileData[index];
                for (QString value : allJsonKeys) {
                    bufferData = bufferData.replace(value, jsonManager->valueFromJson(value));
                }
            fileData[index] = bufferData;
                bufferData.clear();
    }
    QFile file(QString("%1lang.cpp").arg(pathWithoutFile));
    file.open(QIODevice::WriteOnly);
    QTextStream out(&file);
    QString bufferss;
    for (int index = 0; index < fileData.size(); index++) {
        bufferss += fileData[index];
    }
    out << bufferss;
    file.close();

    //cppManager->toCpp(fileData, pathWithoutFile);
    //deleteAllBufferFile();
    cppManager->cppCompile(pathWithoutFile, fileName);
}

void Replacer::deleteAllBufferFile()
{
    for (int index = 0; index < fileData.size(); index++) {
        QFile file(QString("./BufferFile%1.txt").arg(index));
        file.remove();
    }
}

void Replacer::newData()
{
    QVector<QString> buffer(fileData.size());
    this->newDataInit = buffer;
}


