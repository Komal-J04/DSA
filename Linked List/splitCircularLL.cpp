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
        cout << "Empty list" << endl;
        return;
    }
    Node *temp = tail;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail);
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
            return;
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

int getLen(Node *tail)
{
    Node *temp = tail->next;
    int count = 1;
    while (temp != tail)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

Node *split(Node *&tail, int len)
{
    tail = tail->next;

    int x;
    if (len % 2 == 0)
        x = len / 2;
    else
        x = (len / 2) + 1;

    Node *slow = tail;
    Node *fast = tail;

    int count = 1;
    while (count < x)
    {
        count++;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast->next != tail)
        fast = fast->next;

    fast->next = slow->next;
    Node *newHead = slow->next;
    slow->next = tail;

    return newHead;
}

int main()
{
    Node *tail = NULL;

    insertion(tail, 1, 1);
    print(tail);
    insertion(tail, 3, 1);
    print(tail); // the tail is being displayed first, then the other elements
    insertion(tail, 2, 1);
    print(tail);
    insertion(tail, 5, 4);
    print(tail);
    insertion(tail, 4, 3);
    print(tail);

    int len = getLen(tail);

    cout << "Split circular LL - " << endl;
    Node *newHead = split(tail, len);
    print(tail);
    print(newHead);

    return 0;
}