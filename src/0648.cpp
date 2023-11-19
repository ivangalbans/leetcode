// https://leetcode.com/problems/replace-words/description/

struct Trie
{
    struct node
    {
        int full;
        node *edge[26];

        node() : full(0) { memset(edge, 0, sizeof(edge)); }
    } *root;

    Trie() { root = new node(); }

    void insert(string &word)
    {
        node *t = root;
        for (auto ch : word)
        {
            int pos = ch - 'a';
            if (t->full)
                return;
            if (!t->edge[pos])
                t->edge[pos] = new node();
            t = t->edge[pos];
        }

        t->full++;
    }

    int replace_successor(string &s, int i, node *t)
    {
        int len = s.length();
        for (; i < len; ++i)
        {
            if (t->full || s[i] == ' ')
                return i;

            int pos = s[i] - 'a';
            if (!t->edge[pos])
            {
                while (i < len && s[i] != ' ')
                    ++i;
                return i;
            }
            t = t->edge[pos];
        }
        return i;
    }

    int replace_successor(string sentence, int index)
    {
        return replace_successor(sentence, index, root);
    }
};

class Solution
{
private:
    Trie trie;

public:
    string replaceWords(vector<string> &dictionary, string sentence)
    {
        for (auto &word : dictionary)
            trie.insert(word);

        int i = 0;
        string ans = "";
        int len = sentence.length();
        for (int i = 0; i < len;)
        {
            if (sentence[i] == ' ')
                ans += sentence[i++];
            int j = trie.replace_successor(sentence, i);
            ans += sentence.substr(i, j - i);
            for (i = j; i < len && sentence[i] != ' '; ++i)
                ;
        }

        return ans;
    }
};