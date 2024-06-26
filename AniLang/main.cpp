#include <QCoreApplication>
#include <QCommandLineParser>

#include "jsonparser.h"
#include "replacer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QCommandLineParser parser;
    QCommandLineOption filePath(QStringList()<<"p"<<"Path","Path","default-path");
    parser.addOption(filePath);
    parser.process(a);
    if(parser.isSet(filePath)) {
        QString pathOfFile = parser.value(filePath);
        Replacer *repl = new Replacer(pathOfFile);
        repl->replace();
    };
    return a.exec();
}
