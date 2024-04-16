#include "numberexpression.h"

NumberExpression::NumberExpression(double value) {
    this->value = value;
}

double NumberExpression::eval()
{
    return value;
}
