#ifndef THREADOBJECT_H
#define THREADOBJECT_H

#include <QThread>
#include <QFile>
#include <QTextStream>

#include "replacer.h"

class ThreadObject : public QThread
{
public:
    ThreadObject(QVector<QString> fileData, int integer);

protected:
    void run() override;

private:
    QVector<QString> fileData;
    int integer;

};

#endif // THREADOBJECT_H
