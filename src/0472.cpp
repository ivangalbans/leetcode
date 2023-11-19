// https://leetcode.com/problems/concatenated-words/

struct Trie
{
    struct node
    {
        int full;
        node *edge[26];

        node() : full(0) { memset(edge, 0, sizeof(edge)); }
    } *root;

    Trie() { root = new node(); }

    void insert(string &s)
    {
        node *t = root;
        for (auto ch : s)
        {
            int pos = ch - 'a';
            if (!t->edge[pos])
                t->edge[pos] = new node();
            t = t->edge[pos];
        }
        t->full++;
    }

    bool is_concatenated(string &s, int i, node *t, int nwords)
    {
        if (i == s.length())
            return nwords >= 2;

        for (; i < s.length(); ++i)
        {
            int pos = s[i] - 'a';
            if (!t->edge[pos])
            {
                return false;
            }

            t = t->edge[pos];
            if (t->full && is_concatenated(s, i + 1, root, nwords + 1))
                return true;
        }

        return false;
    }

    bool is_concatenated(string s)
    {
        return is_concatenated(s, 0, root, 0);
    }
};

class Solution
{
private:
    Trie trie;

public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
        sort(begin(words), end(words), [](const string &s1, const string &s2)
             { return s1.size() < s2.size(); });

        vector<string> ans;
        for (auto &word : words)
            if (trie.is_concatenated(word))
                ans.push_back(word);
            else
                trie.insert(word);

        return ans;
    }
};

// DP

class Solution
{
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
        unordered_set<string> us(begin(words), end(words));
        vector<string> ans;

        for (auto &word : words)
        {
            int len = word.length();
            vector<bool> dp(len + 1);
            dp[0] = true;

            for (int i = 0; i < len; ++i)
            {
                if (!dp[i])
                    continue;
                for (int j = i + 1; j <= len; ++j)
                    if (j - i < len && us.count(word.substr(i, j - i)))
                        dp[j] = true;
                if (dp[len])
                {
                    ans.push_back(word);
                    break;
                }
            }
        }

        return ans;
    }
};