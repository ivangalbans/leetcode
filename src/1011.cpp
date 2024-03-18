// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

class Solution
{
public:
    bool shipWithinDays(vector<int> &weights, int days, int w)
    {
        int sum = 0;
        int needed = 1;
        for (int i = 0; i < weights.size(); ++i)
        {
            if (sum + weights[i] > w)
            {
                sum = weights[i];
                needed++;
            }
            else
                sum += weights[i];
        }

        return needed <= days;
    }

    int shipWithinDays(vector<int> &weights, int days)
    {
        int lo = *max_element(begin(weights), end(weights)), hi = 25000000;
        int ans;
        while (lo < hi)
        {
            int mid = (lo + hi) / 2;
            if (!shipWithinDays(weights, days, mid))
                lo = mid + 1;
            else
                hi = mid;
        }
        return lo;
    }
};