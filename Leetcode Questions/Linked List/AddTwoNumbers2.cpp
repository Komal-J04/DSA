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
    void insertAtTail(ListNode *&head, int val)
    {
        ListNode *newNode = new ListNode(val);

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        ListNode *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int sum = 0, carry = 0;
        ListNode *temp1 = l1;
        ListNode *temp2 = l2;
        ListNode *ans = NULL;
        while (temp1 != NULL || temp2 != NULL || carry != 0)
        {
            sum = (temp1 ? temp1->val : 0) + (temp2 ? temp2->val : 0) + carry;
            insertAtTail(ans, sum % 10);
            carry = sum / 10;
            if (temp1)
                temp1 = temp1->next;
            if (temp2)
                temp2 = temp2->next;
        }
        return ans;
    }
};