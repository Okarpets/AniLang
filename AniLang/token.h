#ifndef TOKEN_H
#define TOKEN_H

#include <QString>
#include "TypeOfToken.h"

class Token
{
public:
    Token();
    Token(TypeOfToken type, QString text);
    void setTokenText(QString text);
    QString getTokenText();
    void setType(TypeOfToken type);
    TypeOfToken getType();
private:
    QString text;
    TypeOfToken type;
};

#endif // TOKEN_H
