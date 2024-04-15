#include "lexer.h"

Lexer::Lexer(QString inputString)
{
    this->inputString = inputString;
    inputLength = inputString.length();
}

QVector<Token> Lexer::processed()
{
    while(pos < inputLength) {
        QChar currentChar = peekPos(0);
        if (currentChar.isDigit()) {

        }
    }
}

void Lexer::addToken(TypeOfToken type)
{
    tokens.append(Token(type, ""));
}

void Lexer::addToken(TypeOfToken type, QString text)
{
    tokens.append(Token(type, text));
}

QChar Lexer::peekPos(int relativePos)
{
    int position = pos + relativePos;
    if (position >= inputLength) {
        return'\0';
    }
    return inputString[position];
}
