#include <iostream>
using namespace std;

class Queue
{
private:
    int size;
    int front;
    int rear;
    int *Q;

public:
    Queue(int size)
    {
        this->size = size;
        front = rear = -1;
        Q = new int[size];
    }

    ~Queue()
    {
        delete[] Q;
    }

    void enqueue(int x)
    {
        if (rear == size - 1)
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            rear++;
            Q[rear] = x;
        }
    }
    int dequeue()
    {
        int x = -1;
        if (front == rear)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            front++;
            x = Q[front];
        }
        return x;
    }

    void display()
    {
        for (int i = front + 1; i <= rear; i++)
        {
            cout << Q[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    Queue q(10);

    // Customer IDs to be processed
    int customers[] = {13, 7, 4, 1, 6, 8, 10};

    // Enqueue all customers
    for (int i = 0; i < 7; i++)
    {
        q.enqueue(customers[i]);
    }

    q.display();

    q.dequeue(); 
    q.dequeue(); 

    q.display();

    return 0;
}