// https://leetcode.com/problems/lexicographical-numbers/description/

struct Trie
{
    struct node
    {
        int num;
        node *edge[10];

        node() : num(-1) { memset(edge, 0, sizeof(edge)); }
    } *root;

    Trie() { root = new node(); }

    void insert(int num)
    {
        node *t = root;
        for (auto ch : to_string(num))
        {
            int pos = ch - '0';
            if (!t->edge[pos])
                t->edge[pos] = new node();
            t = t->edge[pos];
        }
        t->num = num;
    }

    void search_all(node *t, vector<int> &ans)
    {
        if (t->num >= 0)
            ans.push_back(t->num);

        for (int i = 0; i <= 9; ++i)
            if (t->edge[i])
                search_all(t->edge[i], ans);
    }

    vector<int> search_all()
    {
        vector<int> ans;
        search_all(root, ans);
        return ans;
    }
};

class Solution
{
private:
    Trie trie;

public:
    vector<int> lexicalOrder(int n)
    {
        for (int i = 1; i <= n; ++i)
            trie.insert(i);
        return trie.search_all();
    }
};