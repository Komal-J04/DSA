#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/
// SOLUTION 1
//  T.C. - O(n)       S.C. - O(1)
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *curr = head;
    LinkedListNode<int> *forward;

    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    // head = prev;
    // return head;
    // OR
    return prev;
}

// SOLUTION 2 - RECURSION
//  T.C. - O(n)       S.C. - O(n)
void reverse(LinkedListNode<int> *&head, LinkedListNode<int> *prev, LinkedListNode<int> *curr)
{
    if (curr == NULL)
    {
        head = prev;
        return;
    }

    LinkedListNode<int> *forward = curr->next;
    curr->next = prev;
    reverse(head, curr, forward);
}

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *curr = head;

    reverse(head, prev, curr);

    return head;
}

// SOLUTION 3 - RECURSION
//  T.C. - O(n)       S.C. - O(n)
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    LinkedListNode<int> *smallHead = reverseLinkedList(head->next);

    head->next->next = head;
    head->next = NULL;

    return smallHead;
}