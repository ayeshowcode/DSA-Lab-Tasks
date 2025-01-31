#include <iostream>
using namespace std;

// Node structure for the linked list in hash table
struct Node
{
    char key;   // Character stored (nut or bolt)
    Node *next; // Pointer to the next node

    Node(char k) : key(k), next(NULL) {}
};

// Hash Table class with chaining
class HashTable
{
    int BUCKET;   // Number of buckets
    Node **table; // Array of pointers to linked lists

public:
    // Constructor to initialize the hash table
    HashTable(int b)
    {
        BUCKET = b;
        table = new Node *[BUCKET];
        for (int i = 0; i < BUCKET; i++)
        {
            table[i] = NULL; // Initialize all buckets as empty
        }
    }

    // Hash function to compute bucket index
    int hashFunction(char key)
    {
        return (key % BUCKET); // Simple hash based on ASCII value
    }

    // Insert a key into the hash table
    void insert(char key)
    {
        int index = hashFunction(key);
        Node *newNode = new Node(key);

        // Insert new node at the beginning of the linked list
        newNode->next = table[index];
        table[index] = newNode;
    }

    // Search for a key in the hash table
    bool search(char key)
    {
        int index = hashFunction(key);
        Node *current = table[index];

        // Traverse the linked list at the given bucket
        while (current != NULL)
        {
            if (current->key == key)
            {
                return true; // Key found
            }
            current = current->next;
        }
        return false; // Key not found
    }
};

// Function to match and sort nuts and bolts
void matchNutsAndBolts(char nuts[], char bolts[], int n, const char *order)
{
    int BUCKET = 128; // Large enough bucket size for all ASCII characters

    // Create hash tables for nuts and bolts
    HashTable nutsTable(BUCKET);
    HashTable boltsTable(BUCKET);

    // Insert all nuts and bolts into their respective hash tables
    for (int i = 0; i < n; i++)
    {
        nutsTable.insert(nuts[i]);
        boltsTable.insert(bolts[i]);
    }

    // Sort nuts and bolts based on the predefined order
    int index = 0;
    for (int i = 0; order[i] != '\0'; i++)
    {
        char c = order[i];
        if (nutsTable.search(c) && boltsTable.search(c))
        {
            nuts[index] = c;
            bolts[index] = c;
            index++;
        }
    }
}

// Utility function to print an array
void printArray(char arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    // Input: Nuts and Bolts (unordered)
    int N = 5;
    char nuts[] = {'@', '%', '$', '#', '^'};
    char bolts[] = {'%', '@', '#', '$', '^'};

    // Define the custom order
    const char order[] = "#$%&*@^~";

    // Match and sort nuts and bolts
    matchNutsAndBolts(nuts, bolts, N, order);

    // Output the matched pairs
    printArray(nuts, N);
    printArray(bolts, N);

    return 0;
}