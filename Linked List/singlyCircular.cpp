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
    if (tail == NULL)
    {
        cout << "Circular linked list is empty" << endl;
        return;
    }

    Node *temp = tail->next;
    cout << "Current state of LL - ";

    // if there is a single element in the LL, while loop will not work
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail->next);
    cout << endl;

    delete temp;
}

// insert d after element
void insertion(Node *&tail, int element, int d)
{
    Node *newNode = new Node(d);

    // empty list
    if (tail == NULL)
    {
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        // non-empty list
        // assuming that the element is present in the list

        Node *temp = tail;

        while (temp->data != element)
        {
            temp = temp->next;
        }

        // element found -> temp is representing element wala node
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

int main()
{
    Node *tail = NULL;
    insertion(tail, 5, 3);
    print(tail);
    insertion(tail, 3, 5);
    print(tail);

    return 0;
}