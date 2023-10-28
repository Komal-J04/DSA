#include <iostream>
#include <map>
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
    Node *temp = tail->next;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail->next);
    cout << endl;
}

void print2(Node *head)
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

// using map
void detectLoop(Node *head)
{
    if (head == NULL)
    {
        cout << "No loop" << endl;
        return;
    }

    map<Node *, bool> map;
    map[head] = true;

    Node *curr = head->next;

    while (curr != NULL && map[curr] != true)
    {
        map[curr] = true;
        curr = curr->next;
    }
    if (curr == NULL)
        cout << "No loop" << endl;
    if (map[curr])
        cout << "Loop starts on node with value " << curr->data << endl;
}

// Floyd's cycle detection algorithm
bool floyd(Node *head)
{
    if (head == NULL)
        return false;

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

        // both the pointer are initially equal(head), so if we check for this condition before incrementing them we will get true only
        if (slow == fast)
            return true;
    }
}

// start of a loop using Floyd's algo
Node *startNode(Node *head)
{
    // we can get the intersection node from floyd function as well
    if (head == NULL)
        return head;

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
        {
            slow = head;
            break;
        }
    }

    while (slow != fast)
    {
        fast = fast->next;
        slow = slow->next;
    }

    return slow;
}

// this code will not work for circular singly LL because this code makes the node just before the loop start node, point to null. And, in singly LL, that node is a part of the list
/*
Node *removeLoop(Node *head)
{
    if (head == NULL)
        return head;

    Node *loopStartNode = startNode(head);
    // cout << "In removeLoop, loop start node = " << loopStartNode->data << endl;
    if (loopStartNode != NULL)
    {
        Node *temp = loopStartNode;

        while (temp->next != loopStartNode)
        {
            cout << "temp->data = " << temp->data << endl;
            temp = temp->next;
        }

        temp->next = NULL;
        return head;
    }
}
*/

Node *removeLoop(Node *tail)
{
    if (tail == NULL)
        return tail;

    Node *temp = tail;
    while (temp->next != tail)
    {
        temp = temp->next;
    }
    temp->next = NULL;

    return tail;
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

    deletion(tail, 6);
    print(tail);
    deletion(tail, 20);
    print(tail);
    deletion(tail, 5);
    print(tail);

    detectLoop(tail);

    if (floyd(tail))
        cout << "Loop detected" << endl;
    else
        cout << "No loop" << endl;

    Node *loopStartNode = startNode(tail);
    cout << "The loop starts at the node with data " << loopStartNode->data << endl;

    Node *noLoopHead = removeLoop(tail);
    print2(noLoopHead);

    return 0;
}