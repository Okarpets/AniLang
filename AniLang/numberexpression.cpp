#include "numberexpression.h"

NumberExpression::NumberExpression(double value) {
    this->value = value;
}

double NumberExpression::eval()
{
    return value;
}

QString NumberExpression::toString()
{
    QString result = QString("%1").arg(value);
    return result;
}
