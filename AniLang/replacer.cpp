#include "replacer.h"

Replacer::Replacer(QString pathOfLppFile) {
    this->allJsonKeys = jsonManager->getAllKeys();
    this->filePath = pathOfLppFile;
    this->fileData = readLangFile();
    QString pathWithoutFile = pathOfLppFile.left(pathOfLppFile.lastIndexOf('\\') + 1);
    this->pathWithoutFile = pathWithoutFile;
    QString fileName = pathOfLppFile.remove(pathWithoutFile).remove(".lpp");
    this->fileName = fileName;
}

QString Replacer::readLangFile()
{
    QString bufferData;
    QFile file(filePath);
    file.open(QIODevice::ReadOnly);
    if (file.isOpen())
    {
        bufferData = file.readAll();
    }
    else qDebug() << "Not open file .lpp";
    return bufferData;
}

void Replacer::replace()
{
    for (QString value : allJsonKeys) {
                fileData = fileData.replace(value, jsonManager->valueFromJson(value));
    }

    for (QString value : allJsonKeys) {
        QString undo = QString("/%1").arg(jsonManager->valueFromJson(value));
        fileData = fileData.replace(undo, value);
    }

    cppManager->toCpp(fileData, pathWithoutFile, fileName);
    cppManager->cppCompile(pathWithoutFile, fileName);
}


