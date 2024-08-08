/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int maxLevelSum(TreeNode *root)
    {
        if (!root)
            return 0;

        int lvl = 1, maxi = root->val;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 1});
        while (!q.empty())
        {
            int sz = q.size(), s = 0, l = q.front().second;
            for (int i = 0; i < sz; i++)
            {
                TreeNode *curr = q.front().first;
                q.pop();
                s += curr->val;
                if (curr->left)
                    q.push({curr->left, l + 1});
                if (curr->right)
                    q.push({curr->right, l + 1});
            }
            if (s > maxi)
            {
                maxi = s;
                lvl = l;
            }
        }
        return lvl;
    }
};