// APPROACH 1 - RECURSIVE(DFS)
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
    int sum(TreeNode *root, bool isLeft)
    {
        if (!root)
            return 0;
        if (!root->left && !root->right && isLeft)
            return root->val;

        return sum(root->left, true) + sum(root->right, false);
    }
    int sumOfLeftLeaves(TreeNode *root)
    {
        return sum(root, false);
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

// APPROACH 2 - BFS
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
    int sumOfLeftLeaves(TreeNode *root)
    {
        int ans = 0;
        queue<pair<TreeNode *, bool>> q;
        q.push({root, 0});

        while (!q.empty())
        {
            TreeNode *curr = q.front().first;
            bool isLeft = q.front().second;
            q.pop();
            if (isLeft && !curr->left && !curr->right)
                ans += curr->val;
            if (curr->left)
                q.push({curr->left, true});
            if (curr->right)
                q.push({curr->right, false});
        }

        return ans;
    }
};