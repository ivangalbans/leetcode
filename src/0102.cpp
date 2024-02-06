// https://leetcode.com/problems/binary-tree-level-order-traversal/description/

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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (!root)
            return {};

        vector<vector<int>> ans = {{root->val}};
        vector<TreeNode *> parents = {root};

        while (!parents.empty())
        {
            vector<TreeNode *> children;
            vector<int> vals;
            for (auto node : parents)
            {
                if (node->left)
                    children.push_back(node->left);
                if (node->right)
                    children.push_back(node->right);
            }
            if (!children.empty())
            {
                ans.push_back(vector<int>());
                for (auto ch : children)
                    ans.back().push_back(ch->val);
            }

            parents = children;
        }

        return ans;
    }
};