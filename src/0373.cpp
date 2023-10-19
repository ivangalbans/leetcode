// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/

typedef pair<int, int> pii;

class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> ans;

        priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
        pq.push(make_pair(nums1[0] + nums2[0], make_pair(0, 0)));

        while (!pq.empty() && k--)
        {
            int i = pq.top().second.first, j = pq.top().second.second;
            pq.pop();
            ans.push_back({nums1[i], nums2[j]});
            if (i < n - 1 && j == 0)
                pq.push(make_pair(nums1[i + 1] + nums2[0], make_pair(i + 1, 0)));
            if (j < m - 1)
                pq.push(make_pair(nums1[i] + nums2[j + 1], make_pair(i, j + 1)));
        }

        return ans;
    }
};