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
    if (root == NULL)
        return temp;

    Node *parent = NULL, *curr = root;
    while (curr != NULL)
    {
        parent = curr;
        if (curr->key > x)
            curr = curr->left;
        else if (curr->key < x)
            curr = curr->right;
        else
            return root; // Avoid duplicates
    }

    if (parent->key > x)
        parent->left = temp;
    else
        parent->right = temp;
    return root;
}

int findCeil(Node *root, int input)
{
    // Base case
    if (root == nullptr)
        return -1;

    // We found equal key
    if (root->key == input)
        return root->key;

    // If root's key is smaller,
    // ceil must be in the right subtree
    if (root->key < input)
        return findCeil(root->right, input);

    // Else, either left subtree or
    // root has the ceil value
    int ceil = findCeil(root->left, input);
    return (ceil >= input) ? ceil : root->key;
}

int findFloor(Node *root, int input)
{
    // Base case
    if (root == nullptr)
        return -1;

    // We found equal key
    if (root->key == input)
        return root->key;

    // If root's key is greater,
    // floor must be in the left subtree
    if (root->key > input)
        return findFloor(root->left, input);

    // Else, either right subtree or
    // root has the floor value
    int floor = findFloor(root->right, input);
    return (floor <= input) ? floor : root->key;
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

    int X;
    char choice;
    cout << "Enter a value for X: ";
    cin >> X;
    cout << "Do you want to ceil or floor the value? Enter 'c' for ceil and 'f' for floor: ";
    cin >> choice;

    if (choice == 'c')
    {
        X += 1; // For ceil, add 1
        int ceilValue = findCeil(root, X);
        if (ceilValue != -1)
            cout << "Ceil of " << X << " is: " << ceilValue << endl;
        else
            cout << "No ceil found for " << X << endl;
    }
    else if (choice == 'f')
    {
        X -= 1; // For floor, subtract 1
        int floorValue = findFloor(root, X);
        if (floorValue != -1)
            cout << "Floor of " << X << " is: " << floorValue << endl;
        else
            cout << "No floor found for " << X << endl;
    }
    else
    {
        cout << "Invalid choice. Exiting program.\n";
    }
    return 0;
}