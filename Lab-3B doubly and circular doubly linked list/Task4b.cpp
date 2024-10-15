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
    // Constructor to create a doubly linked list from an array
    DoublyLinkedList() : head(nullptr) {}
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
        Node *p = head;
        while (p != NULL)
        {
            cout << p->data << ", ";
            p = p->next;
        }
        cout << endl;
    }

    int length()
    {
        Node *p = head;
        int len = 0;
        while (p != NULL)
        {
            len++;
            p = p->next;
        }
        return len;
    }

    void extractAndAppendAlternate()
    {
        if (head == NULL || head->next == NULL)
            return;

        Node *current = head->next; 
        Node *newHead = NULL;
        Node *last = NULL;

        while (current != NULL)
        {
            if (newHead == NULL)
            {
                newHead = new Node(current->data);
                last = newHead;
            }
            else
            {
                Node *temp = new Node(current->data);
                last->next = temp;
                temp->prev = last;
                last = temp;
            }

            current = current->next;
            if (current != NULL)
                current = current->next;
        }

        // Reverse the extracted list
        Node *prev = NULL;
        Node *curr = newHead;
        Node *next = NULL;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            curr->prev = next;
            prev = curr;
            curr = next;
        }
        newHead = prev;

        // Append the reversed list at the end of the original list
        if (head == NULL)
        {
            head = newHead;
        }
        else
        {
            Node *lastOriginal = head;
            while (lastOriginal->next != NULL)
                lastOriginal = lastOriginal->next;

            lastOriginal->next = newHead;
            if (newHead != NULL)
                newHead->prev = lastOriginal;
        }
    }
};

int main()
{
    int A[] = {10, 20, 30, 40, 50};
    DoublyLinkedList dll1(A, 5);
    cout << "Original list 1: " << endl;
    dll1.display();

    dll1.extractAndAppendAlternate();

    cout << "Modified list 1 after appending reversed alternate nodes: " << endl;
    dll1.display();
    return 0;
}
