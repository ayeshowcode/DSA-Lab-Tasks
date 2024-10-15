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
    void display()
    {
        Node *p;
        p = first;
        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
    }
    void divisibleby3()
    {
        Node *p = first;
        Node *yesstart = NULL, *yesend = NULL;
        Node *nostart = NULL, *noend = NULL;
        // start use to keep track from where they start so we can link them at the end
        // end use to link while traversing

        while (p != NULL)
        {
            if (p->data % 3 == 0)
            {
                if (yesstart == NULL)
                {
                    yesstart = p;
                    yesend = yesstart;
                }

                else
                {
                    yesend->next = p;
                    yesend = yesend->next;
                }
            }
            else
            {

                if (nostart == NULL)
                {
                    nostart = p;
                    noend = nostart;
                }

                else
                {
                    noend->next = p;
                    noend = noend->next;
                }
            }
            p = p->next;
        }
        if (nostart == NULL)
        {
            first = yesstart;
            return;
        }
        noend->next = yesstart;
        first=nostart;
        if (yesend != NULL)
        {
            yesend->next = NULL;
        }
    }
};
int main()
{
    int A[] = {1, 2, 3, 4,5,6};
    LinkedList ll(A, 6);
    ll.display();
    cout << endl;
    ll.divisibleby3();
    cout << endl;
    ll.display();
}