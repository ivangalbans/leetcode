// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

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
        if (root == NULL || root == p || root == q)
            return root;

        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);

        if (left == NULL)
            return right;
        if (right == NULL)
            return left;

        return root;
    }
};

// Finding Path

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
    bool find_path(TreeNode *root, TreeNode *u, vector<TreeNode *> &path)
    {
        if (root == NULL)
            return false;
        if (root == u)
        {
            path.push_back(root);
            return true;
        }

        auto left = find_path(root->left, u, path);
        auto right = find_path(root->right, u, path);

        if (left || right)
        {
            path.push_back(root);
            return true;
        }

        return false;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        vector<TreeNode *> path_p, path_q;
        find_path(root, p, path_p);
        reverse(begin(path_p), end(path_p));
        find_path(root, q, path_q);
        reverse(begin(path_q), end(path_q));

        for (int i = 0; i < min(path_p.size(), path_q.size()); ++i)
            if (path_p[i]->val != path_q[i]->val)
                return path_p[i - 1];

        return path_p[min(path_p.size(), path_q.size()) - 1];
    }
};