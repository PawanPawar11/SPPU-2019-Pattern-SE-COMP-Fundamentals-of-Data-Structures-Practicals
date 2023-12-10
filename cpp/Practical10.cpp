/*
Implement C++ program for expression conversion as infix to postfix
and its evaluation - using stack based on given conditions.
a) Operands and operator, both must be single character.
b) Input postfix expression must be in a desired format.
*/
#include <iostream>
#include <stack>
#include <cctype>

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char c)
{
    if (c == '+' || c == '-')
    {
        return 1;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    return -1; // If not an operator
}

std::string infixToPostfix(const std::string &expression)
{
    std::stack<char> operatorStack;
    std::string postfix;

    for (char c : expression)
    {
        if (std::isalnum(c))
        { // If character is an operand, add it to the postfix expression
            postfix += c;
        }
        else if (c == '(')
        { // Push opening parenthesis onto the stack
            operatorStack.push(c);
        }
        else if (c == ')')
        { // Pop operators from the stack and add to postfix until '(' is encountered
            while (!operatorStack.empty() && operatorStack.top() != '(')
            {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            if (!operatorStack.empty())
            {
                operatorStack.pop(); // Pop '(' from the stack
            }
        }
        else if (isOperator(c))
        { // If character is an operator
            while (!operatorStack.empty() && precedence(c) <= precedence(operatorStack.top()))
            {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(c);
        }
    }

    // Pop remaining operators from the stack and add to postfix
    while (!operatorStack.empty())
    {
        postfix += operatorStack.top();
        operatorStack.pop();
    }

    return postfix;
}

int evaluatePostfix(const std::string &postfix)
{
    std::stack<int> operandStack;

    for (char c : postfix)
    {
        if (std::isdigit(c))
        {
            operandStack.push(c - '0');
        }
        else if (isOperator(c))
        {
            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
            operandStack.pop();

            switch (c)
            {
            case '+':
                operandStack.push(operand1 + operand2);
                break;
            case '-':
                operandStack.push(operand1 - operand2);
                break;
            case '*':
                operandStack.push(operand1 * operand2);
                break;
            case '/':
                operandStack.push(operand1 / operand2);
                break;
            }
        }
    }

    return operandStack.top();
}

int main()
{
    std::string infixExpression;
    std::cout << "Enter infix expression: ";
    std::getline(std::cin, infixExpression);

    std::string postfixExpression = infixToPostfix(infixExpression);
    std::cout << "Postfix expression: " << postfixExpression << std::endl;

    int result = evaluatePostfix(postfixExpression);
    std::cout << "Result after evaluation: " << result << std::endl;

    return 0;
}
