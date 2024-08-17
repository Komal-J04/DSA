/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    void reverse(ListNode *&head)
    {
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *forward;
        while (curr)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        head = prev;
    }

    void remove(ListNode *head)
    {
        ListNode *prev = head;
        ListNode *curr = head->next;
        int maxi = head->val;
        while (curr)
        {
            if ((curr->val) >= maxi)
            {
                maxi = curr->val;
                prev = curr;
                curr = curr->next;
            }
            else
            {
                prev->next = curr->next;
                curr = prev->next;
            }
        }
    }
    ListNode *removeNodes(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        reverse(head);
        remove(head);
        reverse(head);
        return head;
    }
};