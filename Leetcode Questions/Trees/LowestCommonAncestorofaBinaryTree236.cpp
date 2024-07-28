// APPROACH 1 - USING ROOT TO NODE PATH
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    bool rootToNodePath(TreeNode *root, TreeNode *node, vector<TreeNode *> &path)
    {
        if (!root)
            return false;

        path.push_back(root);

        if (node == root)
            return true;

        if (rootToNodePath(root->left, node, path) || rootToNodePath(root->right, node, path))
            return true;

        path.pop_back();

        return false;
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        vector<TreeNode *> path1;
        rootToNodePath(root, p, path1);
        vector<TreeNode *> path2;
        rootToNodePath(root, q, path2);

        int i = 0, j = 0;
        TreeNode *ans;
        while (i < path1.size() && j < path2.size() && path1[i] == path2[j])
        {
            ans = path1[i];
            i++;
            j++;
        }

        return ans;
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

// APPROACH 2
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root || (root == p) || (root == q))
            return root;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (!left)
            return right;
        if (!right)
            return left;
        return root;
    }
};