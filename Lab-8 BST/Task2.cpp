#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    Node *left, *right;

    Node(int item) : key(item), left(NULL), right(NULL) {}
};
Node *insert(Node *root, int x)
{
    Node *temp = new Node(x);

    // If tree is empty
    if (root == NULL)
        return temp;

    // Find the node who is going to have the new node temp as it child. The parent node is mainly going to be a leaf node
    Node *parent = NULL, *curr = root;
    while (curr != NULL)
    {
        parent = curr;
        if (curr->key > x)
            curr = curr->left;
        else if (curr->key < x)
            curr = curr->right;
        else
            return root;
    }

    // If x is smaller, make it
    // left child, else right child
    if (parent->key > x)
        parent->left = temp;
    else
        parent->right = temp;
    return root;
}
Node *insertrec(Node *node, int key)
{
    // If the tree is empty, return a new node
    if (node == NULL)
        return new Node(key);

    // If the key is already present in the tree,
    // return the node
    if (node->key == key)
        return node;

    // Otherwise, recur down the tree/ If the key
    // to be inserted is greater than the node's key,
    // insert it in the right subtree
    if (node->key < key)
        node->right = insertrec(node->right, key);

    // If the key to be inserted is smaller than
    // the node's key,insert it in the left subtree
    else
        node->left = insertrec(node->left, key);

    // Return the (unchanged) node pointer
    return node;
}
void inorder(Node *node)
{
    if (node == NULL)
        return;
    inorder(node->left);
    cout << node->key << " ";
    inorder(node->right);
}
Node *minvalueNode(Node *node)
{
    Node *current = node;

    // Loop down to find the leftmost leaf
    while (current && current->left != NULL)
        current = current->left;

    return current;
}
Node *deleteNode(Node *root, int x)
{
    if (root == NULL)
        return root;
    if (x < root->key)
        root->left = deleteNode(root->left, x);
    else if (x > root->key)
        root->right = deleteNode(root->right, x);
    // means x==root->key
    else
    {
        // Node with only one left child or no child
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp; // return the right child
        }
        // Node with only one right child or no child
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp; // return the left child
        }
        // when both the children are present
        Node *temp = minvalueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
bool isFull(Node *root)
{
    if (root == NULL)
        return true;
    if (root->left == NULL && root->right == NULL)
        return true;
    if ((root->left) && (root->right))
        return (isFull(root->left) && isFull(root->right));
    return false;
}

// Recursive function to check if the tree is complete
bool isCompleteUtil(Node *root, int index, int totalNodes)
{
    // If we reach a NULL node, the tree is complete so far
    if (root == NULL)
        return true;

    // If index assigned to current node is greater than the total number of nodes, it’s not complete
    if (index >= totalNodes)
        return false;

    // Recur for left and right children with updated indices
    return isCompleteUtil(root->left, 2 * index + 1, totalNodes) &&
           isCompleteUtil(root->right, 2 * index + 2, totalNodes);
}
// Count nodes
int countNodes(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main()
{
    // Insert nodes directly
    Node *root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);

    cout << "Inorder traversal of the Binary Search Tree: " << endl;
    inorder(root);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 8);

    // Check if complete and delete nodes to make it full if necessary
    int totalNodes = countNodes(root);
    if (isCompleteUtil(root, 0, totalNodes))
    {
        cout << "The tree is complete." << endl;
    }
    else
    {
        cout << "The tree is not complete." << endl;
        deleteNode(root, 6);
        deleteNode(root, 7);
        deleteNode(root, 8);
    }
    inorder(root);

    if(isFull(root))
    {
        cout << "The tree is full." << endl;
    }
    else
    {
        cout << "The tree is not full." << endl;
    }
    return 0;
}