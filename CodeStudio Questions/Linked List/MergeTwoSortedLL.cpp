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
    Node<int> *temp3;

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

    temp3 = newHead;

    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data <= temp2->data)
        {
            temp3->next = temp1;
            temp1 = temp1->next;
            temp3 = temp3->next;
        }
        else
        {
            temp3->next = temp2;
            temp2 = temp2->next;
            temp3 = temp3->next;
        }
    }

    while (temp1)
    {
        temp3->next = temp1;
        temp1 = temp1->next;
        temp3 = temp3->next;
    }

    while (temp2)
    {
        temp3->next = temp2;
        temp2 = temp2->next;
        temp3 = temp3->next;
    }

    return newHead;
}
