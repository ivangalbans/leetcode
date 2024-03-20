// https://leetcode.com/problems/design-tic-tac-toe/description/

class TicTacToe
{
private:
    int n;
    vector<pair<int, int>> rows, cols;
    pair<int, int> d1, d2;

public:
    TicTacToe(int n) : n(n)
    {
        rows = vector<pair<int, int>>(n);
        cols = vector<pair<int, int>>(n);
    }

    void update(int pos, vector<pair<int, int>> &v, int player)
    {
        if (v[pos].first == 0)
            v[pos] = {player, 1};
        else if (v[pos].first == player)
            ++v[pos].second;
        else
            v[pos] = {-1, -1};
    }

    void update_diagonal(pair<int, int> &d, int player)
    {
        if (d.first == 0)
            d = {player, 1};
        else if (d.first == player)
            ++d.second;
        else
            d = {-1, -1};
    }

    int move(int row, int col, int player)
    {
        update(row, rows, player);
        update(col, cols, player);

        if (row == col)
            update_diagonal(d1, player);
        if (row + col == n - 1)
            update_diagonal(d2, player);

        if (rows[row].second == n || cols[col].second == n || d1.second == n || d2.second == n)
            return player;
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */