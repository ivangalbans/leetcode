// https://leetcode.com/problems/range-sum-query-2d-immutable/

class NumMatrix
{
private:
    vector<vector<int>> cum_sum;

public:
    NumMatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        cum_sum = vector<vector<int>>(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
                cum_sum[i][j] = matrix[i - 1][j - 1] + cum_sum[i][j - 1] + cum_sum[i - 1][j] - cum_sum[i - 1][j - 1];
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        ++row1;
        ++col1;
        ++row2;
        ++col2;
        return cum_sum[row2][col2] - cum_sum[row1 - 1][col2] - cum_sum[row2][col1 - 1] + cum_sum[row1 - 1][col1 - 1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */