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
    void evenodd()
    {
        Node *evenStart = NULL, *evenEnd = NULL;
        Node *oddStart = NULL, *oddEnd = NULL;
        Node *p = first;

        while (p != NULL)
        {
            if (p->data % 2 == 0)
            {
                if (evenStart == NULL) // First even node
                {
                    evenStart = p;
                    evenEnd = evenStart;
                }
                else
                {
                    evenEnd->next = p;
                    evenEnd = evenEnd->next;
                }
            }
            else // Odd node
            {
                if (oddStart == NULL) // First odd node
                {
                    oddStart = p;
                    oddEnd = oddStart;
                }
                else
                {
                    oddEnd->next = p;
                    oddEnd = oddEnd->next;
                }
            }
            p = p->next;
        }

        // If there are no even nodes
        if (evenStart == NULL)
        {
            first = oddStart;
            return;
        }

        // Combine even and odd lists
        evenEnd->next = oddStart; // if there are only even nodes then it will point to null

        // Set first to the new head (start of even list)
        first = evenStart;
        // End the odd list
        if (oddEnd != NULL)
        {
            oddEnd->next = NULL;
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
};
int main()
{
    int A[] = {17, 15, 8, 12, 10, 5, 4, 1, 7, 6};

    LinkedList ll1(A, 10);
    cout << "ORIGINAL" << endl;
    ll1.display();

    ll1.evenodd();
    cout << endl;
    cout << "MODIFIED" << endl;
    ll1.display();

    cout << endl
         << endl;

    int B[] = {8, 12, 10, 5, 4, 1, 6};

    LinkedList ll2(B, 7);
    cout << "ORIGNIAL" << endl;
    ll2.display();
    ll2.evenodd();
    cout << endl;
    cout << "MODIFIED" << endl;
    ll2.display();

    cout << endl
         << endl;

    int C[] = {8, 12, 10};

    LinkedList ll3(C, 3);
    cout << "ORIGNIAL" << endl;
    ll3.display();
    ll3.evenodd();
    cout << endl;
    cout << "MODIFIED" << endl;
    ll3.display();


    cout << endl
         << endl;

    int D[] = {1,3,5,7};

    LinkedList ll4(D, 4);
    cout << "ORIGNIAL" << endl;
    ll4.display();
    ll4.evenodd();
    cout << endl;
    cout << "MODIFIED" << endl;
    ll4.display();
}