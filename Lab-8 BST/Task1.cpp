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

int main()
{
    // Insert nodes directly
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
    return 0;
}

