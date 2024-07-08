// https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/?envType=daily-question&envId=2024-07-08

// VARIATION OF JOSEPHUS PROBLEM

// APPROACH 1 - LINKED LIST
class Solution
{
public:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    ListNode *makeLL(int n)
    {
        ListNode *head = new ListNode(1);
        ListNode *temp = head;
        int cnt = 2;
        while (cnt <= n)
        {
            temp->next = new ListNode(cnt);
            temp = temp->next;
            cnt++;
        }
        temp->next = head;
        return head;
    }

    int winner(ListNode *head, int k)
    {
        ListNode *prev = head;
        while (prev->next != head)
            prev = prev->next;

        ListNode *curr = head;
        int cnt = 1;

        while (curr->next != curr)
        {
            if (cnt == k)
            {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
                cnt = 1;
                continue;
            }

            cnt++;
            prev = curr;
            curr = curr->next;
        }
        return curr->val;
    }

    int findTheWinner(int n, int k)
    {
        ListNode *head = makeLL(n);
        return winner(head, k);
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

// APPROACH 2 - VECTOR
class Solution
{
public:
    int findTheWinner(int n, int k)
    {
        vector<int> temp(n);
        int cnt = 1;
        int zeroCount = n;
        int i = 0;
        while (zeroCount > 1)
        {
            if (cnt == k && temp[i] == 0)
            {
                temp[i] = -1;
                cnt = 0;
                zeroCount--;
            }

            if (i == (temp.size() - 1))
                i = 0;
            else
                i++;

            if (temp[i] == 0)
                cnt++;
        }

        for (i = 0; i < n; i++)
        {
            if (temp[i] == 0)
                return i + 1;
        }

        return -1;
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

// APPROACH 3 - FOR LOOP
class Solution
{
public:
    int findTheWinner(int n, int k)
    {
        int winner = 0;
        for (int i = 1; i <= n; ++i)
        {
            winner = (winner + k) % i;
        }
        return winner + 1;
    }
};