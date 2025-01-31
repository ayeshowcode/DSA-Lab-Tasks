#include <iostream>
#include <vector>
using namespace std;

// Definition of a BST node
class Node
{
public:
    int key;
    Node *left, *right;

    Node(int item) : key(item), left(NULL), right(NULL) {}
};

// Inorder traversal to store nodes of a BST in a sorted vector
void inorder(Node *root, vector<int> &vec)
{
    if (root == NULL)
        return;
    inorder(root->left, vec);
    vec.push_back(root->key);
    inorder(root->right, vec);
}

// Merge two sorted arrays into one sorted array
vector<int> mergeArrays(vector<int> &arr1, vector<int> &arr2)
{
    vector<int> merged;
    int i = 0, j = 0;

    // Traverse both arrays and merge them
    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] <= arr2[j])
        {
            merged.push_back(arr1[i]);
            i++;
        }
        else
        {
            merged.push_back(arr2[j]);
            j++;
        }
    }

    // Add remaining elements of arr1 (if any)
    while (i < arr1.size())
    {
        merged.push_back(arr1[i]);
        i++;
    }

    // Add remaining elements of arr2 (if any)
    while (j < arr2.size())
    {
        merged.push_back(arr2[j]);
        j++;
    }

    return merged;
}

// Function to convert the sorted array into a balanced BST
Node *sortedArrayToBST(vector<int> &arr, int start, int end)
{
    if (start > end)
        return NULL;

    // Middle element becomes the root
    int mid = (start + end) / 2;
    Node *root = new Node(arr[mid]);

    // Recursively construct the left subtree and right subtree
    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);

    return root;
}

// Function to merge two BSTs
Node *mergeBSTs(Node *root1, Node *root2)
{
    // Step 1: Store inorder traversal of both trees in sorted arrays
    vector<int> bst1, bst2;
    inorder(root1, bst1);
    inorder(root2, bst2);

    // Step 2: Merge the two sorted arrays
    vector<int> mergedArray = mergeArrays(bst1, bst2);

    // Step 3: Convert the merged sorted array into a balanced BST
    return sortedArrayToBST(mergedArray, 0, mergedArray.size() - 1);
}

// Inorder traversal to print the BST
void printInorder(Node *root)
{
    if (root == NULL)
        return;
    printInorder(root->left);
    cout << root->key << " ";
    printInorder(root->right);
}

// Helper function to insert nodes into a BST
Node *insert(Node *root, int key)
{
    if (root == NULL)
        return new Node(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
}

int main()
{
    // Constructing first BST
    Node *root1 = NULL;
    root1 = insert(root1, 3);
    root1 = insert(root1, 1);
    root1 = insert(root1, 2);
    root1 = insert(root1, 6);

    // Constructing second BST
    Node *root2 = NULL;
    root2 = insert(root2, 5);
    root2 = insert(root2, 2);
    root2 = insert(root2, 3);
    root2 = insert(root2, 7);
    root2 = insert(root2, 4);

    // Merging the two BSTs
    Node *mergedRoot = mergeBSTs(root1, root2);

    // Print the merged BST (inorder traversal)
    cout << "Inorder traversal of the merged BST: ";
    printInorder(mergedRoot);
    cout << endl;

    return 0;
}