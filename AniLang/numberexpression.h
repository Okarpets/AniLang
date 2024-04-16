#ifndef NUMBEREXPRESSION_H
#define NUMBEREXPRESSION_H

#include "expression.h"

class NumberExpression : public Expression
{
public:
    NumberExpression(double value);
    double eval();
    double value;
    QString toString();
};

#endif // NUMBEREXPRESSION_H
