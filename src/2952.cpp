// https://leetcode.com/problems/minimum-number-of-coins-to-be-added/description/

class Solution
{
public:
    int minimumAddedCoins(vector<int> &coins, int target)
    {
        int n = coins.size();

        sort(begin(coins), end(coins));

        int x = 0, i = 0, ans = 0;
        while (x < target)
        {
            if (i < n && coins[i] <= x + 1)
            {
                x += coins[i];
                ++i;
            }
            else
            {
                x = 2 * x + 1;
                ++ans;
            }
        }

        return ans;
    }
};