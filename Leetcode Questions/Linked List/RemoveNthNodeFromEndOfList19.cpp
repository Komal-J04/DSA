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
    int getLen(ListNode *head)
    {
        int ans = 0;
        ListNode *temp = head;

        while (temp)
        {
            ans++;
            temp = temp->next;
        }

        return ans;
    }

    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int len = getLen(head);
        if (n == len)
            return head->next;

        n = len - n;
        ListNode *prev = NULL;
        ListNode *curr = head;

        while (n--)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        delete curr;

        return head;
    }
};