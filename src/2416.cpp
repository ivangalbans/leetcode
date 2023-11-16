// https://leetcode.com/problems/sum-of-prefix-scores-of-strings/

struct Trie
{
    struct node
    {
        int partial;
        node *edge[26];
        node() : partial(0)
        {
            memset(edge, 0, sizeof(edge));
        }
    } *root;

    Trie() { root = new node(); }

    void insert(string word)
    {
        node *t = root;
        for (auto ch : word)
        {
            int pos = ch - 'a';
            if (!t->edge[pos])
                t->edge[pos] = new node();
            t = t->edge[pos];
            t->partial++;
        }
    }

    int get_score(string word)
    {
        node *t = root;
        int score = 0;
        for (auto ch : word)
        {
            int pos = ch - 'a';
            if (!t->edge[pos])
                break;
            t = t->edge[pos];
            score += t->partial;
        }
        return score;
    }
};

class Solution
{
private:
    Trie trie;

public:
    vector<int> sumPrefixScores(vector<string> &words)
    {
        vector<int> ans;
        for (auto word : words)
            trie.insert(word);
        for (auto word : words)
            ans.push_back(trie.get_score(word));
        return ans;
    }
};