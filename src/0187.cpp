// https://leetcode.com/problems/repeated-dna-sequences/description/

struct Trie
{
    struct node
    {
        int full;
        node *edge[26];
        node() : full(0)
        {
            memset(edge, 0, sizeof(edge));
        }
    } *root;

    Trie()
    {
        root = new node();
    }

    int insert(string &s)
    {
        node *t = root;
        for (auto ch : s)
        {
            int pos = ch - 'A';
            if (!t->edge[pos])
                t->edge[pos] = new node();
            t = t->edge[pos];
        }

        return ++t->full;
    }
};

class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        int n = s.length();
        unordered_set<string> ans;

        Trie trie;
        string w;
        for (int i = 0; i + 9 < n; ++i)
        {
            w = s.substr(i, 10);
            if (trie.insert(w) >= 2)
                ans.insert(w);
        }

        return vector<string>(begin(ans), end(ans));
    }
};

// Hashset

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        unordered_set<string> dna;
        unordered_set<string> ans;

        string w;
        for(int i = 0; i + 9 < n; ++i) {
            w = s.substr(i, 10);
            if(dna.contains(w))
                ans.insert(w);
            else
                dna.insert(w);
        }

        return vector<string>(begin(ans), end(ans));
    }
};