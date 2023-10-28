/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// SOLUTION 1 - FLOYD CYCLE DETECTION ALGORITHM
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;

            if (slow == fast)
                return true;
        }

        return false;
    }
};

// SOLUTION 2 - USING MAP
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == NULL)
            return false;

        map<ListNode *, bool> map;
        map[head] = true;

        ListNode *curr = head->next;

        while (curr != NULL && map[curr] != true)
        {
            map[curr] = true;
            curr = curr->next;
        }

        if (curr == NULL)
            return false;
        return true;
    }
};