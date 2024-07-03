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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        set<int> s;
        s.insert(head->val);
        ListNode *prev = head;
        ListNode *curr = head->next;

        while (curr != NULL)
        {
            if (s.find(curr->val) != s.end())
            {
                while (curr && curr->next && curr->val == curr->next->val)
                {
                    curr = curr->next;
                }
                prev->next = curr->next;
            }
            else
            {
                prev = curr;
                s.insert(curr->val);
            }

            curr = curr->next;
        }

        return head;
    }
};