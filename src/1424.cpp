// https://leetcode.com/problems/diagonal-traverse-ii/

class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &nums)
    {
        vector<int> ans;
        vector<pair<int, pair<int, int>>> cells;
        for (int i = 0; i < nums.size(); ++i)
            for (int j = 0; j < nums[i].size(); ++j)
                cells.push_back({i + j, {j, i}});

        sort(begin(cells), end(cells));
        for (auto p : cells)
            ans.push_back(nums[p.second.second][p.second.first]);

        return ans;
    }
};