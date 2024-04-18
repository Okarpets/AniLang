#include "threadobject.h"

ThreadObject::ThreadObject(QString filePath, QString oldValue, QString newValue, QString fileText)
{
    this->filePath = filePath;
    this->oldValue = oldValue;
    this->newValue = newValue;
    this->fileText = fileText;
}

void ThreadObject::run()
{
    QFile file(filePath);
    file.open(QIODevice::WriteOnly);
    QString newText = fileText.replace(oldValue, newValue);
    QTextStream stream(&file);
    stream << newText;
    file.close();
}
