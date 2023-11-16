// https://leetcode.com/problems/design-add-and-search-words-data-structure/description/

struct Trie
{
    struct node
    {
        int full;
        node *edge[26];

        node() : full(0) { memset(edge, 0, sizeof(edge)); }
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
        }
        t->full++;
    }

    bool search(string regex, node *t)
    {
        for (int i = 0; i < regex.length(); ++i)
        {
            char ch = regex[i];
            if (ch == '.')
            {
                for (int pos = 0; pos < 26; ++pos)
                    if (t->edge[pos] && search(regex.substr(i + 1, regex.length() - i - 1), t->edge[pos]))
                        return true;
                return false;
            }
            else
            {
                if (!t->edge[ch - 'a'])
                    return false;
                t = t->edge[ch - 'a'];
            }
        }
        return t->full;
    }

    bool search(string regex)
    {
        return search(regex, root);
    }
};

class WordDictionary
{
private:
    Trie trie;

public:
    WordDictionary()
    {
    }

    void addWord(string word)
    {
        trie.insert(word);
    }

    bool search(string word)
    {
        return trie.search(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */