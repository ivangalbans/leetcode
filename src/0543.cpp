// https://leetcode.com/problems/diameter-of-binary-tree/description/

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
    // pair<diameter, longest path from root>
    pair<int, int> diameter(TreeNode *root)
    {
        if (root == nullptr)
            return {0, 0};

        auto [d_left, l_left] = diameter(root->left);
        auto [d_right, l_right] = diameter(root->right);

        return {max({d_left, d_right, l_left + l_right}), 1 + max(l_left, l_right)};
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        return diameter(root).first;
    }
};