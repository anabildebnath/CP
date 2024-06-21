#include <iostream>
#include <queue>
#include <list>
using namespace std;

// Definition of a tree
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};


// Building a tree
class BinaryTree
{
private:
    static int i;

public:
    static Node *buildTree(int nodes[])
    {
        i++;
        if (nodes[i] == -1)
        {
            return nullptr;
        }
        Node *newNode = new Node(nodes[i]);
        newNode->left = buildTree(nodes);
        newNode->right = buildTree(nodes);
        return newNode;
    }
};

// Preorder traversal
void preorder(Node *root)
{
    if (root == NULL)
    {
        cout << -1 << " ";
    }
    else
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Inorder traversal
void inorder(Node *root)
{
    if (root == NULL)
    {
        cout << -1 << " ";
    }
    preorder(root->left);
    cout << root->data << " ";
    preorder(root->right);
}

// Postorder traversal
void postorder(Node *root)
{
    if (root == NULL)
    {
        cout << -1 << " ";
    }

    preorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Post-order traversal for deleting the tree
void postorderDelete(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorderDelete(root->left);
    postorderDelete(root->right);
    delete root;
}

// Level order traversal
void levelOrderTraversal(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();

        if (current == nullptr)
        {
            cout << endl;

            if (q.empty())
            {
                break;
            }
            else
            {
                q.push(nullptr);
            }
        }
        else
        {
            cout << current->data << " ";
            if (current->left != nullptr)
            {
                q.push(current->left);
            }
            if (current->right != nullptr)
            {
                q.push(current->right);
            }
        }
    }
}

// Height of a tree
int height(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}

// Count of nodes
int count(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int leftCount = count(root->left);
    int rightCount = count(root->right);
    return leftCount + rightCount + 1;
}
// Sum of all nodes
int sum(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int leftSum = sum(root->left);
    int rightSum = sum(root->right);
    return leftSum + rightSum + root->data;
}

// Diameter approach 1
int diameter1(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int leftDiameter = diameter1(root->left);
    int rightDiameter = diameter1(root->right);
    int rootDiameter = height(root->left) + height(root->right) + 1;

    return max(rootDiameter, max(leftDiameter, rightDiameter));
}

// Diameter approach 2
class TreeInfo
{
public:
    int height;
    int diameter;

    TreeInfo(int height, int diameter)
    {
        this->height = height;
        this->diameter = diameter;
    }
};
TreeInfo diameter2(Node *root)
{
    if (root == nullptr)
    {
        return TreeInfo(0, 0);
    }
    TreeInfo leftTreeInfo = diameter2(root->left);
    TreeInfo rightTreeInfo = diameter2(root->right);
    int realHeight = max(leftTreeInfo.height, rightTreeInfo.height) + 1;
    int height = leftTreeInfo.height + rightTreeInfo.height + 1;
    int leftDiameter = leftTreeInfo.diameter;
    int rightDiameter = rightTreeInfo.diameter;
    int realDiameter = max(height, max(leftDiameter, rightDiameter));
    return TreeInfo(realHeight, realDiameter);
}

// Subtree of another tree
bool isIdentical(Node *root, Node *subroot)
{
    if (root == nullptr && subroot == nullptr)
    {
        return true;
    }
    if (root == nullptr || subroot == nullptr)
    {
        return false;
    }
    if (root->data == subroot->data)
    {
        return isIdentical(root->right, subroot->right) && isIdentical(root->left, subroot->left);
    }
    return false;
}
bool isSubtree(Node *root, Node *subroot)
{
    if (subroot == nullptr)
    {
        return true;
    }
    if (root == nullptr)
    {
        return false;
    }

    if (isIdentical(root, subroot))
    {
        return true;
    }

    return isSubtree(root->left, subroot) || isSubtree(root->right, subroot);
}
int BinaryTree::i = -1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int nodes[] = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = BinaryTree::buildTree(nodes);
    cout << root->data << endl;
    levelOrderTraversal(root);
    cout << height(root) << endl;
    cout << count(root) << endl;
    cout << sum(root) << endl;
    cout << diameter1(root) << endl;
    cout << diameter2(root).diameter << endl;

    return 0;
}
