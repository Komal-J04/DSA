#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node *tail)
{
    Node *temp = tail->next;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail->next);
    cout << endl;
}

void insertion(Node *&tail, int d, int elt)
{
    Node *newNode = new Node(d);

    if (tail == NULL)
    {
        tail = newNode;
        newNode->next = newNode;
        return;
    }
    // inserting d right after elt
    Node *temp = tail->next;
    do
    {
        if (temp->data == elt)
        {
            newNode->next = temp->next;
            temp->next = newNode;
            if (temp == tail)
                tail = newNode;
        }
        temp = temp->next;
    } while (temp != tail->next);

    // inserting at the end if elt is not found
    if (newNode->next == NULL)
    {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
}

int main()
{
    Node *tail = NULL;
    insertion(tail, 5, 3);
    print(tail);
    insertion(tail, 10, 5);
    print(tail);
    insertion(tail, 6, 5);
    print(tail);
    insertion(tail, 15, 10);
    print(tail);
    insertion(tail, 17, 11);
    print(tail);
    insertion(tail, 20, 12);
    print(tail);
    return 0;
}