// https://leetcode.com/problems/most-beautiful-item-for-each-query/description/

// Offline query processing - Sweep
class Solution
{
public:
    vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries)
    {
        int n = items.size();
        int q = queries.size();

        vector<pair<int, int>> queriesPair(q);
        for (int i = 0; i < q; ++i)
            queriesPair[i] = {queries[i], i};

        sort(begin(items), end(items));
        sort(begin(queriesPair), end(queriesPair));

        vector<int> ans(q);
        int index = 0, best = 0;

        for (auto queryPair : queriesPair)
        {
            int price = queryPair.first, queryIndex = queryPair.second;
            while (index < n && items[index][0] <= price)
            {
                best = max(best, items[index][1]);
                ++index;
            }
            ans[queryIndex] = best;
        }

        return ans;
    }
};

// Binary Search - upper_bound

class Solution
{
public:
    vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries)
    {
        const int oo = INT_MAX;
        int n = items.size();
        sort(begin(items), end(items));

        vector<pair<int, int>> itemsPair(n);
        int best = 0;
        for (int i = 0; i < n; ++i)
        {
            best = max(best, items[i][1]);
            itemsPair[i] = {items[i][0], best};
        }

        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); ++i)
        {
            auto index = upper_bound(begin(itemsPair), end(itemsPair), pair<int, int>{queries[i], oo}) - begin(itemsPair);

            if (index == 0)
                ans[i] = 0;
            else
                ans[i] = itemsPair[index - 1].second;
        }

        return ans;
    }
};