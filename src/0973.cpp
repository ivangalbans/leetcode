// https://leetcode.com/problems/k-closest-points-to-origin/

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<pair<int, pair<int, int>>> pq;
        for (auto &point : points)
        {
            auto [x, y] = make_pair(point[0], point[1]);
            pq.push({(x * x + y * y), {x, y}});
            if (pq.size() == k + 1)
                pq.pop();
        }

        vector<vector<int>> ans;
        while (!pq.empty())
        {
            auto [x, y] = pq.top().second;
            ans.push_back({x, y});
            pq.pop();
        }

        return ans;
    }
};