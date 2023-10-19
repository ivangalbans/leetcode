// https://leetcode.com/problems/koko-eating-bananas/

class Solution
{
public:
    bool can_eat_all(vector<int> &piles, int h, int k)
    {
        int c = 0;
        for (auto &pile : piles)
            c += (pile / k) + ((pile % k) == 0 ? 0 : 1);
        return c <= h;
    }

    int minEatingSpeed(vector<int> &piles, int h)
    {
        int lo = 1, hi = INT_MAX;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (can_eat_all(piles, h, mid) == false)
                lo = mid + 1;
            else
                hi = mid - 1;
        }

        return lo;
    }
};