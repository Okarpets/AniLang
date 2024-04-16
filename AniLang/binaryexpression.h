#ifndef BINARYEXPRESSION_H
#define BINARYEXPRESSION_H

#include "QChar"

#include "expression.h"

class BinaryExpression
{
public:
    BinaryExpression(QChar operation, Expression expression1, Expression expression2);
    double eval();
private:
    Expression expression1;
    Expression expression2;
    QChar operation;
};

#endif // BINARYEXPRESSION_H
