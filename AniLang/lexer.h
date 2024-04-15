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
    QString inputString; // Line to be processed
    QVector<Token> tokens; // Created tokens for further parsing
    int pos; // Current position in the "inputString"
    int inputLength;
    QString charsOperator = "+-*/"; // All operator chars
    QVector<TypeOfToken> tokenOperator = {
        TypeOfToken::SUM, TypeOfToken::MINUS, TypeOfToken::MULTIPLY, TypeOfToken::DIVIDE
    }; // All relevant charsOperator tokens
    QString buffer; // Timeless buffer

    void tokenizeNumber();
    void tokenizeOperator();
    QChar next(); // Go to next char in inputString
    void addToken(TypeOfToken); // Added token to list of tokens
    void addToken(TypeOfToken, QString);
    QChar peekPos(int relativePos); // set and check your current position in inputString
};

#endif // LEXER_H
