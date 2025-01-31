#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    Node *left, *right;

    Node(int item) : key(item), left(NULL), right(NULL) {}
};

// Insert a node into the binary search tree
Node *insert(Node *root, int x)
{
    Node *temp = new Node(x);

    // If tree is empty
    if (root == NULL)
        return temp;

    // Traverse to find the appropriate parent node for the new node
    Node *parent = NULL, *curr = root;
    while (curr != NULL)
    {
        parent = curr;
        if (curr->key > x)
            curr = curr->left;
        else if (curr->key < x)
            curr = curr->right;
        else
            return root; // Node already exists
    }

    // Place the new node as left or right child based on its value
    if (parent->key > x)
        parent->left = temp;
    else
        parent->right = temp;

    return root;
}

// Inorder traversal of the tree
void inorder(Node *node)
{
    if (node == NULL)
        return;
    inorder(node->left);
    cout << node->key << " ";
    inorder(node->right);
}

// Function to search if a node with a given key exists in the tree
bool ifNodeExists(Node *root, int key)
{
    if (root == NULL)
        return false;
    if (root->key == key)
        return true;

    return ifNodeExists(root->left, key) || ifNodeExists(root->right, key);
}

// Function to find the level of a node with a given key
int findLevel(Node *root, int key, int level = 0)
{
    if (root == NULL)
        return -1; // Key not found

    if (root->key == key)
        return level;

    int leftLevel = findLevel(root->left, key, level + 1);
    if (leftLevel != -1)
        return leftLevel;

    return findLevel(root->right, key, level + 1);
}

// Function to identify if the node is root, left child, or right child
void displayNodeLocation(Node *root, int key)
{
    if (root == NULL)
        return;

    if (root->key == key)
    {
        cout << "Node with key " << key << " is the Root node." << endl;
        return;
    }

    Node *parent = NULL, *curr = root;
    while (curr != NULL && curr->key != key)
    {
        parent = curr;
        if (curr->key > key)
            curr = curr->left;
        else
            curr = curr->right;
    }

    if (curr == NULL)
    {
        cout << "Node with key " << key << " not found in the tree." << endl;
        return;
    }

    int level = findLevel(root, key);
    if (parent->left == curr)
        cout << "Node with key " << key << " is at level " << level << " and is a left child." << endl;
    else if (parent->right == curr)
        cout << "Node with key " << key << " is at level " << level << " and is a right child." << endl;
}

int main()
{
    // Initial binary search tree
    Node *root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 7);

    cout << "Inorder traversal of the Binary Search Tree: " << endl;
    inorder(root);

    // Searching for a node and inserting if it doesn't exist
    int searchKey;
    cout << endl
         << "Enter the key to search: ";
    cin >> searchKey;

    if (ifNodeExists(root, searchKey))
        cout << "Node exists in the tree." << endl;
    else
    {
        cout << "Node does not exist. Inserting node..." << endl;
        root = insert(root, searchKey);
    }

    // Display the level and location (root, left or right child)
    displayNodeLocation(root, searchKey);
    cout << "Updated Inorder Traversal: ";
    inorder(root);
    cout << endl;

    return 0;
}
