/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

// SOLUTION 1 - BRUTE FORCE
Node *sortList(Node *head)
{
    int zero = 0;
    int one = 0;
    int two = 0;

    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
            zero++;
        if (temp->data == 1)
            one++;
        if (temp->data == 2)
            two++;

        temp = temp->next;
    }

    // cout<<zero<<" "<<one<<" "<<two<<endl;

    temp = head;
    while (zero > 0)
    {
        temp->data = 0;
        zero--;
        temp = temp->next;
    }
    while (one > 0)
    {
        temp->data = 1;
        one--;
        temp = temp->next;
    }
    while (two > 0)
    {
        temp->data = 2;
        two--;
        temp = temp->next;
    }

    return head;
}

// SOLUTION 2 - NO DATA MANIPULATION
void populate(Node *&tail, Node *curr)
{
    tail->next = curr;
    tail = curr;
}

Node *sortList(Node *head)
{
    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;
    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;
    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;

    Node *curr = head;

    // 3 separate linked lists
    while (curr != NULL)
    {
        int value = curr->data;

        if (value == 0)
            populate(zeroTail, curr);
        if (value == 1)
            populate(oneTail, curr);
        if (value == 2)
            populate(twoTail, curr);

        curr = curr->next;
    }

    // merge the 3 linked lists
    if (oneHead->next != NULL) // 1 list is non empty
    {
        zeroTail->next = oneHead->next;
        oneTail->next = twoHead->next;
        twoTail->next = NULL;
    }
    else // 1 list is empty
    {
        zeroTail->next = twoHead->next;
        twoTail->next = NULL;
    }

    // set head
    head = zeroHead->next;

    // delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}