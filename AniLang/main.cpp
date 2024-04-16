#include <QCoreApplication>
#include "lexer.h"
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
    // QString dad = "+-/*";
    // qDebug() << dad.contains("]");
     QString inf = "26 + 93";
     Lexer *test = new Lexer(inf);
     QVector<Token> tokens = test->processed();
     for (Token  token : tokens) {
        qDebug() << token.getType();
        qDebug() << token.getTokenText();
     }
    return a.exec();
}


// TRASH FILE :D
