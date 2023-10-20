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
<<<<<<< HEAD
    if (tail == NULL)
    {
        cout << "Empty list" << endl;
        return;
    }
=======
>>>>>>> fb745e5449705034c1cbb3e6a9cb44509f6d1cec
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

<<<<<<< HEAD
// delete node with value d
void deletion(Node *&tail, int d)
{
    if (tail == NULL)
    {
        cout << "List is empty already" << endl;
        return;
    }
    Node *prev = tail;
    Node *curr = prev->next;
    if (curr == prev)
        tail = NULL;
    do
    {
        if (curr->data == d)
        {
            if (tail == curr)
                tail = prev;
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (prev != tail);
}

=======
>>>>>>> fb745e5449705034c1cbb3e6a9cb44509f6d1cec
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
<<<<<<< HEAD

    deletion(tail, 6);
    print(tail);
    deletion(tail, 20);
    print(tail);
    deletion(tail, 5);
    print(tail);
    deletion(tail, 10);
    print(tail);
    deletion(tail, 15);
    print(tail);
    deletion(tail, 17);
    print(tail);
    deletion(tail, 17);
    print(tail);

=======
>>>>>>> fb745e5449705034c1cbb3e6a9cb44509f6d1cec
    return 0;
}