#include <iostream>
using namespace std;

// Node to represent each entry in the hash table
struct Node
{
    int key;
    int index; // Store index for two-sum logic
    Node *next;

    Node(int key, int index) : key(key), index(index), next(NULL) {}
};

class Hash
{
    int BUCKET;
    int numOfElements;
    Node **table;

public:
    Hash(int b)
    {
        BUCKET = b;
        numOfElements = 0;
        table = new Node *[BUCKET];
        for (int i = 0; i < BUCKET; i++)
        {
            table[i] = NULL;
        }
    }

    int hashFunction(int x)
    {
        return x % BUCKET;
    }

    float getLoadFactor()
    {
        return (float)numOfElements / BUCKET;
    }

    void insertItem(int key, int index)
    {
        // Rehash if load factor exceeds 0.5
        while (getLoadFactor() > 0.5)
        {
            rehashing();
        }

        int hashIndex = hashFunction(key);

        // Create a new node for the key
        Node *newNode = new Node(key, index);

        // Insert the new node at the head of the chain
        newNode->next = table[hashIndex];
        table[hashIndex] = newNode;

        numOfElements++;
    }

    void deleteItem(int key)
    {
        int index = hashFunction(key);
        Node *current = table[index];
        Node *prev = NULL;

        // Traverse the chain to find the key
        while (current != NULL && current->key != key)
        {
            prev = current;
            current = current->next;
        }

        // Key not found
        if (current == NULL)
        {
            return;
        }

        // Key found, remove the node
        if (prev == NULL)
        {
            // Key is at the head of the chain
            table[index] = current->next;
        }
        else
        {
            // Key is in the middle or end of the chain
            prev->next = current->next;
        }

        delete current;
        numOfElements--;
    }

    void displayHash()
    {
        for (int i = 0; i < BUCKET; i++)
        {
            cout << i;
            Node *current = table[i];
            while (current != NULL)
            {
                cout << " --> " << current->key << " (Index: " << current->index << ")";
                current = current->next;
            }
            cout << endl;
        }
    }

    void rehashing()
    {
        int oldBucket = BUCKET;
        BUCKET = 2 * BUCKET; // Double the number of buckets

        Node **oldTable = table;

        table = new Node *[BUCKET];
        for (int i = 0; i < BUCKET; i++)
        {
            table[i] = NULL;
        }
        numOfElements = 0; // Reset the elements count

        // Reinsert all keys from the old table into the new table
        for (int i = 0; i < oldBucket; i++)
        {
            Node *current = oldTable[i];
            while (current != NULL)
            {
                insertItem(current->key, current->index);
                Node *temp = current;
                current = current->next;
                delete temp;
            }
        }
    }

    Node *searchItem(int key)
    {
        int index = hashFunction(key);
        Node *current = table[index];

        while (current != NULL)
        {
            if (current->key == key)
            {
                return current; // Return the node if key is found
            }
            current = current->next;
        }
        return NULL;
    }

    // Two-sum implementation using the hash table
    bool twoSum(int start, int n, int k, int *arr)
    {
        // Clear the hash table for each call
        for (int i = 0; i < BUCKET; i++)
        {
            Node *current = table[i];
            while (current != NULL)
            {
                Node *temp = current;
                current = current->next;
                delete temp;
            }
            table[i] = NULL;
        }
        numOfElements = 0; // Reset the count

        // Insert the first element into the hash table
        insertItem(arr[start], start);

        for (int i = start + 1; i < n; i++)
        {
            int diff = k - arr[i];

            // Check if the complement exists in the hash table
            Node *complementNode = searchItem(diff);
            if (complementNode != NULL)
            {
                cout << "Pair found: (" << arr[i] << ", " << diff << ")" << endl;
                return true; // Pair found
            }

            // Insert the current element into the hash table if not already present
            if (searchItem(arr[i]) == NULL)
                insertItem(arr[i], i);
        }

        return false;
    }

    // Three-sum implementation
    bool threeSum(int n, int *arr)
    {
        for (int i = 0; i < n - 2; i++)
        {
            int target = -arr[i];
            cout << "Checking for target: " << target << " with element " << arr[i] << endl;
            if (twoSum(i + 1, n, target, arr))
            {
                cout << "Triplet found with first element: " << arr[i] << endl;
                return true;
            }
        }
        return false;
    }
};

int main()
{
    int bucketSize;
    cout << "Enter the initial number of buckets: ";
    cin >> bucketSize;

    // Create a hash table with the given bucket size
    Hash hashTable(bucketSize);

    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int *arr = new int[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Call the threeSum method
    if (hashTable.threeSum(n, arr))
    {
        cout << "Triplet exists!" << endl;
    }
    else
    {
        cout << "No triplet found." << endl;
    }

    delete[] arr;
    return 0;
}