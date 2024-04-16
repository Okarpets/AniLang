#include "binaryexpression.h"

BinaryExpression::BinaryExpression(QChar operation, Expression expression1, Expression expression2)
{
    this->operation = operation;
    this->expression1 = expression1;
    this->expression2 = expression2;
}

double BinaryExpression::eval()
{
    switch (operation.toLatin1()) {
        case '-': return expression1.eval() - expression2.eval();
        case '*': return expression1.eval() * expression2.eval();
        case '/': return expression1.eval() / expression2.eval();
        default:
        case '+':
            return expression1.eval() + expression2.eval();

        }
}

QString BinaryExpression::toString()
{
   // QString result = QString("%1 %2 %3").arg(expression1).arg(operation).arg(expression2);
    return "expression1operationexpression2";
}