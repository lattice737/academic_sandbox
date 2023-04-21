#include<iostream>
#include<string>

using namespace std;

bool bracesBalanced(string);
bool stringInLanguage(string);
void convertInfixExpression(char*);

int main() {

    cout << "{a{b}c} -> " << (bracesBalanced ? "true" : "false") << endl
         << "{a{bc}  -> " << (bracesBalanced ? "true" : "false") << endl
         << "{ab}c}  -> " << (bracesBalanced ? "true" : "false") << endl;
    
    cout << "a$a   -> " << (stringInLanguage ? "true" : "false") << endl
         << "ab$ab -> " << (stringInLanguage ? "true" : "false") << endl
         << "ab$a  -> " << (stringInLanguage ? "true" : "false") << endl
         << "ab$ba -> " << (stringInLanguage ? "true" : "false") << endl;

    cout << "7 3 - 2 + -> " << calculatePostfixExpression("7 3 - 2 +");

    // cout << " a / b * c -> " << convertPostfixExpression("a / b * c");

    return 0;
}

bool bracesBalanced(string chars) {
    Stack aStack = Stack();
    bool balanced = true;
    char thisChar;
    int i = 0;  // Trackes character position in string

    while (balanced && i < chars.length()) {
        thisChar = chars[i];
        i++;

        if (thisChar == '{')
            aStack.push('{');
        else if (thisChar == '}') {
            if (!aStack.isEmpty())
                aStack.pop();
            else
                balanced = false;
        }
    }

    return balanced && aStack.isEmpty() ? true : false;
}

bool stringInLanguage(string someString) {
    Stack aStack = Stack();
    char thisChar = someString[0],
         stackTop;
    bool inLanguage = true;
    int i = 0;

    while (thisChar != '$') {
        aStack.push(thisChar);
        i++;
        thisChar = someString[i];
    }

    i++;

    while (inLanguage && i < someString.length()) {
        if (!aStack.isEmpty()) {
            stackTop = aStack.peek();
            aStack.pop();
            thisChar = someString[i];
            if (stackTop == thisChar)
                i++;
            else
                inLanguage == false;
        } else
            inLanguage = false;
    }

    return inLanguage && aStack.isEmpty() ? true : false;
}

double calculatePostfixExpression(string expression) {
    Stack expressionStack = Stack();
    int operands[] = { '+', '-', '*', '/'};
    double operand2, operand1, result;
    
    for (char thisChar : expression) {
        if (operands.contains(thisChar))    // check if operand array contains char
            expressionStack.push(thisChar);
        else {
            operand2 = expressionStack.peek(); // get top item
            expressionStack.pop();
            operand1 = expressionStack.peek();
            expressionStack.pop();

            switch (thisChar) {
                case '+': result = static_cast<double>(operand1) + static_cast<double>(operand2);
                case '-': result = static_cast<double>(operand1) - static_cast<double>(operand2);
                case '*': result = static_cast<double>(operand1) * static_cast<double>(operand2);
                case '/': result = static_cast<double>(operand1) / static_cast<double>(operand2);
            }

            expressionStack.push(result);
        }
    }

    return expressionStack.peek();
}

void convertInfixExpression(char* expression) {
    Stack operatorStack = Stack(); 
    char operators[] = {'+', '-', '*', '/'},
         thisChar;
    int i = 0;

    while (expression[i] != '\0') {
        thisChar = expression[i];
        switch (thisChar) {
            case '0':   // TODO STUB: test for operand
                // TODO append operand to end of postfixExpression
                break;
            case '(':
                operatorStack.push(thisChar);
                break;
            case operators.contains(thisChar):
                while (!operatorStack.isEmpty() && operatorStack.peek() != '!' && precedence(thisChar) <= precedence(operatorStack.peek())) {
                    // TODO append operatorStack.peek() to the end of postfixExpression
                    operatorStack.pop();
                }
                operatorStack.push(thisChar);
                break;
            case ')':
                while (operatorStack.peek() != '(') {
                    // TODO append operatorStack.peek() to the end of postfixExpression
                    operatorStack.pop();
                }
                operatorStack.pop();
                break;
        }
        i++;
    }

    while (!operatorStack.isEmpty()) {
        // TODO append operatorStack.peek() to the end of postfixExpression
        operatorStack.pop();
    }

    // TODO return postfixExpression
}

