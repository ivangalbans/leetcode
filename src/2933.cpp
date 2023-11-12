// https://leetcode.com/problems/high-access-employees/description/

class Solution
{
public:
    int toMinute(string t)
    {
        int h = (t[0] - '0') * 10 + (t[1] - '0');
        int m = (t[2] - '0') * 10 + (t[3] - '0');

        return h * 60 + m;
    }

    bool solve(vector<int> &access)
    {
        sort(begin(access), end(access));

        for (int i = 2; i < access.size(); ++i)
            if (access[i] - access[i - 2] < 60)
                return true;
        return false;
    }

    vector<string> findHighAccessEmployees(vector<vector<string>> &access_times)
    {
        map<string, vector<int>> emp;
        for (auto item : access_times)
        {
            string name = item[0];
            string access = item[1];
            emp[name].push_back(toMinute(access));
        }

        vector<string> ans;
        for (auto item : emp)
        {
            string name = item.first;
            vector<int> access = item.second;
            if (solve(access))
                ans.push_back(name);
        }

        return ans;
    }
};