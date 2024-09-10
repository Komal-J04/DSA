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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
    {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        if (!head)
            return ans;

        ListNode *curr = head;
        int sRow = 0, eRow = (m - 1), sCol = 0, eCol = (n - 1);

        while (curr)
        {
            int j = sCol;
            while (curr && (j <= eCol))
            {
                ans[sRow][j] = curr->val;
                curr = curr->next;
                j++;
            }
            sRow++;

            j = sRow;
            while (curr && (j <= eRow))
            {
                ans[j][eCol] = curr->val;
                curr = curr->next;
                j++;
            }
            eCol--;

            j = eCol;
            while (curr && (j >= sCol))
            {
                ans[eRow][j] = curr->val;
                curr = curr->next;
                j--;
            }
            eRow--;

            j = eRow;
            while (curr && (j >= sRow))
            {
                ans[j][sCol] = curr->val;
                curr = curr->next;
                j--;
            }
            sCol++;
        }

        return ans;
    }
};