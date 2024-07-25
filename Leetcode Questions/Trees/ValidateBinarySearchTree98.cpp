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
    vector<int> in(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return ans;
        stack<TreeNode *> s;
        TreeNode *curr = root;
        while (true)
        {
            if (curr)
            {
                s.push(curr);
                curr = curr->left;
            }
            else
            {
                if (s.empty())
                    break;
                curr = s.top();
                s.pop();
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
        return ans;
    }

    bool isValidBST(TreeNode *root)
    {
        vector<int> inorder = in(root);
        int n = inorder.size();
        for (int i = 0; i < (n - 1); i++)
        {
            if (inorder[i] >= inorder[i + 1])
                return false;
        }
        return true;
    }
};