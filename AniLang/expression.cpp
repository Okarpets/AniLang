#include "expression.h"

Expression::Expression() {}

double Expression::eval()
{
    return value;
}

QString Expression::toString()
{
    return QString(QString::number(value));
}
