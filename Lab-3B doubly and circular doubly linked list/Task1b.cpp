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

        // Making it circular
        last->next = head;
        head->prev = last;
    }

    // Display the list from the head to the end
    void display()
    {
        if (!head)
            return; // No nodes to display

        Node *p = head;
        do
        {
            cout << p->data << " ";
            p = p->next;
        } while (p != head);

        cout << endl;
    }

    // Length of the list
    int length()
    {
        if (!head)
            return 0; // No nodes

        Node *p = head;
        int len = 0;
        do
        {
            len++;
            p = p->next;
        } while (p != head);
        return len;
    }

    // Insert value at the given index
    void insert(int index, int value)
    {
        // Check if the index is valid
        if (index < 0 || index > length())
        {
            return;
        }

        // Create the new node
        Node *t = new Node;
        t->data = value;

        // Inserting at the beginning
        if (index == 0)
        {
            if (head == NULL)
            {
                // Empty list
                head = t;
                head->next = head;
                head->prev = head;
            }
            else
            {
                // Non-empty list
                Node *p = head;
                while (p->next != head)
                {
                    p = p->next;
                }
                p->next = t;
                t->prev = p;
                t->next = head;
                head->prev = t;
                head = t;
            }
        }
        else
        {
            // Inserting at other positions
            Node *p = head;
            for (int i = 0; i < index - 1; i++)
            {
                p = p->next;
            }
            // Now p is the node before the insertion point
            t->next = p->next;
            t->prev = p;
            p->next->prev = t;
            p->next = t;
        }
    }
    void Delete(int index)
    {
        struct Node *p = head;
        if (index < 1 || index > length())
            return;
        if (index == 1)
        {
            if (head->next == NULL)
            {
                delete head;
                head = NULL;
            }
            while (p->next != head)
            {
                p = p->next;
            }
            Node *temp = head;
            head = head->next;
            head->prev = p;
            p->next = head;
            delete temp;
        }
        else
        {
            for (int i = 0; i < index - 1; i++)
            {
                p = p->next;
            }
            Node *q = p->next;
            p->next = q->next;
            q->next->prev = p;
            delete q;
        }
    }
};

int main()
{
    int A[] = {10, 20, 30, 40, 50};
    DoublyLinkedList dll(A, 5);
    cout << "ORIGINAL" << endl;
    dll.display();
    cout << "inserting at the beginnning" << endl;
    dll.insert(0, 9);
    dll.display();

    cout << endl;
    cout << "inserting at last" << endl;
    dll.insert(dll.length(), 99);
    dll.display();

    cout << endl;
    cout << "inserting at given index" << endl;
    int index, value;
    cout << "enter the index: ";
    cin >> index;
    cout << "enter the value: ";
    cin >> value;
    dll.insert(index, value);
    dll.display();
    cout << endl;
    cout << "deleting a node" << endl;
    dll.Delete(1);
    dll.display();
    cout << "again deleting a node" << endl;
    dll.Delete(4);
    dll.display();

    return 0;
}
