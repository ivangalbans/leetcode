// https://leetcode.com/problems/closest-binary-search-tree-value/

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
    pair<double, int> closestValueTree(TreeNode *node, double target)
    {
        TreeNode *next;
        if (node->left && target < node->val)
            next = node->left;
        if (node->right && target >= node->val)
            next = node->right;
        if (!next)
            return {abs(node->val - target), node->val};

        return min(pair<double, int>(abs(node->val - target), node->val), closestValueTree(next, target));
    }

    int closestValue(TreeNode *root, double target)
    {
        return closestValueTree(root, target).second;
    }
};

// Iterative

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
    int closestValue(TreeNode *root, double target)
    {
        int closest = root->val;
        double diff = 1e9 + 1;
        do
        {
            if (abs(root->val - target) < diff)
            {
                closest = root->val;
                diff = abs(root->val - target);
            }
            if (abs(root->val - target) == diff)
                closest = min(closest, root->val);

            root = (target < root->val) ? root->left : root->right;

        } while (root);

        return closest;
    }
};