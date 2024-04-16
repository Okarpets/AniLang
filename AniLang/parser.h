#ifndef PARSER_H
#define PARSER_H

#include <QVector>
#include <QDebug>

#include "numberexpression.h"
#include "binaryexpression.h"
#include "expression.h"
#include "token.h"

class Parser
{
public:
    Parser(QVector<Token> tokens);
    Token peekPos(int relativePos);

    QVector<Expression> parse();
    Expression expression();
    Expression additive();
    Expression multiplicative();
    Expression unary();
    Expression primary();
    bool match(TypeOfToken);

private:
    QVector<Expression> result;
    QVector<Token> tokens;
    int size;
    int pos;




};

#endif // PARSER_H
