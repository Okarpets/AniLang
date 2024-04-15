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
            tokenizeNumber();
        } else if (charsOperator.indexOf(currentChar) != -1) {
            tokenizeOperator();
        } else {
            next();
        }
    }
    return tokens;
}

void Lexer::tokenizeNumber()
{
    buffer.clear();
    QChar currentChar = peekPos(0);
    while (currentChar.isDigit()) {
        buffer.append(currentChar);
        currentChar = next();
    }
    addToken(TypeOfToken::NUMBER, buffer);
}

void Lexer::tokenizeOperator()
{
    int position = charsOperator.indexOf(peekPos(0));
    addToken(tokenOperator[position]);
    next();
}

QChar Lexer::next()
{
    pos++;
    return peekPos(0);
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
