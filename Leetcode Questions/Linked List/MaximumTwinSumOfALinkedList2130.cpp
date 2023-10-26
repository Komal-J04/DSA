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

// This solution does not work because the originalHead is also modified after calling the reverse function
class Solution
{
public:
    void print(ListNode *head)
    {
        if (head == NULL)
            return;

        ListNode *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ListNode *reverse(ListNode *head, ListNode *prev, ListNode *curr)
    {
        if (curr == NULL)
            return prev;

        ListNode *forward = curr->next;
        curr->next = prev;
        return reverse(head, curr, forward);
    }

    int pairSum(ListNode *head)
    {
        ListNode *originalHead = head; // another pointer called originalHead pointing to the same location as head

        ListNode *revHead = reverse(head, NULL, head);

        print(originalHead);
        cout << "------" << endl;
        print(revHead);

        ListNode *list1 = originalHead;
        ListNode *list2 = revHead;

        int maxSum = INT_MIN;

        while (list1 != NULL && list2 != NULL)
        {
            int sum = list1->val + list2->val;
            if (sum > maxSum)
                maxSum = sum;

            list1 = list1->next;
            list2 = list2->next;
        }

        return maxSum;
    }
};

// SOLUTION
class Solution
{
public:
    int pairSum(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        stack<int> st;
        while (fast && fast->next)
        {
            st.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        int res = 0;
        while (st.size())
        {
            res = max(res, st.top() + slow->val);
            st.pop();
            slow = slow->next;
        }
        return res;
    }
};