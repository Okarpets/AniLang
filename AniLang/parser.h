#ifndef PARSER_H
#define PARSER_H

#include <QVector>

#include "expression.h"
#include "token.h"

class Parser
{
public:
    Parser(QVector<Token> tokens);


    QVector<Expression> parse();

private:
    QVector<Token> tokens;



};

#endif // PARSER_H
