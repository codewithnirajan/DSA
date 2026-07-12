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
    Node* temp;

    temp = head;

    newNode->next = temp;
    newNode->data = value;
    newNode->prev = NULL;

    if (temp != NULL)
    {
        temp->prev = newNode;
    }

    head = newNode;
}

// Insert at End
void insertEnd(int value)
{
    Node* newNode = new Node();

    // If list is empty
    if (head == NULL)
    {
        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = NULL;

        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = temp;

    temp->next = newNode;
}

// Delete from Beginning
void deleteBeginning()
{
    if (head == NULL)
    {
        return;
    }

    Node* temp1;
    Node* temp2;

    temp1 = head;
    temp2 = head->next;

    if (temp2 != NULL)
    {
        temp2->prev = NULL;
    }

    head = temp2;

    delete temp1;
}

// Delete from End
void deleteEnd()
{
    if (head == NULL)
    {
        return;
    }

    // Only one node
    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }

    Node* temp;
    Node* save;

    temp = head;

    while (temp->next != NULL)
    {
        save = temp;
        temp = temp->next;
    }

    save->next = NULL;

    delete temp;
}

// Display
void display()
{
    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}
// Display Address
void displayAddress()
{
    Node* temp = head;

    cout << "\n-------------------------------------------------------------\n";
    cout << "Address\t\tData\tPrev\t\tNext\n";
    cout << "-------------------------------------------------------------\n";

    while (temp != NULL)
    {
        cout << temp << "\t"
             << temp->data << "\t"
             << temp->prev << "\t"
             << temp->next << endl;

        temp = temp->next;
    }

    cout << "-------------------------------------------------------------\n";
}

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
    displayAddress();

    return 0;
}