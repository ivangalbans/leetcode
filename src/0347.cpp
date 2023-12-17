// https://leetcode.com/problems/top-k-frequent-elements/

// O (k*log(n))

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        vector<int> ans(k);

        unordered_map<int, int> occ;
        for (auto x : nums)
            occ[x]++;

        priority_queue<pair<int, int>> heap;
        for (const auto &[num, cnt] : occ)
            heap.push({cnt, num});

        for (int i = 0; i < k; ++i)
        {
            ans[i] = heap.top().second;
            heap.pop();
        }

        return ans;
    }
};

// O(n)

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        int n = nums.size();

        unordered_map<int, int> occ;
        for (auto x : nums)
            occ[x]++;

        vector<vector<int>> freq(n + 1); // freq[i] = [x, y..] => [x, y..] appears i times
        for (const auto &[num, cnt] : occ)
            freq[cnt].push_back(num);

        vector<int> ans(k);
        int index = 0;
        for (int i = n; i > 0 && index < k; --i)
            for (int j = 0; j < freq[i].size() && index < k; ++j)
                ans[index++] = freq[i][j];

        return ans;
    }
};