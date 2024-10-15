// assumption: considered the position/index as: if the index/position value is 3 it means the value will be inserted after 3 nodes
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
        first = new Node;
        first->data = A[0];
        first->next = first;
        last = first;

        for (int i = 1; i < n; i++)
        {
            t = new Node;
            t->data = A[i];
            t->next = last->next;
            last->next = t;
            last = t;
        }
    }

    ~LinkedList()
    {
        Node *p = first;
        if (first != NULL)
        {
            do
            {
                Node *temp = p;
                p = p->next;
                delete temp;
            } while (p != first);
        }
    }

    void display()
    {
        if (first == NULL)
            return;

        Node *p = first;
        do
        {
            cout << p->data << " ";
            p = p->next;
        } while (p != first);
        cout << endl;
    }

    int length(Node *p)
    {
        if (first == NULL)
            return 0;

        int len = 0;
        do
        {
            len++;
            p = p->next;
        } while (p != first);
        return len;
    }

    void insert(int index, int x)
    {
        Node *t;
        Node *p = first;

        if (index < 0 || index > length(first))
            return;

        if (index == 0)
        {
            t = new Node;
            t->data = x;

            if (first == NULL)
            {
                first = t;
                first->next = first;
            }
            else
            {
                while (p->next != first)
                    p = p->next;
                p->next = t;
                t->next = first;
                first = t;
            }
        }
        else
        {
            for (int i = 0; i < index - 1; i++)
                p = p->next;

            t = new Node;
            t->data = x;
            t->next = p->next;
            p->next = t;
        }
    }

    int Delete(int index)
    {
        if (index < 1 || index > length(first))
            return -1;

        Node *p = first;
        int x = -1;

        if (index == 1)
        {
            while (p->next != first) // Find the last node
                p = p->next;

            x = first->data;

            if (first == p) // Only one node
            {
                delete first;
                first = NULL;
            }
            else
            {
                p->next = first->next; // Update last node to point to new first
                Node *temp = first;
                first = first->next; // Move first to the next node
                delete temp;         // Delete old first node
            }
        }
        else
        {
            for (int i = 0; i < index - 2; i++)
                p = p->next;

            Node *q = p->next;
            p->next = q->next;
            x = q->data;
            delete q;
        }
        return x;
    }
};

int main()
{
    int A[] = {1, 2, 3, 2, 1};
    LinkedList ll(A, 5);

    cout << "Original list:" << endl;
    ll.display();

    cout << "Inserting at the first node:" << endl;
    ll.insert(0, 91);
    ll.display();

    cout << "Inserting at the last node:" << endl;
    ll.insert(6, 90);
    ll.display();

    cout << "Inserting at a given index:" << endl;
    int index, val;
    cout << "Enter the index: ";
    cin >> index;
    cout << "Enter the value: ";
    cin >> val;
    ll.insert(index, val);
    ll.display();

    cout << "Deleting a node:" << endl;
    cout << "Enter the node index to delete: ";
    cin >> index;
    ll.Delete(index);
    ll.display();

    return 0;
}
