#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
class LinkedList
{
private:
    Node *first;

public:
    LinkedList() { first = NULL; }
    LinkedList(int A[], int n)
    {
        Node *last, *t;
        int i = 0;

        first = new Node;
        first->data = A[0];
        first->next = NULL;
        last = first;

        for (i = 1; i < n; i++)
        {
            t = new Node;
            t->data = A[i];
            t->next = NULL;
            last->next = t;
            last = t;
        }
    }
    ~LinkedList()
    {
        Node *p = first;
        while (first)
        {
            first = first->next;
            delete p;
            p = first;
        }
    }
    void displayrec(Node *p)
    {
        if (p)
        {
            cout << p->data << " ";
            displayrec(p->next);
        }
    }
    int getLength(Node *p)
    {
        if (p)
        {
           return getLength(p->next)+1;
        }
        return 0;
    }
    Node *getFirst()
    {
        return first;
    }
};
int main()
{
    int A[] = {17, 15, 8, 12, 10, 5, 4, 1, 7, 6};

    LinkedList ll1(A, 10);
    cout << "Length of the list is: ";
    cout << ll1.getLength(ll1.getFirst());
}