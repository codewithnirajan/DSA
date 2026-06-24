#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Insert at Beginning
void insertAtBeginning(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Insert at End
void insertAtEnd(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Homework: Insert at Position
void insertAtPosition(int position, int value) {
    // Write your code here
}

// Delete at Beginning
void deleteAtBeginning() {
    if (head == NULL) {
        cout << "List is Empty!" << endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

// Homework: Delete at End
void deleteAtEnd() {
    // Write your code here
}

// Homework: Delete at Position
void deleteAtPosition(int position) {
    // Write your code here
}

// Search
void searchNode(int value) {
    Node* temp = head;
    int position = 1;

    while (temp != NULL) {
        if (temp->data == value) {
            cout << value << " found at position "
                 << position << endl;
            return;
        }

        temp = temp->next;
        position++;
    }

    cout << value << " not found!" << endl;
}

// Display
void display() {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main() {

    insertAtBeginning(10);
    insertAtEnd(20);
    insertAtEnd(30);

    cout << "Initial List: ";
    display();

    // Test after completing homework functions

    // insertAtPosition(1, 15);
    // display();

    // deleteAtEnd();
    // display();

    // deleteAtPosition(1);
    // display();

    searchNode(20);
    searchNode(100);

    return 0;
}