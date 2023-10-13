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

void insertAtPos(Node *&head, int pos, int d)
{
    if (pos == 1)
    {
        insertAtHead(head, d);
        return;
    }

    Node *newNode = new Node(d);
    Node *prev = head;
    Node *n = prev->next;
    for (int i = 0; i < pos - 2; i++)
    {
        prev = prev->next;
        n = n->next;
    }
    prev->next = newNode;
    newNode->next = n;
}

int main()
{
    Node *n1 = new Node(10); // dynamic allocation-creating a Node in the heap
    // cout << n1->data << endl;
    // cout << n1->next << endl;

    Node *head = n1;
    Node *tail = n1;

    print(head);
    insertAtHead(head, 5);
    print(head);
    insertAtHead(head, 2);
    print(head);

    insertAtTail(tail, 15);
    print(head);
    insertAtTail(tail, 17);
    print(head);

    insertAtPos(head, 3, 9);
    print(head);
    insertAtPos(head, 1, 1);
    print(head);
    insertAtPos(head, 6, 12);
    print(head);
    insertAtPos(head, 9, 19);
    print(head);
    insertAtPos(head, 10, 20);
    print(head);
}