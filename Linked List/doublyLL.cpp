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

void deleteNode(Node *&head, int pos)
{
    if (pos == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *temp = head;
        Node *curr = temp->next;
        for (int i = 0; i < pos - 2; i++)
        {
            temp = curr;
            curr = curr->next;
        }
        temp->next = curr->next;
        if (temp->next == NULL)
        {
            curr->prev = NULL;
            delete curr;
            return;
        }
        curr->next->prev = temp;
        curr->prev = NULL;
        curr->next = NULL;
        delete curr;
    }
}

int main()
{
    Node *head = NULL;

    print(head);
    cout << "length = " << getLen(head) << endl;

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
    cout << "head=" << head->data << endl;
    insertAtPos(head, 17, 6);
    print(head);
    insertAtPos(head, 20, 7);
    print(head);

    deleteNode(head, 3);
    print(head);
    deleteNode(head, 1);
    print(head);
    deleteNode(head, 5);
    print(head);

    return 0;
}