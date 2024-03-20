// https://leetcode.com/problems/best-meeting-point/description/

class Solution
{
private:
    int dist_median(vector<int> &nums)
    {
        int dist = 0;
        for (int i = 0, j = nums.size() - 1; i < j; ++i, --j)
            dist += (nums[j] - nums[i]);
        return dist;
    }

public:
    int minTotalDistance(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<int> rows, cols;

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j])
                    rows.push_back(i);

        for (int j = 0; j < n; ++j)
            for (int i = 0; i < m; ++i)
                if (grid[i][j])
                    cols.push_back(j);

        return dist_median(rows) + dist_median(cols);
    }
};