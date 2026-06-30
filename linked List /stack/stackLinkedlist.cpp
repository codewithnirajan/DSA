#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    void push(int x) {
        Node* newNode = new Node;

        newNode->data = x;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == NULL) {
            cout << "Stack Underflow\n";
            return;
        }

        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek() {
        if (top == NULL) {
            cout << "Stack is empty\n";
            return -1;
        }

        return top->data;
    }

    bool isEmpty() {
        return top == NULL;
    }

    int size() {
        int count = 0;
        Node* temp = top;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        return count;
    }

    void display() {
        Node* temp = top;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Stack: ";
    s.display();

    cout << "Top element: " << s.peek() << endl;

    s.pop();

    cout << "After pop: ";
    s.display();

    cout << "Size = " << s.size() << endl;

    if (s.isEmpty())
        cout << "Stack is empty\n";
    else
        cout << "Stack is not empty\n";

    return 0;
}