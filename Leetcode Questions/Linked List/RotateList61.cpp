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
    int size(ListNode *head)
    {
        int cnt = 1;
        ListNode *temp = head;
        while (temp->next)
        {
            temp = temp->next;
            cnt++;
        }
        return cnt;
    }

    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next)
            return head;

        k = k % size(head);

        while (k--)
        {
            ListNode *tail = head;
            while (tail->next->next)
                tail = tail->next;
            ListNode *temp = tail->next;
            tail->next = NULL;
            temp->next = head;
            head = temp;
        }
        return head;
    }
};

// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************

// APPROACH 2
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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next || (k == 0))
            return head;

        int n = 1;
        ListNode *tail = head;
        while (tail->next)
        {
            ++n;
            tail = tail->next;
        }

        k = k % n;
        if (k == 0)
            return head;
        tail->next = head;

        ListNode *temp = head;
        for (int i = 0; i < (n - k - 1); i++)
            temp = temp->next;

        ListNode *newHead = temp->next;
        temp->next = NULL;
        return newHead;
    }
};