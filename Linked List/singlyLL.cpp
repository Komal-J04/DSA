#include <iostream>
#include <map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node *head)
{
    Node *temp = head;
    cout << "Current state of the linked list - ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtHead(Node *&head, Node *&tail, int d) //* because it is a pointer and & because we want to make changes in the original LL, not its copy
{
    Node *newNode = new Node(d); // if we do static allocation, newNode will be live only within the scope of this function

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    newNode->next = head;
    head = newNode;
}

void insertAtTail(Node *&head, Node *&tail, int d)
{
    Node *newNode = new Node(d);

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}

void insertAtPos(Node *&head, Node *&tail, int pos, int d)
{
    if (pos == 1)
    {
        insertAtHead(head, tail, d);
        return;
    }
    Node *newNode = new Node(d);

    Node *temp = head;
    for (int i = 0; i < pos - 2; i++)
    {
        temp = temp->next;
    }

    if (temp->next == NULL) // this or the below 'if' condition
    {
        insertAtTail(head, tail, d);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    // if (newNode->next == NULL) // update the tail when inserting at last
    // {
    //     tail = newNode;
    // }
}

void deleteHead(Node *&head)
{
    Node *temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
}

void deleteTail(Node *&head, Node *&tail)
{
    Node *temp = head;
    Node *curr = temp->next;
    while (curr->next != NULL)
    {
        temp = temp->next;
        curr = curr->next;
    }
    temp->next = NULL;
    tail = temp;
    curr->next = NULL;
    delete curr;
}

void deleteAtPos(Node *&head, Node *&tail, int pos)
{
    if (pos == 1)
    {
        deleteHead(head);
        return;
    }

    Node *prev = head;
    Node *n = prev->next;
    for (int i = 0; i < pos - 2; i++)
    {
        prev = prev->next;
        n = n->next;
    }
    prev->next = n->next;
    if (prev->next == NULL)
        tail = prev;
    n->next = NULL;
    delete n;
}

void deleteElt(Node *&head, Node *&tail, int d)
{
    if (head->data == d)
    {
        head = head->next;
        return;
    }
    Node *prev = head;
    Node *n = prev->next;
    while (n->data != d)
    {
        prev = prev->next;
        n = n->next;
    }
    prev->next = n->next;
    if (prev->next == NULL)
        tail = prev;
    n->next = NULL;
    delete n;
}

// using map
void detectLoop(Node *head)
{
    if (head == NULL)
    {
        cout << "No loop" << endl;
        return;
    }

    map<Node *, bool> map;
    map[head] = true;

    Node *curr = head->next;

    while (curr != NULL && map[curr] != true)
    {
        map[curr] = true;
        curr = curr->next;
    }
    if (curr == NULL)
        cout << "No loop" << endl;
    if (map[curr])
    {
        cout << "Loop starts on node with value " << curr->data << endl;
    }
}

// Floyd's cycle detection algorithm
bool floyd(Node *head)
{
    if (head == NULL)
        return false;

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

        // both the pointer are initially equal(head), so if we check for this condition before incrementing them we will get true only
        if (slow == fast)
            return true;
    }

    if (fast == NULL)
        return false;
}

// start of a loop using Floyd's algo
Node *startNode(Node *head)
{
    if (head == NULL)
        return head;

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
        {
            slow = head;
            break;
        }
    }

    while (slow != fast)
    {
        fast = fast->next;
        slow = slow->next;
    }

    return slow;
}

int main()
{
    Node *n1 = new Node(10); // dynamic allocation-creating a Node in the heap and n1 points to it

    Node *head = NULL;
    Node *tail = NULL;
    // cout << head->data;

    // print(head);
    insertAtHead(head, tail, 5);
    print(head);
    insertAtHead(head, tail, 4);
    print(head);

    insertAtTail(head, tail, 15);
    print(head);
    insertAtTail(head, tail, 17);
    print(head);

    insertAtPos(head, tail, 3, 9);
    print(head);
    insertAtPos(head, tail, 1, 1);
    print(head);
    insertAtPos(head, tail, 7, 19);
    print(head);
    insertAtPos(head, tail, 8, 20);
    print(head);
    insertAtPos(head, tail, 2, 3);
    print(head);

    insertAtTail(head, tail, 21);
    print(head);

    deleteHead(head);
    print(head);

    deleteTail(head, tail);
    print(head);

    deleteAtPos(head, tail, 3);
    print(head);
    deleteAtPos(head, tail, 1);
    print(head);
    deleteAtPos(head, tail, 6);
    print(head);

    insertAtTail(head, tail, 20);
    print(head);

    deleteElt(head, tail, 15);
    print(head);
    deleteElt(head, tail, 4);
    print(head);
    deleteElt(head, tail, 20);
    print(head);

    tail->next = head->next;
    detectLoop(head);

    if (floyd(head))
        cout << "Loop detected" << endl;
    else
        cout << "No loop" << endl;

    Node *loopStartNode = startNode(head);
    cout << "The loop starts at the node with data " << loopStartNode->data << endl;
}