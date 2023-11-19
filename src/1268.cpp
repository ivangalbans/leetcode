// https://leetcode.com/problems/search-suggestions-system/description/

struct Trie
{
    struct node
    {
        int id;
        vector<int> ids;
        node *edge[26];

        node() : id(-1) { memset(edge, 0, sizeof(edge)); }
    } *root;

    Trie() { root = new node(); }

    void insert(string s, int id)
    {
        node *t = root;
        for (auto ch : s)
        {
            int pos = ch - 'a';
            if (!t->edge[pos])
                t->edge[pos] = new node();
            t->ids.push_back(id);
            t = t->edge[pos];
        }
        t->ids.push_back(id);
        t->id = id;
    }

    vector<int> search(string s)
    {
        vector<int> ids;
        node *t = root;

        for (auto ch : s)
        {
            int pos = ch - 'a';
            if (!t->edge[pos])
                return ids;
            t = t->edge[pos];
        }

        for (int i = 1; i <= min(3, (int)t->ids.size()); ++i)
            ids.push_back(t->ids[i - 1]);

        return ids;
    }
};

class Solution
{
private:
    Trie trie;

public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
    {
        int n = products.size();
        sort(begin(products), end(products));

        for (int i = 0; i < n; ++i)
            trie.insert(products[i], i);

        vector<vector<string>> suggestions(searchWord.length());
        for (int i = 0; i < searchWord.length(); ++i)
        {
            auto ids = trie.search(searchWord.substr(0, i + 1));
            for (auto id : ids)
                suggestions[i].push_back(products[id]);
        }

        return suggestions;
    }
};