#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.

    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int> *sortTwoLists(Node<int> *first, Node<int> *second)
{
    if (first == NULL)
        return second;
    if (second == NULL)
        return first;

    Node<int> *temp1 = first;
    Node<int> *temp2 = second;

    Node<int> *newHead;

    if (temp1->data <= temp2->data)
    {
        newHead = temp1;
        temp1 = temp1->next;
    }
    else
    {
        newHead = temp2;
        temp2 = temp2->next;
    }

    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data <= temp2->data)
        {
            newHead->next = temp1;
            temp1 = temp1->next;
        }
        else
        {
            newHead->next = temp2;
            temp2 = temp2->next;
        }
    }

    while (temp1)
    {
        newHead->next = temp1;
        temp1 = temp1->next;
    }

    while (temp2)
    {
        newHead->next = temp2;
        temp2 = temp2->next;
    }

    return newHead;
}
