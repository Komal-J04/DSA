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
// T.C. - O(n)
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

Node *findMiddle(Node *head)
{
    int n = getLen(head) / 2;

    Node *temp = head;
    for (int i = 0; i < n; i++)
    {
        temp = temp->next;
    }

    return temp;
}

// SOLUTION 2 - Two pointer approach
// T.C. - O(n)
Node *findMiddle(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *twoSteps = head;
    Node *oneStep = head;

    while (twoSteps->next != NULL)
    {
        twoSteps = twoSteps->next;
        if (twoSteps->next != NULL)
            twoSteps = twoSteps->next; // in case of even no. of nodes
        oneStep = oneStep->next;       // when even no. of nodes, we have to return the 2nd middle one
    }

    return oneStep;
}