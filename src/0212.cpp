// https://leetcode.com/problems/word-search-ii/description/

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

    bool contains(string word)
    {
        node *t = root;
        for (auto ch : word)
        {
            int pos = ch - 'a';
            if (!t->edge[pos])
                return false;
            t = t->edge[pos];
        }
        return t->full;
    }
};

class Solution
{
private:
    Trie trie;

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    bool visited[12][12];

    bool inside(int i, int j, int m, int n)
    {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    void dfs(int i, int j, string word, vector<vector<char>> &board)
    {
        trie.insert(word);

        if (word.length() == 10)
            return;

        visited[i][j] = true;
        for (int k = 0; k < 4; ++k)
        {
            int x = i + dx[k];
            int y = j + dy[k];
            if (inside(x, y, board.size(), board[0].size()) && !visited[x][y])
                dfs(x, y, word + board[x][y], board);
        }
        visited[i][j] = false;
    }

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                memset(visited, false, sizeof(visited));
                dfs(i, j, string(1, board[i][j]), board);
            }
        }

        vector<string> ans;
        for (auto word : words)
            if (trie.contains(word))
                ans.push_back(word);

        return ans;
    }
};