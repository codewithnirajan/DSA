#include <iostream>
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
            cout << value << " pushed into stack" << endl;
        }
    }

    // Pop operation
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
        }
        else {
            cout << st[top] << " popped from stack" << endl;
            top--;
        }
    }

    // Peek operation
    void peek() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
        }
        else {
            cout << "Top element is: " << st[top] << endl;
        }
    }

    // Display stack
    void display() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
        }
        else {
            cout << "Stack elements are: ";
            for (int i = top; i >= 0; i--) {
                cout << st[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack s;

    s.peek();

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    s.pop();

    s.peek();

    return 0;
}