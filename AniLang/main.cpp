#include <QCoreApplication>
#include <QString>

#include <QJsonDocument>
#include <QFile>
#include <QJsonObject>

QString readJsonFile();
QString valueFromJson(QString);


int main()
{
    QString testResult = valueFromJson("дробное");
    qDebug() << testResult;

    return 0;
}

QString readJsonFile()
{
    QFile file(":/Resources/lexer.json");
    file.open(QIODevice::ReadOnly);
    QString fileData = file.readAll();
    return fileData;
}

QString valueFromJson(QString orderValue)
{
    QJsonDocument bufferDocument = QJsonDocument::fromJson(readJsonFile().toUtf8());
    QJsonObject bufferObject = bufferDocument.object();
    QJsonValue value = bufferObject.value(QString("%1").arg(orderValue));
    return value.toString();
}
