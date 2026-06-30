#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Display
void display(Node* head) {

    if (head == NULL) {
        cout << "Empty List\n";
        return;
    }

    Node* ptr = head;

    cout << "List: ";

    do {
        cout << ptr->data << " ";
        ptr = ptr->next;
    } while (ptr != head);

    cout << "(back to head)\n";
}

// Insert at Beginning
void insertAtBeginning(Node*& head, int value) {

    cout << "\nInserting " << value << " at the beginning...\n";

    Node* newNode = new Node;
    newNode->data = value;

    if (head == NULL) {

        cout << "List is empty.\n";

        head = newNode;
        newNode->next = head;
    }
    else {

        Node* ptr = head;

        cout << "Finding the last node...\n";

        while (ptr->next != head)
            ptr = ptr->next;

        cout << "Last node found: " << ptr->data << endl;

        newNode->next = head;
        ptr->next = newNode;
        head = newNode;
    }

    cout << value << " inserted successfully.\n";
}

// Insert at End
void insertAtEnd(Node*& head, int value) {

    cout << "\nInserting " << value << " at the end...\n";

    Node* newNode = new Node;
    newNode->data = value;

    if (head == NULL) {

        cout << "List is empty.\n";

        head = newNode;
        newNode->next = head;
    }
    else {

        Node* ptr = head;

        cout << "Traversing to the last node...\n";

        while (ptr->next != head)
            ptr = ptr->next;

        cout << "Last node is " << ptr->data << endl;

        ptr->next = newNode;
        newNode->next = head;
    }

    cout << value << " inserted successfully.\n";
}

// Delete from Beginning
void deleteFromBeginning(Node*& head) {

    cout << "\nDeleting from beginning...\n";

    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* ptr = head;

    while (ptr->next != head)
        ptr = ptr->next;

    cout << "Last node is " << ptr->data << endl;
    cout << "Deleting node " << head->data << endl;

    Node* temp = head;
    head = temp->next;
    ptr->next = head;

    delete temp;

    cout << "Deletion successful.\n";
}

// Delete from End
void deleteFromEnd(Node*& head) {

    cout << "\nDeleting from end...\n";

    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* ptr = head;
    Node* temp = NULL;

    while (ptr->next != head) {
        temp = ptr;
        ptr = ptr->next;
    }

    cout << "Last node is " << ptr->data << endl;
    cout << "Previous node is " << temp->data << endl;

    temp->next = head;

    delete ptr;

    cout << "Deletion successful.\n";
}

int main() {

    Node* head = NULL;

    insertAtBeginning(head, 20);
    display(head);

    insertAtBeginning(head, 10);
    display(head);

    insertAtEnd(head, 30);
    display(head);

    insertAtEnd(head, 40);
    display(head);

    deleteFromBeginning(head);
    display(head);

    deleteFromEnd(head);
    display(head);

    return 0;
}