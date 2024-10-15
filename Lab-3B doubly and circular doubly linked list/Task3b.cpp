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
    DoublyLinkedList(int A[], int n)
    {
        if (n <= 0)
            return;

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

        last->next = head;
        head->prev = last;
    }

    // Display the list from the head to the end
    void display()
    {
        if (!head)
            return;

        Node *p = head;
        do
        {
            cout << p->data << " ";
            p = p->next;
        } while (p != head);

        cout << endl;
    }

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

    void swapNodes(int index1, int index2)
    {
        if (index1 == index2)
            return; // No need to swap if both indices are the same

        Node *node1 = nullptr, *node2 = nullptr;
        Node *p = head;
        int pos = 0;

        // Find node1
        do
        {
            if (pos == index1)
                node1 = p;
            if (pos == index2)
                node2 = p;
            p = p->next;
            pos++;
        } while (p != head);

        if (!node1 || !node2)
        {
            cout << "One or both indices are out of bounds!" << endl;
            return;
        }

        // Swap node1 and node2
        if (node1->prev)
            node1->prev->next = node2;
        if (node1->next)
            node1->next->prev = node2;
        if (node2->prev)
            node2->prev->next = node1;
        if (node2->next)
            node2->next->prev = node1;

        Node *tempPrev = node1->prev;
        Node *tempNext = node1->next;
        node1->prev = node2->prev;
        node1->next = node2->next;
        node2->prev = tempPrev;
        node2->next = tempNext;

        if (node1->next == node2)
        {
            node2->prev = node1;
            node1->next = node2;
        }

        // Adjust head if needed
        if (head == node1)
            head = node2;
        else if (head == node2)
            head = node1;
    }
};

int main()
{
    int A[] = {1, 7, 4, 2, 6, 4, 5, 3, 9, 8};
    DoublyLinkedList dll(A, 10);
    cout << "Initial Linked List:" << endl;
    dll.display();

    int index1 = 3; 
    int index2 = 7;
    dll.swapNodes(index1, index2);

    cout << "After Swapping Nodes at Indexes " << index1 << " and " << index2 << ":" << endl;
    dll.display();

    return 0;
}
