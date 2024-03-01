// https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution
{
public:
    // <leftmost, rightmost>
    pair<Node *, Node *> dfs(Node *node)
    {
        if (!node)
            return {nullptr, nullptr};

        auto [a_leftmost, a_rightmost] = dfs(node->left);
        auto [b_leftmost, b_rightmost] = dfs(node->right);

        Node *leftmost = node, *rightmost = node;
        if (a_rightmost)
        {
            a_rightmost->right = node;
            node->left = a_rightmost;
            leftmost = a_leftmost ? a_leftmost : a_rightmost;
        }
        if (b_leftmost)
        {
            node->right = b_leftmost;
            b_leftmost->left = node;
            rightmost = b_rightmost ? b_rightmost : b_leftmost;
        }

        return {leftmost, rightmost};
    }

    Node *treeToDoublyList(Node *root)
    {

        auto [head, last] = dfs(root);
        if (head && last)
        {
            last->right = head;
            head->left = last;
        }
        return head;
    }
};