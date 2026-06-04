#include <iostream>
#include <cmath>
using namespace std;

#define MAX 100

class Stack {
private:
    int stack[MAX];
    int top;

public:
    // Constructor
    Stack() {
        top = -1;
    }

    // Push operation
    void push(int value) {
        if (top == MAX - 1) {
            cout << "Stack Overflow" << endl;
        }
        else {
            top++;
            stack[top] = value;
        }
    }

    // Pop operation
    int pop() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        else {
            int value = stack[top];
            top--;
            return value;
        }
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }
};

// Function to check operator
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' ||
            ch == '*' || ch == '/' ||
            ch == '^');
}

// Function to evaluate prefix expression
int evaluatePrefix(string exp) { 

    Stack s;

    // Scan from right to left
    for (int i = exp.length() - 1; i >= 0; i--) {

        char ch = exp[i];

        // If operand, push into stack
        if (ch >= '0' && ch <= '9') {
            s.push(ch - '0');
        }

        // If operator, perform operation
        else if (isOperator(ch)) {

            int val1 = s.pop();
            int val2 = s.pop();

            switch (ch) {

            case '+':
                s.push(val1 + val2);
                break;

            case '-':
                s.push(val1 - val2);
                break;

            case '*':
                s.push(val1 * val2);
                break;

            case '/':
                s.push(val1 / val2);
                break;

            case '^':
                s.push(pow(val1, val2));
                break;
            }
        }
    }

    return s.pop();
}

int main() {

    // string exp = "+*235";
    string exp = "-+*456/82";
    //-+*456/82

    cout << "Prefix Expression = " << exp << endl;
    cout << "Result = " << evaluatePrefix(exp) << endl;

    return 0;
}