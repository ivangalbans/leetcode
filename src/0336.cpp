// https://leetcode.com/problems/palindrome-pairs/description/

// HashMap

class Solution
{
private:
    unordered_map<string, int> id;

    bool is_palindrome(string s)
    {
        int n = s.length();
        for (int i = 0; i < n / 2; ++i)
            if (s[i] != s[n - 1 - i])
                return false;
        return true;
    }

    string reverse_str(string s)
    {
        reverse(s.begin(), s.end());
        return s;
    }

public:
    vector<vector<int>> palindromePairs(vector<string> &words)
    {
        int n = words.size();

        for (int i = 0; i < n; ++i)
            id[words[i]] = i;

        vector<vector<int>> ans;

        // case 1: s1 = ""
        if (id.count(""))
        {
            string s1 = "";
            int id1 = id[s1];
            for (int i = 0; i < n; ++i)
            {
                string s2 = words[i];
                if (is_palindrome(s2) && id1 != i)
                {
                    ans.push_back({id1, i});
                    ans.push_back({i, id1});
                }
            }
        }

        // case 2: s2 = rev(s1)
        for (int i = 0; i < n; ++i)
        {
            string s1 = words[i];
            string s2 = reverse_str(s1);
            if (id.count(s2))
            {
                int id2 = id[s2];
                if (id2 != i)
                    ans.push_back({i, id[s2]});
            }
        }

        // case 3: s1[0:c] is pal & s2=rev(s1[c+1:]) => s2+s1 is pal
        // case 4: s1[c+1:] is pal & s2=rev(s1[0:c]) => s1+s2 is pal
        for (int i = 0; i < n; ++i)
        {
            string s1 = words[i];
            for (int c = 1; c < s1.length(); ++c)
            {
                if (is_palindrome(s1.substr(0, c)))
                {
                    string s2 = reverse_str(s1.substr(c));
                    if (id.count(s2))
                    {
                        int id2 = id[s2];
                        if (id2 != i)
                            ans.push_back({id[s2], i});
                    }
                }
                if (is_palindrome(s1.substr(c)))
                {
                    string s2 = reverse_str(s1.substr(0, c));
                    if (id.count(s2))
                    {
                        int id2 = id[s2];
                        if (id2 != i)
                            ans.push_back({i, id[s2]});
                    }
                }
            }
        }

        return ans;
    }
};

// Trie

bool is_palindrome(string &s, int i, int j)
{
    while (i < j)
        if (s[i++] != s[j--])
            return false;
    return true;
}

struct Trie
{
    struct node
    {
        int id;
        vector<int> pal_ids;
        node *edge[26];

        node() : id(-1) { memset(edge, 0, sizeof(edge)); }
    } *root;

    Trie() { root = new node(); }

    void insert(string &s, int id)
    {
        node *t = root;

        for (int i = s.length() - 1; i >= 0; --i)
        {
            int pos = s[i] - 'a';
            if (!t->edge[pos])
                t->edge[pos] = new node();
            if (is_palindrome(s, 0, i))
                t->pal_ids.push_back(id);

            t = t->edge[pos];
        }

        t->pal_ids.push_back(id);
        t->id = id;
    }

    void search(string &s, int id, vector<vector<int>> &ans)
    {
        node *t = root;

        for (int i = 0; i < s.length(); ++i)
        {
            int pos = s[i] - 'a';

            if (t->id >= 0 && t->id != id && is_palindrome(s, i, s.length() - 1))
                ans.push_back({id, t->id});

            if (!t->edge[pos])
                return;

            t = t->edge[pos];
        }

        for (auto pal_id : t->pal_ids)
            if (pal_id != id)
                ans.push_back({id, pal_id});
    }
};

class Solution
{
private:
    Trie trie;

public:
    vector<vector<int>> palindromePairs(vector<string> &words)
    {
        int n = words.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n; ++i)
            trie.insert(words[i], i);
        for (int i = 0; i < n; ++i)
            trie.search(words[i], i, ans);

        return ans;
    }
};