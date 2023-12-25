// https://leetcode.com/problems/maximum-square-area-by-removing-fences-from-a-field/description/

class Solution
{
public:
    const int MOD = 1e9 + 7;
    int maximizeSquareArea(int m, int n, vector<int> &h, vector<int> &v)
    {
        vector<long long> hor = {m - 1}, ver = {n - 1};
        for (auto x1 : h)
        {
            hor.push_back(x1 - 1);
            hor.push_back(m - x1);
            for (auto x2 : h)
            {
                if (x1 != x2)
                {
                    hor.push_back(abs(x1 - x2));
                }
            }
        }

        for (auto x1 : v)
        {
            ver.push_back(x1 - 1);
            ver.push_back(n - x1);
            for (auto x2 : v)
            {
                if (x1 != x2)
                {
                    ver.push_back(abs(x1 - x2));
                }
            }
        }

        sort(begin(hor), end(hor));
        sort(begin(ver), end(ver));

        int i = hor.size() - 1;
        int j = ver.size() - 1;
        while (i >= 0 && j >= 0)
        {
            if (hor[i] == ver[j])
                return hor[i] * hor[i] % MOD;
            if (hor[i] > ver[j])
                i--;
            else if (hor[i] < ver[j])
                j--;
        }
        return -1;
    }
};