#include <QCoreApplication>
#include "lexer.h"
#include "expression.h"
#include "parser.h"
#include <qdebug.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    // Token *num = new Token(FILEEND, "dad");
    // TypeOfToken text = num->getType();
    // qDebug() << text;
    // num->setType(MULTIPLY);
    // TypeOfToken text2 = num->getType();
    // qDebug() << text2;
    // QString dad = "+-/*";
    // qDebug() << dad.contains("]");
    QString inf = "-8";
    Lexer *test = new Lexer(inf);
    QVector<Token> tokens = test->processed();
    for (Token  token : tokens) {
        qDebug() << token.getType();
        qDebug() << token.getTokenText();
    }

    Parser *primaryTest = new Parser(tokens);
    QVector<Expression> expressions = primaryTest->parse();
    for (Expression expression : expressions) {
        qDebug() << expression.toString();
    }

    return a.exec();
}


// TRASH FILE :D
