// https://leetcode.com/problems/spiral-matrix-ii/description/

class Solution
{
public:
    vector<vector<int>> rotateRight(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> rotated(n, vector<int>(m));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                rotated[j][m - 1 - i] = matrix[i][j];

        return rotated;
    }

    vector<vector<int>> generateMatrix(int n)
    {
        int c = n * n;
        vector<vector<int>> m = {{c--}};
        while (c)
        {
            m = rotateRight(m);
            m.insert(m.begin(), vector<int>(m[0].size()));
            for (int i = m[0].size() - 1; i >= 0; --i)
                m[0][i] = c--;
        }

        return m;
    }
};