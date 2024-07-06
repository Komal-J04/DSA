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
    ListNode *oddEvenList(ListNode *head)
    {
        int cnt = 1;

        ListNode *oddHead = new ListNode(-1);
        ListNode *oddTemp = oddHead;
        ListNode *evenHead = new ListNode(-1);
        ListNode *evenTemp = evenHead;

        ListNode *temp = head;

        while (temp)
        {
            if (cnt % 2 == 1)
            {
                oddTemp->next = new ListNode(temp->val);
                oddTemp = oddTemp->next;
            }
            else
            {
                evenTemp->next = new ListNode(temp->val);
                evenTemp = evenTemp->next;
            }
            cnt++;
            temp = temp->next;
        }

        oddTemp->next = evenHead->next;

        return oddHead->next;
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

// APPROACH 2 - in place rearrangement
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
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *temp = even;

        while (even && even->next)
        {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }

        odd->next = temp;

        return head;
    }
};