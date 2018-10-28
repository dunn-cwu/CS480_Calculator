// ---------------------------------
// Course: CS 480 Advanced Software Engineering
// Section: 8:00 AM
// Instructor: Dr. Szilárd VAJDA
// Quarter: Fall 2018
// Date: 10/27/2018
//
// Assignment: Lab 3
// Student: Andrew Dunn
//
// File: postfixexpression.h
// Desc: Header file and definition for PostfixExpression class.
// ---------------------------------

#ifndef POSTFIXEXPRESSION_H
#define POSTFIXEXPRESSION_H

#include <QString>

class PostfixExpression
{
public:
    PostfixExpression();
    PostfixExpression(QString expr);

    bool fromInfix(QString expr);
    bool solve(double& out);
    QString toString();
private:
    QString expr;

    int opPrecedence(QChar op);
    bool isOperand(QChar op);
    QString fixNegations(QString infixExpr);
};

#endif // POSTFIXEXPRESSION_H

// ===================================================
// End Of File
// ===================================================
