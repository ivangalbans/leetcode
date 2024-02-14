// https://leetcode.com/problems/random-pick-with-weight/description/

class Solution
{
private:
    vector<double> buckets;
    uniform_real_distribution<double> unif;
    default_random_engine re;
    int n;

public:
    Solution(vector<int> &w)
    {
        n = w.size();
        unif = uniform_real_distribution<double>(0, 1);
        int sum = accumulate(begin(w), end(w), 0);

        vector<double> prob(n);
        for (int i = 0; i < n; ++i)
            prob[i] = (double)w[i] / sum;

        buckets = vector<double>(n);
        buckets[0] = prob[0];
        for (int i = 1; i < n; ++i)
            buckets[i] = buckets[i - 1] + prob[i];
    }

    int pickIndex()
    {
        return lower_bound(begin(buckets), end(buckets), unif(re)) - begin(buckets);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

// Discrete version

class Solution
{
private:
    vector<int> buckets;
    int n;

public:
    Solution(vector<int> &w)
    {
        n = w.size();
        buckets = vector<int>(n);
        buckets[0] = w[0];
        for (int i = 1; i < n; ++i)
            buckets[i] = buckets[i - 1] + w[i];
    }

    int pickIndex()
    {
        return upper_bound(begin(buckets), end(buckets), rand() % buckets.back()) - begin(buckets);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */