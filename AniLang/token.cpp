#include "token.h"

Token::Token() {}

Token::Token(TypeOfToken type, QString text) {
    this->text = text; // текст, который принимает токен для обработки
    this->type = type; // тип данных, что был передан
}

void Token::setTokenText(QString text)
{
    this->text = text;
}

QString Token::getTokenText()
{
    return this->text;
}

void Token::setType(TypeOfToken type)
{
    this->type = type;
}

TypeOfToken Token::getType()
{
    return this->type;
}
