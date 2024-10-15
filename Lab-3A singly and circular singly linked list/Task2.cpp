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
    Node *getMid(Node *head)
    {
        Node *slow = head;
        Node *fast = head->next;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    Node *reverse(Node *head)
    {
        Node *q = NULL, *r = NULL;
        Node *p = head;

        while (p != NULL)
        {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        return q;
    }
    bool isPalindrome()
    {
        if (first->next == NULL)
            return true;
        Node *middle = getMid(first);

        Node *temp = middle->next;
        middle->next = reverse(temp);

        Node *head1 = first;
        Node *head2 = middle->next;
        while (head2 != NULL)
        {
            if (head1->data != head2->data)
            {
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        // Node *p;
        // p = first;
        // while (p != NULL)
        // {
        //     cout << p->data << " ";
        //     p = p->next;
        // }
        middle->next = reverse(temp);
        return true;
    }
    bool ispalindrome2()
    {
        if(first->next==NULL)return true;
        Node* middle=getMid(first);
        Node *temp = middle->next;

        middle->next=reverse(temp);

        Node *head1=first;
        Node *head2 = middle->next;
        while(head2!=NULL)
        {
            if(head1->data!=head2->data) return false;
            head1=head1->next;
            head2=head2->next;
        }
        middle->next=reverse(temp);
    }
};
int main()
{
    int size;
    cout << "Enter the size: ";
    cin >> size;
    int *A;
    A = new int[size];
    for (int i =0; i< size; i++)
    {
        cin >> A[i];
    }
    LinkedList ll(A, size);
    ll.display();
    cout << endl;
    if (ll.ispalindrome2())
        cout << "yes the list is palindrome" << endl;
    else
        cout << "no the list is not palindrome";
}