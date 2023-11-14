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

void push(Node *&head, int d)
{
    Node *newNode = new Node(d);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

int pop(Node *&head)
{
    if (head->next == NULL)
    {
        cout << "Empty stack" << endl;
    }
    Node *temp = head;
    Node *curr = temp->next;
    while (curr->next != NULL)
    {
        temp = temp->next;
        curr = curr->next;
    }
    int elt = curr->data;
    temp->next = NULL;
    curr->next = NULL;
    delete curr;
    return elt;
}

bool empty(Node *head)
{
    if (head->next == NULL)
        return true;
    return false;
}

int peek(Node *head)
{
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    return temp->data;
}

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

int main()
{
    Node *head = new Node(-1);

    push(head, 20);
    push(head, 30);
    push(head, 40);
    push(head, 50);

    print(head);

    cout << peek(head) << endl;
    cout << pop(head) << endl;
    print(head);
    pop(head);
    pop(head);
    pop(head);
    cout << peek(head) << endl;
    cout << empty(head) << endl;

    return 0;
}