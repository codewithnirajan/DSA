#include <iostream>
using namespace std;

#define MAX 5

class Queue
{
private:
    int queue[MAX];
    int front;
    int rear;

public:
    Queue()
    {
        front = 0;
        rear = -1;
    }

    void enqueue(int item)
    {
        if (rear == MAX - 1)
        {
            cout << "Queue Full" << endl;
            return;
        }

        rear = rear + 1;
        queue[rear] = item;

        cout << item << " inserted" << endl;
    }

    void dequeue()
    {
        if (front > rear)
        {
            cout << "Queue Empty" << endl;
            return;
        }

        cout << queue[front] << " deleted" << endl;
        front = front + 1;
    }

    void display()
    {
        if (front > rear)
        {
            cout << "Queue Empty" << endl;
            return;
        }

        cout << "Queue elements: ";

        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.dequeue();

    q.display();

    q.enqueue(40);
    q.enqueue(50);

    q.display();

    return 0;
}