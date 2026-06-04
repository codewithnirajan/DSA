#include <iostream>
#include <cmath>
using namespace std;

#define MAX 100

class Stack {
private:
    int st[MAX];
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
            st[top] = value;
        }
    }

    // Pop operation
    int pop() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        else {
            int value = st[top];
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

// Function to evaluate postfix expression
int evaluatePostfix(string exp) {

    Stack s;

    for (int i = 0; i < exp.length(); i++) {

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
                s.push(val2 + val1);
                break;

            case '-':
                s.push(val2 - val1);
                break;

            case '*':
                s.push(val2 * val1);
                break;

            case '/':
                s.push(val2 / val1);
                break;

            case '^':
                s.push(pow(val2, val1));
                break;
            }
        }
    }

    return s.pop();
}

int main() {

    string exp = "23*5+";
    // string exp = "46*8/72+5-+23^+";
    // 46*8/72+5-+23^+

    cout << "Postfix Expression = " << exp << endl;
    cout << "Result = " << evaluatePostfix(exp) << endl;

    return 0;
}