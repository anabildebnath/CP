#include <iostream>
#include <queue>
#include <list>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
    }
};

Node *insertNode(Node *root, int val)
{
    if (root == nullptr)
    {
        root = new Node(val);
        return root;
    }

    if (root->data > val)
    {
        root->left = insertNode(root->left, val);
    }
    else
    {
        root->right = insertNode(root->right, val);
    }

    return root;
}

void inorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Search a key
bool search(Node *root, int key)
{
    if (root == nullptr)
    {
        return false;
    }
    if (root->data > key)
    {
        return search(root->left, key);
    }
    else if (root->data < key)
    {
        return search(root->right, key);
    }
    else
    {
        return true;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int values[] = {5, 1, 3, 4, 2, 7};
    Node *root = nullptr;
    for (int i = 0; i < sizeof(values) / sizeof(values[0]); i++)
    {
        root = insertNode(root, values[i]);
    }
    inorder(root);
    cout <<endl;
    if (search(root, 1))
    {
        cout << "exists" << endl;
    }
    else
    {
        cout << "doesn't exist" << endl;
    }

    return 0;
}
