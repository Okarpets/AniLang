#include "replacer.h"

Replacer::Replacer() {
    this->allJsonKeys = jsonManager->getAllKeys();
    this->fileData = readLangFile();
    newData();
}

QVector<QString> Replacer::readLangFile()
{
    QString bufferData;
    QVector<QString> bufferFileData;
    QFile file(filePath);
    file.open(QIODevice::ReadOnly);
    while (!file.atEnd()) {
        for (int i = 0; i < 20; i++) {
            QString buffer = file.readLine();
            bufferData += buffer;
        }
        bufferFileData.append(bufferData);
        bufferData.clear();
    }
    file.close();
    return bufferFileData;
}

bool Replacer::checkKey(QString orderValue, int integer)
{
    return fileData[integer].contains(orderValue);
}

void Replacer::threadReplace()
{
    for (QString langKey : allJsonKeys) {
        if(checkKey(langKey, 1) == true) {
            // Create a thread with replace function
            ThreadObject *processTheard = new ThreadObject(fileData, 1);
            processTheard->start();
            QThread::sleep(1);

            // QFile file(filePath);
            // file.open(QIODevice::WriteOnly);
            // QString newText = bufferText.replace(oldValue, newValue);
            // QTextStream stream(&file);
            // stream << newText;
            // file.close();
        }
    }

}

void Replacer::toCpp()
{

}

void Replacer::cppCompile()
{

}

void Replacer::newData()
{
    QVector<QString> buffer(fileData.size());
    this->newDataInit = buffer;
}


