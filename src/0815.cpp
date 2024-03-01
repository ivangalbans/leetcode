// https://leetcode.com/problems/bus-routes/description/

class Solution
{
public:
    int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
    {
        if (source == target)
            return 0;

        vector<vector<int>> stops(100001);
        vector<bool> visited(501);

        for (int i = 0; i < routes.size(); ++i)
            for (auto stop : routes[i])
                stops[stop].push_back(i);

        queue<pair<int, int>> q;
        for (auto bus : stops[source])
        {
            visited[bus] = true;
            for (auto stop : routes[bus])
                q.push({1, stop});
        }

        while (!q.empty())
        {
            auto [nbus, stop] = q.front();
            q.pop();
            if (stop == target)
                return nbus;

            for (auto bus : stops[stop])
            {
                if (!visited[bus])
                {
                    for (auto stop : routes[bus])
                        q.push({nbus + 1, stop});
                    visited[bus] = true;
                }
            }
        }

        return -1;
    }
};