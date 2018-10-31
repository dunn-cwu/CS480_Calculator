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
// File: postfixexpression.cpp
// Desc: Implementation of PostfixExpression class.
//       Converts infix expressions to postfix.
//       Solves postfix expressions.
// ---------------------------------

#include <stack>
#include <math.h>
#include "postfixexpression.h"

PostfixExpression::PostfixExpression() : expr("")
{
}

PostfixExpression::PostfixExpression(QString expr) : expr(expr)
{
}

// Fixes unary negations in the infix expression
// to work correctly in the postfix expression solving.
// Ex: -2 is converted to (0-2)
//
// Fixes parentheses multiplication to work correctly.
// Ex: 2(3+4) is converted to 2*(3+4)
QString PostfixExpression::fixNegationsAndMult(QString infixExpr)
{
    if (infixExpr.isEmpty()) return infixExpr;

    int expLen = infixExpr.length();

    // Loop through each character in the infix expression string - 1
    for (int i = 0; i < (expLen - 1); i++)
    {
        // Get current and next characters
        QChar curCh = infixExpr.at(i);
        QChar nextChar = infixExpr.at(i + 1);

        // Is the current character a '-' operator and next
        // character an operand?
        if (curCh == '-' && isOperand(nextChar))
        {
            // Find the index for the end of the multi-digit operand following
            // the '-' operator (exclusive)
            int operandEnd = i + 1;

            while (operandEnd < expLen &&
                   isOperand(infixExpr.at(operandEnd)))
            {
                operandEnd++;
            }

            // Is the '-' operator the first character in the exp string?
            if (i == 0)
            {
                // If so, then it is a unary negation operator.
                // Wrap current negation and operand in parentheses
                // and place a zero in front of the '-' operator
                infixExpr.insert(operandEnd, ")");
                infixExpr.insert(i, "(0");
                i = operandEnd + 3;
            }
            else
            {
                // Get previous character
                QChar prevChar = infixExpr.at(i - 1);

                // Is prev. char is an operator but not a right parentheses?
                if (!isOperand(prevChar) && prevChar != ')')
                {
                    // If so, then it is a unary negation operator.
                    // Wrap current negation and operand in parentheses
                    // and place a zero in front of the '-' operator
                    infixExpr.insert(operandEnd, ")");
                    infixExpr.insert(i, "(0");
                    i = operandEnd + 3;
                }
            }
        }
        else if (curCh == '(' && i > 0)
        {
            // Do we have an operand and then a parentheses?
            QChar prevChar = infixExpr.at(i - 1);

            if (isOperand(prevChar))
            {
                // Insert multiplication before parentheses
                infixExpr.insert(i, '*');
                i++;
            }
        }
        else if (curCh == ')' && isOperand(nextChar))
        {

            // Do we have a parentheses and then an operand?
            // Insert multiplication after parentheses
            infixExpr.insert(i + 1, '*');
            i++;

        }
        else if (curCh == ')' && nextChar == '(')
        {
            // Do we have two different opposite parentheses next to each other?
            // Insert multiplication in between them
            infixExpr.insert(i + 1, '*');
            i++;
        }

        // Update expLen with new string length
        expLen = infixExpr.length();
    }

    // Return modified expression.
    return infixExpr;
}

// Converts the given infix expression to postfix
// and sets the current expression to the result.
// Returns true if successful.
// Returns false if an error occurs (Invalid expression)
bool PostfixExpression::fromInfix(QString infixExpr)
{
    if (infixExpr.isEmpty())
    {
        this->expr = "";
        return true;
    }

    // Fix unary negations and parentheses multiplication
    infixExpr = fixNegationsAndMult(infixExpr);

    QString newExp = "";
    std::stack<QChar> expStack;
    const QChar STACK_BASE = 'B';

    // Push char to keep track of the base of the stack
    // This is to avoid some issues I ran into when the
    // stack becomes empty
    expStack.push(STACK_BASE);

    const int expLen = infixExpr.length();

    // Loop through each char in the expr string
    for (int i = 0; i < expLen; i++)
    {
        QChar curCh = infixExpr.at(i);

        // Is the current char an operand?
        if (isOperand(curCh))
        {
            // Extract the entire multi-digit
            // operand using a loop. Automatically
            // checks for decimal points, and
            // returns false if there is more than
            // one for the current operand.
            bool usedPeriod = false;

            while (i < expLen && isOperand(curCh))
            {
                if (curCh == '.')
                {
                    // Invalid operand?
                    if (usedPeriod) return false;
                    else usedPeriod = true;
                }

                // Append operand to postfix expression string
                // one char at a time.
                newExp.append(curCh);

                i++;
                if (i < expLen) curCh = infixExpr.at(i);
            }

            // A vertical bar character is added to mark the end of the
            // multi-digit operator
            newExp.append('|');

            // Subtract 1 from i because the for loop will increment it again.
            i--;
        }
        else if (curCh == '(') {
            expStack.push('('); } // Push left parentheses to stack
        else if (curCh == ')')
        {
            // When a right parentheses is encountered, we must pop all
            // expressions off the stack until the matching left parentheses
            // is found.
            while (expStack.top() != STACK_BASE && expStack.top() != '(')
            {
                newExp.append(expStack.top());
                expStack.pop();
            }

            if (expStack.top() != '(') {
                // If we hit the base of the stack without finding its matching right parentheses
                // the expression is invalid.
                return false; }
            else {
                expStack.pop(); // Pop '(' operator off of the stack
            }
        }
        else
        {
            // Current char is an operator but not a parentheses.
            // We must pop and append all operators from the stack to the expression string
            // that have more precedence than the current operator
            while (expStack.top() != STACK_BASE && opPrecedence(curCh) <= opPrecedence(expStack.top()))
            {
                newExp.append(expStack.top());
                expStack.pop();
            }

            // Push current operator to stack
            expStack.push(curCh);
        }
    }

    // Pop remaining operators from stack and append them
    // to the expression string
    while (expStack.top() != STACK_BASE)
    {
        newExp.append(expStack.top());
        expStack.pop();
    }

    // Infix expression was successfully converted to postfix.
    // Update class member and return true.
    this->expr = newExp;
    return true;
}

// Attempts to solve the current postfix expression
// stored in the class.
// Result is set to the out reference variable on success.
// Returns true if expression is successfully solved.
// Returns false if an error is occured while sovling.
bool PostfixExpression::solve(double& out)
{
    if (expr.isEmpty())
    {
        out = 0.0;
        return true;
    }

    std::stack<double> operandStack;

    const int expLen = expr.length();

    // Loop through every character in the postfix expression string
    for (int i = 0; i < expLen; i++)
    {
        QChar curCh = expr.at(i);

        // Is current char an operand?
        if (isOperand(curCh))
        {
            // If so, we need to push it to the stack.
            // Extract multi-digit operand using a loop.
            QString curOperand = "";

            while (curCh != '|')
            {
                if (i >= expLen || !isOperand(curCh)) return false;

                curOperand.append(curCh);
                i++;

                if (i < expLen) curCh = expr.at(i);
            }

            // Push it to the stack
            operandStack.push(curOperand.toDouble());
        }
        else
        {
            // Current char is an operator
            // Are there at least two operands on the stack?
            // If not, the expression is invalid.
            if (operandStack.size() < 2) return false;

            // Get first and second operands
            double op1 = operandStack.top();
            operandStack.pop();
            double op2 = operandStack.top();
            operandStack.pop();

            // Calculate result of current operator and
            // operands and then push it to the stack
            switch (curCh.unicode())
            {
                case '+':
                    operandStack.push(op2 + op1);
                    break;
                case '-':
                    operandStack.push(op2 - op1);
                    break;
                case '*':
                    operandStack.push(op2 * op1);
                    break;
                case '/':
                    if (op1 == 0) return false;
                    operandStack.push(op2 / op1);
                    break;
                case '^':
                    operandStack.push(pow(op2, op1));
                    break;
            }
        }
    }

    // The operand stack should now contain only a single value, the final answer.
    // If the stack is empty or has more than one value, the expression was invalid.
    if (operandStack.empty() || operandStack.size() > 1) return false;

    // Retrieve final result value and return true.
    out = operandStack.top();
    operandStack.pop();

    return true;
}

// Returns the precedence of the given operator
int PostfixExpression::opPrecedence(QChar op)
{
    if (op == '^') {
        return 3;
    }
    else if (op == '*' || op == '/') {
        return 2;
    }
    else if (op == '+' || op == '-') {
        return 1;
    }
    else
    {
        return -1;
    }
}

// Returns true if the given character is a valid
// operand (0-9, or '.')
bool PostfixExpression::isOperand(QChar op)
{
    if (op >= '0' && op <= '9') return true;
    if (op == '.') return true;

    return false;
}

// Returns the current postfix expression string
QString PostfixExpression::toString()
{
    return this->expr;
}

// ===================================================
// End Of File
// ===================================================
