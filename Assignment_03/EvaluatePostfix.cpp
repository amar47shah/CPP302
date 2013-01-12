/*
 * EvaluatePostfix.cpp
 *
 *  Created on: Oct 7, 2012
 *      Author: amar
 */

#include <iostream>
#include <string>
#include <stack>
#include <cmath>
#include <cstdlib>

using namespace std;

class postfixEvaluator {
  public:
    explicit postfixEvaluator(const string&);
    int evaluate();

  private:
    bool isSolved();
    bool operatorIsNext();
    int nextOperand();
    char nextOperator();
    int stackPop();
    void stackPush(int);

    bool solved;
    int answer;
    string expression;
    stack<int> operandStack;
};

postfixEvaluator::postfixEvaluator(const string& exp) :
            solved(false), answer(0), expression(exp)
{
    if (expression.empty()) expression = "0";
}

int postfixEvaluator::evaluate()
{
    if (isSolved())
        return answer;
    while (!expression.empty()) {
        if (operatorIsNext()) {
            int b = stackPop();
            int a = stackPop();
            switch (nextOperator()) {
                case '+' : stackPush(a + b); break;
                case '-' : stackPush(a - b); break;
                case '*' : stackPush(a * b); break;
                case '/' : b = b == 0 ? 1 : b;  stackPush(a / b); break;
            }
        }
        else
            stackPush(nextOperand());
    }
    solved = true;
    return answer = stackPop();
}

bool postfixEvaluator::isSolved()
{
    return solved;
}

bool postfixEvaluator::operatorIsNext()
{
    if (expression.empty())
        return false;
    switch (expression[0]) {
        case '+' :
        case '-' :
        case '*' :
        case '/' :
            return true;
        default :
            return false;
    }
}

int postfixEvaluator::nextOperand()
{
    int i = (int) expression[0] - 48;
    expression.erase(0, 1);
    return i;
}

char postfixEvaluator::nextOperator()
{
    char c = expression[0];
    expression.erase(0, 1);
    return c;
}

int postfixEvaluator::stackPop()
{
    int i = operandStack.top();
    operandStack.pop();
    return i;
}

void postfixEvaluator::stackPush(int operand)
{
    operandStack.push(operand);
}

int main() {
    string postfixExp;
    char repeat;

    cout << "POSTFIX CALCULATOR" << endl;
    cout << "\tsingle-digit integer operands only" << endl;
    cout << "\t+, -, *, / operators only" << endl;

    do {
        cout << "Please enter a postfix expression: ";
        cin >> postfixExp;

        postfixEvaluator evaluator(postfixExp);
        cout << "\t" <<postfixExp << " = " << evaluator.evaluate() << endl;

        do {
            cout << "Evaluate another? (Y/N)? ";
            cin >> repeat;
        } while (repeat != 'Y' && repeat != 'y' && repeat != 'n' && repeat != 'N');

    } while (repeat == 'Y' || repeat == 'y');

    return 0;
}

