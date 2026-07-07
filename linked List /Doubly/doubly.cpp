#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

// Insert at Beginning
void insertBeginning(int value)
{
    Node* newNode = new Node();

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
    {
        head->prev = newNode;
    }

    head = newNode;
}

// Insert at End
void insertEnd(int value)
{
    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

/*

Assignment
Implement the following functions:

1. Insert a node at Position P (Position starts from 1)

void insertPosition(int position, int value);

2. Delete a node from Position P (Position starts from 1)

void deletePosition(int position);

*/

// Delete from Beginning
void deleteBeginning()
{
    if (head == NULL)
    {
        return;
    }

    Node* temp = head;
    head = head->next;

    if (head != NULL)
    {
        head->prev = NULL;
    }

    delete temp;
}

// Delete from End
void deleteEnd()
{
    if (head == NULL)
    {
        return;
    }

    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    delete temp;
}

// Display
void display()
{
    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}
/*
void displayAddress()
{
    Node* temp = head;

    cout << "\nAddress\t\tData\tPrev\t\tNext\n";

    while (temp != NULL)
    {
        cout << temp << "\t"
             << temp->data << "\t"
             << temp->prev << "\t"
             << temp->next << endl;

        temp = temp->next;
    }
}
    */

int main()
{
    insertBeginning(20);
    insertBeginning(10);

    insertEnd(30);
    insertEnd(40);

    cout << "List: ";
    display();

    deleteBeginning();

    cout << "After deleting from beginning: ";
    display();

    deleteEnd();

    cout << "After deleting from end: ";
    display();
    
    // displayAddress();

    return 0;
}