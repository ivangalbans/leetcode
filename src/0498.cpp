// https://leetcode.com/problems/diagonal-traverse/description/

class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size();

        vector<int> ans;
        for (int sum = 0; sum <= m - 1 + n - 1; ++sum)
        {
            int ini = 0, step = 1;
            if (sum % 2 == 0)
                ini = sum, step = -1;
            for (int s = ini; s >= 0 && s <= sum; s += step)
            {
                int i = s, j = sum - s;
                if (i >= m || j >= n)
                    continue;
                ans.push_back(mat[i][j]);
            }
        }

        return ans;
    }
};