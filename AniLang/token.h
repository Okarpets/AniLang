#ifndef TOKEN_H
#define TOKEN_H

#include <QString>
#include "TypeOfToken.h"

class Token
{
public:
    Token();
    Token(TypeOfToken type, QString text); // construct :3

    void setTokenText(QString text); // Classic getter-setter system
    QString getTokenText();
    void setType(TypeOfToken type);
    TypeOfToken getType();

private: // Token atributes
    QString text;
    TypeOfToken type;
};

#endif // TOKEN_H
