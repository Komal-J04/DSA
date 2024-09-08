// https://leetcode.com/problems/split-linked-list-in-parts/?envType=daily-question&envId=2024-09-08

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
    int len(ListNode *&head)
    {
        int l = 0;
        ListNode *temp = head;
        while (temp)
        {
            l++;
            temp = temp->next;
        }
        return l;
    }

    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        int length = len(head);
        int baseLen = length / k;
        int remainder = length % k;
        ListNode *curr = head;
        vector<ListNode *> ans;

        for (int i = 0; i < k; i++)
        {
            ans.push_back(curr);
            int limit = baseLen - 1 + (remainder ? 1 : 0);

            for (int j = 0; j < limit; j++)
            {
                if (!curr)
                    break;
                curr = curr->next;
            }

            if (remainder)
                remainder -= 1;
            if (curr)
            {
                ListNode *temp = curr->next;
                curr->next = NULL;
                curr = temp;
            }
        }

        return ans;
    }
};