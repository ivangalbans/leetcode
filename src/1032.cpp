// https://leetcode.com/problems/stream-of-characters/description/

// O(QW)

struct Trie
{
    struct node
    {
        bool full;
        node *edge[26];
        node() : full(false) { memset(edge, 0, sizeof(edge)); }

    } *root;

    Trie() { root = new node(); }

    void insert(string &w)
    {
        node *t = root;
        for (int i = w.size() - 1; i >= 0; --i)
        {
            int pos = w[i] - 'a';
            if (!t->edge[pos])
                t->edge[pos] = new node();
            t = t->edge[pos];
        }
        t->full = true;
    }

    bool search(vector<char> &stream)
    {
        node *t = root;
        for (int i = stream.size() - 1; i >= 0; --i)
        {
            int pos = stream[i] - 'a';
            if (!t->edge[pos])
                return false;
            t = t->edge[pos];
            if (t->full)
                return true;
        }
        return false;
    }
};

class StreamChecker
{
private:
    vector<char> stream;
    Trie trie;

public:
    StreamChecker(vector<string> &words)
    {
        for (auto &w : words)
            trie.insert(w);
    }

    bool query(char letter)
    {
        stream.push_back(letter);
        return trie.search(stream);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */

// O(NQ)

struct Trie
{
    struct node
    {
        bool full;
        node *edge[26];
        node() : full(false) { memset(edge, 0, sizeof(edge)); }

    } *root;

    vector<node *> matches;

    Trie()
    {
        root = new node();
        matches = {root};
    }

    void insert(string &w)
    {
        node *t = root;
        for (auto ch : w)
        {
            int pos = ch - 'a';
            if (!t->edge[pos])
                t->edge[pos] = new node();
            t = t->edge[pos];
        }
        t->full = true;
    }

    bool move_next(char ch)
    {
        bool check = false;
        int pos = ch - 'a';
        vector<node *> new_matches = {root};
        for (auto t : matches)
        {
            if (t->edge[pos])
            {
                check |= (t->edge[pos]->full);
                new_matches.push_back(t->edge[pos]);
            }
        }
        matches = new_matches;
        return check;
    }
};

class StreamChecker
{
private:
    vector<char> stream;
    Trie trie;

public:
    StreamChecker(vector<string> &words)
    {
        for (auto &w : words)
            trie.insert(w);
    }

    bool query(char letter)
    {
        return trie.move_next(letter);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */