// https://leetcode.com/problems/prefix-and-suffix-search/description/

struct Trie
{
    struct node
    {
        int id;
        node *edge[27];
        node() : id(-1) { memset(edge, 0, sizeof(edge)); }
    } *root;

    Trie() { root = new node(); }

    void insert(string word, int id)
    {
        node *t = root;
        for (auto ch : word)
        {
            int pos = ch - 'a';
            if (!t->edge[pos])
                t->edge[pos] = new node();
            t = t->edge[pos];
            t->id = id;
        }
    }

    int searchIndex(string word)
    {
        node *t = root;
        for (char ch : word)
        {
            int pos = ch - 'a';
            if (!t->edge[pos])
                return -1;
            t = t->edge[pos];
        }
        return t->id;
    }
};

class WordFilter
{
private:
    Trie trie;

public:
    WordFilter(vector<string> &words)
    {
        for (int i = 0; i < words.size(); ++i)
        {
            string word = words[i];
            for (int j = 0; j < word.length(); ++j)
            {
                string suff = word.substr(j, word.length() - j);
                string w = suff + "{" + word;
                trie.insert(w, i);
            }
        }
    }

    int f(string pref, string suff)
    {
        return trie.searchIndex(suff + "{" + pref);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */

// HashMap

class WordFilter
{
private:
    unordered_map<string, int> mapId;

    vector<string> prefix(string word)
    {
        vector<string> ans;
        for (int len = 1; len <= word.length(); ++len)
            ans.push_back(word.substr(0, len));
        return ans;
    }

    vector<string> suffix(string word)
    {
        vector<string> ans;
        for (int i = 0; i < word.length(); ++i)
            ans.push_back(word.substr(i, word.length()));
        return ans;
    }

public:
    WordFilter(vector<string> &words)
    {
        for (int i = 0; i < words.size(); ++i)
        {
            string word = words[i];
            for (auto pref : prefix(word))
                for (auto suff : suffix(word))
                    mapId[pref + "|" + suff] = i + 1;
        }
    }

    int f(string pref, string suff)
    {
        return mapId[pref + "|" + suff] - 1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */