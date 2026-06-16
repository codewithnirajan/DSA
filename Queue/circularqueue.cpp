#include <iostream>
using namespace std;

#define MAX 5

class CircularQueue
{
private:
    int queue[MAX];
    int front;
    int rear;

public:
    CircularQueue()
    {
        front = -1;
        rear = -1;
    }

    void enqueue(int item)
    {
        if (front == (rear + 1) % MAX)
        {
            cout << "Queue Full" << endl;
            return;
        }

        if (front == -1)
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAX;
        }

        queue[rear] = item;

        cout << item << " inserted" << endl;
    }

    void dequeue()
    {
        if (front == -1)
        {
            cout << "Queue Empty" << endl;
            return;
        }

        cout << queue[front] << " deleted" << endl;

        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }
    }

    void display()
    {
        if (front == -1)
        {
            cout << "Queue Empty" << endl;
            return;
        }

        cout << "Queue Elements: ";

        int i = front;

        while (true)
        {
            cout << queue[i] << " ";

            if (i == rear)
            {
                break;
            }

            i = (i + 1) % MAX;
        }

        cout << endl;
    }
};

int main()
{
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.display();

    q.dequeue();
    q.dequeue();

    q.display();

    q.enqueue(50);
    q.enqueue(60);

    q.display();

    q.enqueue(70);   // Queue Full

    return 0;
}