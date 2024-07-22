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
    void sum(TreeNode *root, int targetSum, vector<int> path, vector<vector<int>> &ans)
    {
        if (!root)
            return;
        targetSum -= root->val;
        path.push_back(root->val);

        if (!root->left && !root->right && targetSum == 0)
        {
            ans.push_back(path);
            return;
        }

        sum(root->left, targetSum, path, ans);
        sum(root->right, targetSum, path, ans);
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> ans;
        vector<int> path;
        sum(root, targetSum, path, ans);
        return ans;
    }
};