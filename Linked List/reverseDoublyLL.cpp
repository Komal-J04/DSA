#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtHead(Node *&head, int d)
{
    Node *newNode = new Node(d);

    // empty list
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insertAtTail(Node *&head, int d)
{
    Node *newNode = new Node(d);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtPos(Node *&head, int d, int pos)
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

    if (temp->next == NULL)
    {
        insertAtTail(head, d);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (newNode->next == NULL)
    {
        temp->next = newNode;
        return;
    }
    temp->next->prev = newNode;
    temp->next = newNode;
}

void reverse(Node *&head)
{
    Node *temp = NULL;
    Node *current = head;

    /* swap next and prev for all nodes of
      doubly linked list */
    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    /* Before changing head, check for the cases like empty
       list and list with only one node */
    if (temp != NULL)
        head = temp->prev;
}

int main()
{
    Node *head = NULL;

    insertAtHead(head, 8);
    print(head);

    insertAtTail(head, 15);
    print(head);

    insertAtPos(head, 9, 2);
    print(head);
    insertAtPos(head, 11, 3);
    print(head);
    insertAtPos(head, 5, 1);
    print(head);
    insertAtPos(head, 17, 6);
    print(head);
    insertAtPos(head, 20, 7);
    print(head);

    reverse(head);
    print(head);

    return 0;
}