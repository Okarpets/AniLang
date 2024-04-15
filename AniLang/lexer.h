#ifndef LEXER_H
#define LEXER_H

#include <QString>
#include <QVector>
#include <Qchar>
#include "token.h"

class Lexer
{
public:
    Lexer(QString inputString);

    QVector<Token> processed();

private:
    QString inputString;
    QVector<Token> tokens;
    int pos;
    int inputLength;

    void addToken(TypeOfToken type);
    void addToken(TypeOfToken type, QString text);
    QChar peekPos(int relativePos);
};

#endif // LEXER_H
