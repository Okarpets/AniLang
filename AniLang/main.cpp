#include <QCoreApplication>
#include "token.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    // Token *num = new Token(FILEEND, "dad");
    // TypeOfToken text = num->getType();
    // qDebug() << text;
    // num->setType(MULTIPLY);
    // TypeOfToken text2 = num->getType();
    // qDebug() << text2;
    // QString text = "FANTASIO";
    // qDebug() << text[3];
    return a.exec();
}
