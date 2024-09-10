// https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/description/?envType=daily-question&envId=2024-09-10

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
    int gcd(int a, int b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    ListNode *insertGreatestCommonDivisors(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *temp = head;
        while (temp->next)
        {
            ListNode *nextNode = temp->next;
            if (temp->val == nextNode->val)
            {
                temp->next = new ListNode(temp->val);
                temp->next->next = nextNode;
                temp = nextNode;
            }
            else
            {
                int a = (temp->val > nextNode->val) ? temp->val : nextNode->val;
                int b = (temp->val < nextNode->val) ? temp->val : nextNode->val;
                temp->next = new ListNode(gcd(a, b));
                temp->next->next = nextNode;
                temp = nextNode;
            }
        }

        return head;
    }
};