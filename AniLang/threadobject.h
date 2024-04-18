#ifndef THREADOBJECT_H
#define THREADOBJECT_H

#include <QThread>
#include <QFile>
#include <QTextStream>

class ThreadObject : public QThread
{
public:
    ThreadObject(QString filePath, QString oldValue, QString newValue, QString fileText);

protected:
    void run() override;

private:
    QString filePath;
    QString oldValue;
    QString newValue;
    QString fileText;

};

#endif // THREADOBJECT_H
