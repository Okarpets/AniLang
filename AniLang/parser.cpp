#include "parser.h"

Parser::Parser(QVector<Token> tokens)
{
    this->tokens = tokens;
    this->size = tokens.size();
}

Token Parser::peekPos(int relativePos)
{
    int position = pos + relativePos;
    if (position >= size) {
        Token *tokenEnd = new Token(FILEEND, "");
        return *tokenEnd;
    }
    return tokens[position];
}

QVector<Expression> Parser::parse()
{
    result.clear();
    while (!match(TypeOfToken::FILEEND)) {
        result.push_back(expression());
    }
    return result;
}

Expression Parser::expression()
{
    return additive();
}

Expression Parser::additive()
{
    Expression exp = multiplicative();

    while (true) {
        if(match(TypeOfToken::SUM)) {
            QChar operation = '+';
            BinaryExpression *numExp = new BinaryExpression(operation, exp, multiplicative());
            exp = *numExp;
            continue;
        }
        if(match(TypeOfToken::MINUS)) {
            QChar operation = '-';
            BinaryExpression *numExp = new BinaryExpression(operation, exp, multiplicative());
            exp = *numExp;
            continue;
        }
        break;
    }
    return exp;
}

Expression Parser::multiplicative()
{
    Expression exp = unary();

    while (true) {
        if(match(TypeOfToken::MULTIPLY)) {
            QChar operation = '*';
            BinaryExpression *numExp = new BinaryExpression(operation, exp, unary());
            exp = *numExp;
            continue;
        }
        if(match(TypeOfToken::DIVIDE)) {
            QChar operation = '/';
            BinaryExpression *numExp = new BinaryExpression(operation, exp, unary());
            exp = *numExp;
            continue;
            }
        break;
        }
    return exp;
}

Expression Parser::unary()
{
    return primary();
}

Expression Parser::primary()
{
    Expression exp;
    Token currentToken = peekPos(0);
    if(match(TypeOfToken::NUMBER)) {
        NumberExpression *numExp = new NumberExpression(currentToken.getTokenText().toDouble());
        exp = *numExp;
        return exp;

    }
    qDebug() << "ERROR";
}

bool Parser::match(TypeOfToken type)
{
    Token currentToken = peekPos(0);
    if (type != currentToken.getType()) return false;
    pos++;
    return true;
}
