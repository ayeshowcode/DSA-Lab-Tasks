#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    // Constructor to initialize a node
    Node() : data(0), prev(nullptr), next(nullptr) {}
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList
{
private:
    Node *head;

public:
    // Constructor to create a circular doubly linked list from an array
    DoublyLinkedList() : head(NULL) {}
    DoublyLinkedList(int A[], int n)
    {
        if (n <= 0)
            return; // No nodes to create if the array is empty

        Node *last;
        head = new Node(A[0]);
        last = head;

        for (int i = 1; i < n; i++)
        {
            Node *temp = new Node(A[i]);
            temp->prev = last;
            last->next = temp;
            last = temp;
        }
    }
    void display()
    {
        struct Node *p = head;
        while (p != NULL)
        {
            cout << p->data << ", ";
            p = p->next;
        }
        cout << endl;
    }
    void concate(DoublyLinkedList *L, DoublyLinkedList *M)
    {
        if (L->head == NULL)
        { 
            L->head = M->head;
            return;
        }

        if (M->head ==  NULL)
        {
            return;
        }

        Node *p = L->head;
        while (p->next != NULL)
            p = p->next;
        p->next = M->head;
        M->head->prev = p;
    }
    // Length of the list
    int length()
    {
        struct Node *p = head;
        int len = 0;
        while (p != NULL)
        {
            len++;
            p = p->next;
        }
        return len;
    }
    // Insert value at the given index
};

int main()
{
    int A[] = {10, 20, 30, 40, 50};
    DoublyLinkedList dll1(A, 5);
    cout << "list 1: " << endl;
    dll1.display();
    int B[] = {60, 70, 80};
    DoublyLinkedList dll2(B, 3);
    cout << "list 2: " << endl;
    dll2.display();
    DoublyLinkedList dll3;
    dll3.concate(&dll1, &dll2);
    cout << "concated" << endl;
    dll1.display();

    return 0;
}
