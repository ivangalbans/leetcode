// https://leetcode.com/problems/maximum-balanced-subsequence-sum/description/

class FenwickTree
{
private:
    vector<long long> ft;

    int lowbit(int x)
    {
        return x & -x;
    }

public:
    FenwickTree(int n)
    {
        ft = vector<long long>(n + 1);
    }

    void update(int pos, long long val)
    {
        for (; pos < ft.size(); pos += lowbit(pos))
            ft[pos] = max(ft[pos], val);
    }

    long long query(int pos)
    {
        long long ans = INT_MIN;
        for (; pos > 0; pos -= lowbit(pos))
            ans = max(ans, ft[pos]);
        return ans;
    }
};

class Solution
{
public:
    long long maxBalancedSubsequenceSum(vector<int> &nums)
    {
        int n = nums.size();

        set<int> s;
        for (int i = 0; i < n; ++i)
            s.insert(nums[i] - i);

        unordered_map<int, int> rank;
        int len = 0;
        for (auto x : s)
            rank[x] = ++len;

        vector<long long> dp(n);
        FenwickTree ft(len);
        for (int i = 0; i < n; ++i)
        {
            long long prev_best = ft.query(rank[nums[i] - i]);
            dp[i] = max((long long)nums[i], nums[i] + prev_best);
            if (dp[i] > prev_best)
                ft.update(rank[nums[i] - i], dp[i]);
        }

        return *max_element(begin(dp), end(dp));
    }
};