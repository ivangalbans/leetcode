// https://leetcode.com/problems/form-array-by-concatenating-subarrays-of-another-array/description/

// KMP

class Solution
{
public:
    vector<int> compute_pi(vector<int> &p)
    {
        int m = p.size();
        vector<int> pi(m + 1, -1);
        for (int i = 1, j = -1; i <= m; ++i)
        {
            while (j >= 0 && p[j] != p[i - 1])
                j = pi[j];
            pi[i] = ++j;
        }
        return pi;
    }

    int kmp(int index, vector<int> &t, vector<int> &p)
    {
        int n = t.size(), m = p.size();
        auto pi = compute_pi(p);

        for (int i = index, k = 0; i < n; ++i)
        {
            while (k >= 0 && p[k] != t[i])
                k = pi[k];
            if (++k >= m)
                return i - m + 1;
        }

        return -1;
    }

    bool canChoose(vector<vector<int>> &groups, vector<int> &nums)
    {
        int index = 0;
        for (auto group : groups)
        {
            index = kmp(index, nums, group);
            if (index == -1)
                return false;
            index += group.size();
        }
        return true;
    }
};