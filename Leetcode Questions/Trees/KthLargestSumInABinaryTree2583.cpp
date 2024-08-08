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
    long long kthLargestLevelSum(TreeNode *root, int k)
    {
        if (!root)
            return 0;
        vector<long long> s;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            long long sz = q.size(), sum = 0;
            for (long long i = 0; i < sz; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                sum += curr->val;
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            s.push_back(sum);
        }
        if (s.size() < k)
            return -1;
        sort(s.begin(), s.end(), greater<>());
        return s[k - 1];
    }
};