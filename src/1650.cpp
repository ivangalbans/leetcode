// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iii/description/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution
{
public:
    vector<Node *> pathToRoot(Node *node)
    {
        vector<Node *> path;
        while (node)
        {
            path.push_back(node);
            node = node->parent;
        }
        return path;
    }

    Node *lowestCommonAncestor(Node *p, Node *q)
    {
        vector<Node *> pathPToRoot = pathToRoot(p);
        vector<Node *> pathQToRoot = pathToRoot(q);

        int i = pathPToRoot.size() - 1;
        int j = pathQToRoot.size() - 1;
        while (i >= 0 && j >= 0 && pathPToRoot[i] == pathQToRoot[j])
        {
            --i;
            --j;
        }

        return pathPToRoot[i + 1];
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution
{
public:
    Node *lowestCommonAncestor(Node *p, Node *q)
    {
        Node *nodeP = p, *nodeQ = q;
        while (nodeP != nodeQ)
        {
            nodeP = !nodeP ? q : nodeP->parent;
            nodeQ = !nodeQ ? p : nodeQ->parent;
        }
        return nodeP;
    }
};