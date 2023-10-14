#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
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

int getLen(Node *head)
{
    int count = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void insertAtHead(Node *&head, int d)
{
    Node *newNode = new Node(d);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertAtTail(Node *&head, int d)
{
    Node *newNode = new Node(d);
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

int main()
{
    Node *n1 = new Node(10);

    Node *head = n1;

    print(head);
    cout << "length = " << getLen(head) << endl;

    insertAtHead(head, 8);
    print(head);

    insertAtTail(head, 15);
    print(head);

    insertAtPos(head, 9, 2);
    print(head);
    insertAtPos(head, 11, 4);
    print(head);
    insertAtPos(head, 5, 1);
    print(head);
    insertAtPos(head, 17, 7);
    print(head);
    insertAtPos(head, 20, 8);
    print(head);

    return 0;
}