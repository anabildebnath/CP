#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int value)
    {
        data = value;
        next = NULL;
    }
};

// Insert at tail
void insertAtTail(node *&head, int value)
{
    node *n = new node(value);
    node *i = head;
    if (head == NULL)
    {
        head = n;
        return;
    }
    while (i->next != NULL)
    {
        i = i->next;
    }
    i->next = n;
}

// Insert at head
void insertAtHead(node *&head, int value)
{

    node *n = new node(value);
    if (head == NULL)
    {
        head = n;
        return;
    }
    n->next = head;
    head = n;
}

// Insert at middle
// void insertAtMiddle(node *&head,int value, int key)
// {
//     node *n = new node(value);
//     while()
// }

// Search a key
bool search(node *&head, int key)
{
    node *i = head;
    while (i != NULL)
    {
        if (i->data == key)
        {
            return true;
        }
        i = i->next;
    }
    return false;
}

// Delete from head
void deleteKeyAtHead(node *&head)
{
    node *deletedKey = head;
    head = head->next;

    delete deletedKey; // otherwise memory leak
}

// Delete a key
void deleteKey(node *&head, int key)
{

    if (head == NULL)
    {
        return;
    }
    if (head->next == NULL)
    {
        deleteKeyAtHead(head);
        return;
    }
    node *i = head;
    while (i->next->data != key)
    {
        i = i->next;
    }
    i->next = i->next->next;
}

// Reverse a linked list using three pointers
void reverse(node *&head)
{
    node *prev = NULL;
    node *current = head;
    node *next;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

// Reverse a linked list via recursion
node *reverseRecursion(node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *newHead = reverseRecursion(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}

// Make a cycle at a given position
void makeCycle(node *&head, int pos)
{
    int count = 1;
    node *temp = head;
    node *startHead;
    while (temp->next != NULL)
    {
        if (count == pos)
        {
            startHead = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startHead;
}

// Detect a cycle
bool detectCycle(node *&head)
{
    node *slow = head;
    node *fast = head;
    while (fast->next != NULL && fast != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

// Remove a cycle
void removeCycle(node *&head)
{
    node *slow = head;
    node *fast = head;
    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    fast = head;
    while (fast->next != slow->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = NULL;
}

void print(node *head) //*&head
{
    node *i = head;
    while (i != NULL)
    {
        cout << i->data << " ";
        i = i->next;
    }
    cout << endl;
}

int main()
{
    node *head = NULL;

    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 4);
    insertAtHead(head, 5);
    insertAtHead(head, 6);
    insertAtHead(head, 7);
    print(head);

    makeCycle(head, 3);
    removeCycle(head);
    if (detectCycle(head))
    {
        cout << "Cycle exists" << endl;
    }
    else
    {
        cout << "No cycle" << endl;
    }

    // if (search(head, 2))
    // {
    //     cout << "Exists" << endl;
    // }
    // else
    // {
    //     cout << "Nai" << endl;
    // }
    // node *newHead = reverseRecursion(head);

    // print(newHead);
}