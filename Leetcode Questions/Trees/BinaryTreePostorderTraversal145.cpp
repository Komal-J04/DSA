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
    void postorder(TreeNode *node, vector<int> &ans)
    {
        if (node == NULL)
            return;

        postorder(node->left, ans);
        postorder(node->right, ans);
        ans.push_back(node->val);
    }

    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        postorder(root, ans);
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

// APPROACH 2 - ITERATIVE USING 2 STACKS
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
    vector<int> postorderTraversal(TreeNode *root)
    {
        if (!root)
            return {};
        vector<int> ans;
        stack<TreeNode *> s1, s2;
        s1.push(root);
        while (!s1.empty())
        {
            TreeNode *temp = s1.top();
            s1.pop();
            s2.push(temp);
            if (temp->left)
                s1.push(temp->left);
            if (temp->right)
                s1.push(temp->right);
        }

        while (!s2.empty())
        {
            ans.push_back(s2.top()->val);
            s2.pop();
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

// APPROACH 3 - ITERATIVE USING 1 STACK
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
    vector<int> postorderTraversal(TreeNode *root)
    {
        if (!root)
            return {};
        stack<TreeNode *> s;
        vector<int> ans;
        TreeNode *temp = root;
        while (temp || !s.empty())
        {
            if (temp)
            {
                s.push(temp);
                temp = temp->left;
            }
            else
            {
                TreeNode *curr = s.top()->right;
                if (curr == NULL)
                {
                    curr = s.top();
                    s.pop();
                    ans.push_back(curr->val);
                    while (!s.empty() && curr == s.top()->right)
                    {
                        curr = s.top();
                        s.pop();
                        ans.push_back(curr->val);
                    }
                }
                else
                    temp = curr;
            }
        }

        return ans;
    }
};