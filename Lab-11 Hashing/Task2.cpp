#include <iostream>
using namespace std;

// Node structure for the linked list in each bucket
struct Node
{
    int key;    // The value stored in the node
    Node *next; // Pointer to the next node

    Node(int k) : key(k), next(NULL) {}
};

// Hash table class with chaining
class HashTable
{
    int BUCKET;   // Number of buckets in the hash table
    Node **table; // Array of pointers to linked lists for chaining

public:
    // Constructor to initialize the hash table
    HashTable(int b)
    {
        BUCKET = b;
        table = new Node *[BUCKET];
        for (int i = 0; i < BUCKET; i++)
        {
            table[i] = NULL; // Initialize each bucket as empty
        }
    }

    // Hash function to compute the index
    int hashFunction(int x)
    {
        return abs(x) % BUCKET; // Ensure non-negative index
    }

    // Insert a key into the hash table
    void insert(int key)
    {
        int index = hashFunction(key);
        Node *newNode = new Node(key);

        // Insert the new node at the beginning of the linked list
        newNode->next = table[index];
        table[index] = newNode;
    }

    // Search for a key in the hash table
    int search(int key)
    {
        int index = hashFunction(key);
        Node *current = table[index];
        int count = 0;

        // Traverse the linked list at the given index to find the key
        while (current != NULL)
        {
            if (current->key == key)
            {
                count++; // Increment count if the key matches
            }
            current = current->next;
        }
        return count;
    }

    // Delete the hash table to free memory
    ~HashTable()
    {
        for (int i = 0; i < BUCKET; i++)
        {
            Node *current = table[i];
            while (current != NULL)
            {
                Node *temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }
};

// Function to count the pairs with sum K using chaining
int countPairsWithSum(int arr[], int n, int k)
{
    // Create a hash table with a suitable number of buckets
    HashTable hashTable(n);

    int count = 0;

    // Traverse the array
    for (int i = 0; i < n; i++)
    {
        // Find the complement
        int complement = k - arr[i];

        // Check if the complement exists in the hash table
        count += hashTable.search(complement);

        // Insert the current element into the hash table
        hashTable.insert(arr[i]);
    }

    return count;
}

int main()
{
    // Input: Array and target sum
    int N = 4, K = 6;
    int arr[] = {1, 5, 7, 1};

    // Find the number of pairs with sum K
    int result = countPairsWithSum(arr, N, K);

    // Output the result
    cout << "Number of pairs with sum " << K << ": " << result << endl;

    return 0;
}