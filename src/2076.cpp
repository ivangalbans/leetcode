// https://leetcode.com/problems/process-restricted-friend-requests/description/

struct disjoint_set
{
    vector<int> parent, count;
    disjoint_set(int n)
    {
        parent = vector<int>(n);
        count = vector<int>(n);

        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
            count[i] = 1;
        }
    }

    int set_of(int x)
    {
        return x == parent[x] ? x : parent[x] = set_of(parent[x]);
    }

    void merge(int x, int y)
    {
        x = set_of(x);
        y = set_of(y);

        if (x == y)
            return;

        if (count[x] < count[y])
            swap(x, y);

        parent[y] = x;
        count[x] += count[y];
    }
};

class Solution
{
public:
    bool make_friends(int a, int b, vector<vector<int>> &res, disjoint_set &ds)
    {
        a = ds.set_of(a);
        b = ds.set_of(b);

        if (a == b)
            return true;

        for (auto r : res)
        {
            int r1 = ds.set_of(r[0]);
            int r2 = ds.set_of(r[1]);
            if ((a == r1 && b == r2) || (a == r2 && b == r1))
                return false;
        }

        ds.merge(a, b);

        return true;
    }

    vector<bool> friendRequests(int n, vector<vector<int>> &restrictions, vector<vector<int>> &requests)
    {
        int nrequests = requests.size();
        disjoint_set ds(n);
        vector<bool> ans(nrequests);

        for (int i = 0; i < nrequests; ++i)
        {
            int a = requests[i][0], b = requests[i][1];
            ans[i] = make_friends(a, b, restrictions, ds);
        }

        return ans;
    }
};