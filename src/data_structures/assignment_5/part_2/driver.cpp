#include <iostream>
#include <string>
#include "ArrayStack.h"
using namespace std;

void validateCharacters(char[], int);
bool validateStack(StackInterface<char>*);
bool validateResult(StackInterface<char>*);

const int OPERATORS[] = { '+', '-', '*', '/' },
          MAX_LENGTH=64,
          MIN_ASCII_INT = 48,
          ASCII_INT_OFFSET = MIN_ASCII_INT,
          MAX_ASCII_INT = 57;

int main() {
    StackInterface<char>* expressionStack = new ArrayStack<char>();
    int rawValue,
        operand2,
        operand1,
        result;
    char userExpression[MAX_LENGTH],
         another;
    bool isOperator,
         validStack,
         validResult;

    cout << "Enter postfix expression (e.g. 2 3 4 + *): " << endl;
    cin.getline(userExpression, MAX_LENGTH);

    do {

        validateCharacters(userExpression, MAX_LENGTH);  // Loops until valid characters entered

        for (int i=0; userExpression[i] != '\0'; i++) {

            isOperator = find(begin(OPERATORS), end(OPERATORS), userExpression[i]) != end(OPERATORS);

            if (!isOperator && userExpression[i] != ' ') {
                expressionStack->push(userExpression[i]);
                continue;
            } else if (userExpression[i] == ' ')
                continue;

            // Validate for empty stack - second operand
            validStack = !expressionStack->isEmpty();
            if (!validStack) break;

            rawValue = expressionStack->peek();
            operand2 = (rawValue >= MIN_ASCII_INT && rawValue <= MAX_ASCII_INT) ? rawValue - ASCII_INT_OFFSET : rawValue;
            expressionStack->pop();

            // Validate for empty stack - first operand
            validStack = !expressionStack->isEmpty();
            if (!validStack) break;

            operand1 = expressionStack->peek() - ASCII_INT_OFFSET;
            expressionStack->pop();

            switch (userExpression[i]) {
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

        validResult = validStack ? validateResult(expressionStack) : false;

        // Prompt about invalid expression or another iteration
        if (!validStack) {
            cout << "\nMalformed expression: too many operators or unordered stack elements. Enter another postfix expression: " << endl;
            cin.getline(userExpression, MAX_LENGTH);
        } else if (!validResult) {
            cout << "\nMalformed expression: Final stack contains more than the result. Enter another postfix expression: " << endl;
            cin.getline(userExpression, MAX_LENGTH);
        } else {
            cout << "\nMore expressions (Y/N)? ";
            cin >> another;
            if (tolower(another) == 'y') {
                cin.ignore();
                cout << "Enter another postfix expression: " << endl;
                cin.getline(userExpression, MAX_LENGTH);
            }
        }

    } while (tolower(another) == 'y' || !validStack || !validResult);

    return 0;
}

// Validate for illegal characters in entered expression (i.e. letters, punctuation); return a valid expression
void validateCharacters(char expression[], int size) {
    bool invalidExpression = false,
         isOperator;
    char invalidChar;

    do {
        if (invalidExpression) {
            cout << "Invalid character encountered: " << invalidChar << ". Enter another postfix expression: " << endl;
            cin.getline(expression, size);
        }

        for (int i=0; expression[i] != '\0'; i++) {
            isOperator = find(begin(OPERATORS), end(OPERATORS), expression[i]) != end(OPERATORS);
            invalidExpression = (!isdigit(expression[i]) && !isOperator && expression[i] != ' ') ? true : false;
            if (invalidExpression) {
                invalidChar = expression[i];
                break;
            }
        }
    } while (invalidExpression);
}


// Validate for single-element stack after algorithm
bool validateResult(StackInterface<char>* stack) {
    int finalResult = stack->peek(); // preserve result before popping
    int valid;

    stack->pop();

    if (stack->isEmpty()) {
        cout << "The value of the expression is " << finalResult << endl;
        valid = true;
    } else
        valid = false;
    
    return valid;
}