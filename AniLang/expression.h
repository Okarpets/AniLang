#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <QString>

class Expression
{
public:
    Expression();
    double eval();
    QString toString();

private:
    double value;
};

#endif // EXPRESSION_H
