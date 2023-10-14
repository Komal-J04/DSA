#include <iostream>
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

void insertAtHead(Node *&head, int d) //* because it is a pointer and & because we want to make changes in the original LL, not its copy
{
    Node *newNode = new Node(d); // if we do static allocation, newNode will be live only within the scope of this function
    newNode->next = head;
    head = newNode;
}

void insertAtTail(Node *&tail, int d)
{
    Node *newNode = new Node(d);
    tail->next = newNode;
    tail = newNode;
}

void insertAtPos(Node *&head, Node *&tail, int pos, int d)
{
    if (pos == 1)
    {
        insertAtHead(head, d);
        return;
    }
    Node *newNode = new Node(d);

    Node *temp = head;
    for (int i = 0; i < pos - 2; i++)
    {
        temp = temp->next;
    }

    // if (temp->next == NULL) //this or the below 'if' condition
    // {
    //     insertAtTail(tail, d);
    //     return;
    // }

    newNode->next = temp->next;
    temp->next = newNode;

    if (newNode->next == NULL) // update the tail when inserting at last
    {
        tail = newNode;
    }
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
    Node *curr = head;
    while (temp->next->next != NULL)
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

int main()
{
    Node *n1 = new Node(10); // dynamic allocation-creating a Node in the heap and n1 points to it

    Node *head = n1;
    Node *tail = n1;
    cout << head->data;

    print(head);
    insertAtHead(head, 5);
    print(head);
    insertAtHead(head, 4);
    print(head);

    insertAtTail(tail, 15);
    print(head);
    insertAtTail(tail, 17);
    print(head);

    insertAtPos(head, tail, 3, 9);
    print(head);
    insertAtPos(head, tail, 1, 1);
    print(head);
    insertAtPos(head, tail, 8, 19);
    print(head);
    insertAtPos(head, tail, 9, 20);
    print(head);
    insertAtPos(head, tail, 2, 3);
    print(head);

    insertAtTail(tail, 21);
    print(head);

    deleteHead(head);
    print(head);

    deleteTail(head, tail);
    print(head);

    deleteAtPos(head, tail, 3);
    print(head);
    deleteAtPos(head, tail, 1);
    print(head);
    deleteAtPos(head, tail, 7);
    print(head);

    insertAtTail(tail, 20);
    print(head);

    deleteElt(head, tail, 15);
    print(head);
    deleteElt(head, tail, 4);
    print(head);
    deleteElt(head, tail, 20);
    print(head);
}