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
