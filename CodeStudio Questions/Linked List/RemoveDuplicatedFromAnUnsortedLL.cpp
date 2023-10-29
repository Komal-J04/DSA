#include <bits/stdc++.h>
/****************************************************************
    Following is the class structure of the Node class:
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
*****************************************************************/

// TLE for large test cases     T.C. - O(n^2)   S.C.-O(1)
// For every node we need to traverse entire list, which can be of length n in worst case
Node *removeDuplicates(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *curr = head->next;
    Node *pre = head;

    while (curr != NULL)
    {
        Node *prev = head;
        while (prev != curr)
        {
            if (curr->data == prev->data)
            {
                pre->next = curr->next;
                delete curr;
                curr = pre;
                break; // because the previous node has already been checked for duplicates
            }

            prev = prev->next;
        }
        pre = curr;
        curr = curr->next;
    }
    return head;
}

//  TLE for large test cases     T.C. - O(n^2)   S.C.-O(1)
// Better than previous, in 1 traversal, we are done dealing with all the nodes which have the same value
Node *removeDuplicates(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *curr = head;

    while (curr != NULL)
    {
        Node *tempPrev = curr;
        Node *temp = curr->next;

        while (temp != NULL)
        {
            if (temp->data == curr->data)
            {
                tempPrev->next = temp->next;
                temp->next = NULL;
                delete temp;

                temp = tempPrev->next;
            }
            else
            {
                tempPrev = temp;
                temp = temp->next;
            }
        }
        curr = curr->next;
    }
    return head;
}