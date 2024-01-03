// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

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
    void find_path(TreeNode *root, TreeNode *u, vector<TreeNode *> &path)
    {
        path.push_back(root);

        if (root == u)
            return;

        if (u->val < root->val)
            find_path(root->left, u, path);
        else
            find_path(root->right, u, path);
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        vector<TreeNode *> path_p, path_q;
        find_path(root, p, path_p);
        find_path(root, q, path_q);

        for (int i = 0; i < min(path_p.size(), path_q.size()); ++i)
            if (path_p[i]->val != path_q[i]->val)
                return path_p[i - 1];

        return path_p[min(path_p.size(), path_q.size()) - 1];
    }
};

// BST

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
    TreeNode *lowestCommonAncestor2(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (p->val <= root->val && root->val <= q->val)
            return root;
        return p->val < root->val ? lowestCommonAncestor2(root->left, p, q) : lowestCommonAncestor2(root->right, p, q);
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (p->val > q->val)
            swap(p, q);
        return lowestCommonAncestor2(root, p, q);
    }
};
