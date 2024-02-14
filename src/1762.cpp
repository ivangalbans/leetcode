// https://leetcode.com/problems/buildings-with-an-ocean-view/

class Solution
{
public:
    vector<int> findBuildings(vector<int> &heights)
    {
        int n = heights.size();
        int taller = heights.back();
        vector<bool> ocean(n);
        ocean[n - 1] = true;
        for (int i = n - 2; i >= 0; --i)
        {
            if (heights[i] > taller)
            {
                taller = heights[i];
                ocean[i] = true;
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; ++i)
            if (ocean[i])
                ans.push_back(i);

        return ans;
    }
};