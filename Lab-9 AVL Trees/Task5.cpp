#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
    int height;

    Node(int k)
    {
        key = k;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

int height(Node *N)
{
    if (N == nullptr)
        return 0;
    return N->height;
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(height(y->left),
                        height(y->right));
    x->height = 1 + max(height(x->left),
                        height(x->right));

    return x;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(height(x->left),
                        height(x->right));
    y->height = 1 + max(height(y->left),
                        height(y->right));

    return y;
}

int getBalance(Node *N)
{
    if (N == nullptr)
        return 0;
    return height(N->left) - height(N->right);
}

Node *insert(Node *node, int key)
{
    if (node == nullptr)
        return new Node(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left),
                           height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void preOrder(Node *root)
{
    if (root != nullptr)
    {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inorder(Node *root)
{
    if (root != nullptr)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

void postOrder(Node *root)
{
    if (root != nullptr)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->key << " ";
    }
}

Node *minValueNode(Node *node)
{
    Node *current = node;

    while (current->left != nullptr)
        current = current->left;

    return current;
}

Node *deleteNode(Node *root, int key)
{
    if (root == nullptr)
        return root;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
        if ((root->left == nullptr) ||
            (root->right == nullptr))
        {
            Node *temp = root->left ? root->left : root->right;

            if (temp == nullptr)
            {
                temp = root;
                root = nullptr;
            }
            else
                *root = *temp;
            free(temp);
        }
        else
        {
            Node *temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == nullptr)
        return root;

    root->height = 1 + max(height(root->left),
                           height(root->right));

    int balance = getBalance(root);

    if (balance > 1 &&
        getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 &&
        getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 &&
        getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 &&
        getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

Node *search(Node *root, int key)
{
    if (root == nullptr || root->key == key)
        return root;

    if (key < root->key)
        return search(root->left, key);

    return search(root->right, key);
}

void findKthSmallest(Node *root, int &k, Node *&result)
{
    if (root == nullptr || result != nullptr)
        return;

    findKthSmallest(root->left, k, result);

    k--;
    if (k == 0)
    {
        result = root;
        return;
    }

    findKthSmallest(root->right, k, result);
}

void findKthLargest(Node *root, int &k, Node *&result)
{
    if (root == nullptr || result != nullptr)
        return;

    findKthLargest(root->right, k, result);

    k--;
    if (k == 0)
    {
        result = root;
        return;
    }

    findKthLargest(root->left, k, result);
}

void printSubtreeHeights(Node *root)
{
    if (root == nullptr)
    {
        cout << "Tree is empty." << endl;
        return;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    cout << "Left subtree height from root: " << leftHeight << endl;
    cout << "Right subtree height from root: " << rightHeight << endl;
}

int main()
{
    Node *root = nullptr;

    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 7);

    int kSmallest = 3;
    Node *kthSmallestNode = nullptr;
    findKthSmallest(root, kSmallest, kthSmallestNode);
    if (kthSmallestNode != nullptr)
        cout << "The " << 3 << "rd smallest element is: " << kthSmallestNode->key << endl;
    else
        cout << kSmallest << "rd smallest element not found." << endl;

    int kLargest = 3;
    Node *kthLargestNode = nullptr;
    findKthLargest(root, kLargest, kthLargestNode);
    if (kthLargestNode != nullptr)
        cout << "The " << 3 << "rd largest element is: " << kthLargestNode->key << endl;
    else
        cout << kLargest << "rd largest element not found." << endl;

    printSubtreeHeights(root);

    return 0;
}