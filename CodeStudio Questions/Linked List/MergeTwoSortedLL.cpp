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

// SOLN 1
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

// SOLN 2  T.C.-O(N) S.C.-O(1)
Node<int> *sort(Node<int> *first, Node<int> *second)
{

    // if only 1 element is present in first list
    if (first->next == NULL)
    {
        first->next = second;
        return first;
    }

    Node<int> *prev = first;
    Node<int> *curr = prev->next;
    Node<int> *temp = second;

    while (temp != NULL && curr != NULL)
    {
        if (temp->data >= prev->data && temp->data <= curr->data)
        {
            Node<int> *temp2 = temp->next;
            prev->next = temp;
            temp->next = curr;
            prev = temp;
            temp = temp2;
        }
        else
        {
            prev = curr;
            curr = curr->next;
            if (curr == NULL) // first list is over
            {
                prev->next = temp;
                return first;
            }
        }
    }

    return first; // the loop is exited only if one of temp or curr is null, temp null implies 2nd list over=>merged, curr null is handled in the loop
}

Node<int> *sortTwoLists(Node<int> *first, Node<int> *second)
{
    if (first == NULL)
        return second;
    if (second == NULL)
        return first;

    if (first->data <= second->data)
        return sort(first, second);
    return sort(second, first);
}
