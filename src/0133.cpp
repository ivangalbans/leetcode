// https://leetcode.com/problems/clone-graph/description/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
private:
    unordered_map<Node *, Node *> mp;

    void dfs(Node *u)
    {
        Node *copy = new Node(u->val);
        mp[u] = copy;

        for (auto v : u->neighbors)
        {
            if (mp.find(v) == mp.end())
                dfs(v);
            copy->neighbors.push_back(mp[v]);
        }
    }

public:
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return nullptr;
        dfs(node);
        return mp[node];
    }
};