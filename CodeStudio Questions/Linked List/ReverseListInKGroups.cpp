/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

// T.C. - O(n)      S.C. - O(n) [say each iteration uses k space => (n/k)*k]
Node *kReverse(Node *head, int k)
{
    // base case
    if (head == NULL)
        return head;

    // step 1 - reverse k nodes
    Node *prev = NULL;
    Node *curr = head;
    Node *forward;
    int count = 0;

    // step 2 - check if there are atleast k nodes remaining
    while (curr != NULL)
    {
        count++;
        curr = curr->next;
        if (count > k)
            break;
    }

    if (count < k)
        return head; // number of remaining nodes<k => they should be left unchanged

    // step 3 - reverse the k nodes
    curr = head;
    count = 0;

    while (curr != NULL && count < k)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    // step 4 : recursive call
    if (forward != NULL)
    {
        head->next = kReverse(forward, k);
    }

    // step 5 : return head of reversed list
    return prev;
}