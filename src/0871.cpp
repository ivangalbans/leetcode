// https://leetcode.com/problems/minimum-number-of-refueling-stops

// DP (N^2)

class Solution
{
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
    {
        int n = stations.size();
        vector<long long> dp(n + 1, startFuel);

        for (int i = 0; i < n; ++i)
            for (int j = i; j >= 0 && dp[j] >= stations[i][0]; --j)
                dp[j + 1] = max(dp[j + 1], dp[j] + stations[i][1]);

        for (int i = 0; i <= n; ++i)
            if (dp[i] >= target)
                return i;

        return -1;
    }
};

// Priority Queue (N*LogN)

class Solution
{
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
    {
        priority_queue<int> pq;
        int cur = startFuel;
        int charges;
        int i = 0;

        for (charges = 0; cur < target; ++charges)
        {
            while (i < stations.size() && cur >= stations[i][0])
                pq.push(stations[i++][1]);

            if (pq.empty())
                return -1;

            cur += pq.top();
            pq.pop();
        }

        return charges;
    }
};