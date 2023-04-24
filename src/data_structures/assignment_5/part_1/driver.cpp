#include <iostream>
#include <string>
#include "ArrayStack.h"
using namespace std;

int calculatePostfixExpression(char[]);

int main() {
    const int MAX_LENGTH=49;
    char userExpression[MAX_LENGTH],
         another;

    do {
        if (tolower(another) == 'y') cin.ignore();

        cout << "Enter postfix expression (e.g. 2 3 4 + *): " << endl;
        cin.getline(userExpression, MAX_LENGTH);

        cout << "The value of the expression is " << calculatePostfixExpression(userExpression) << endl;

        cout << "\nMore expressions (Y/N)? ";
        cin >> another;

    } while (tolower(another) == 'y');

    return 0;
}

int calculatePostfixExpression(char expression[]) {
    const int MIN_ASCII_INT = 48,
              ASCII_INT_OFFSET = MIN_ASCII_INT,
              MAX_ASCII_INT = 57;
    StackInterface<char>* expressionStack = new ArrayStack<char>();
    int operators[] = { '+', '-', '*', '/' },
        rawValue,
        operand2,
        operand1,
        result;
    bool isOperator;

    for (int i=0; expression[i] != '\0'; i++) {

        isOperator = find(begin(operators), end(operators), expression[i]) != end(operators);

        if (!isOperator && expression[i] != ' ') {
            expressionStack->push(expression[i]);
            continue;
        } else if (expression[i] == ' ')
            continue;

        rawValue = expressionStack->peek();
        operand2 = (rawValue >= MIN_ASCII_INT && rawValue <= MAX_ASCII_INT) ? rawValue - ASCII_INT_OFFSET : rawValue;
        expressionStack->pop();
        operand1 = expressionStack->peek() - ASCII_INT_OFFSET;
        expressionStack->pop();

        switch (expression[i]) {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                result = operand1 / operand2;
                break;
        }

        expressionStack->push(result);
    }

    return expressionStack->peek();
}