// https://leetcode.com/problems/group-shifted-strings/description/

class Solution
{
public:
    string hash(string &s)
    {
        int n = s.length();
        string id = "";
        int offset = s[0] - 'a';
        for (int i = 0; i < n; ++i)
        {
            char ch = s[i] - offset;
            if (ch < 'a')
                ch += 26;
            id += ch;
        }
        return id;
    }

    vector<vector<string>> groupStrings(vector<string> &strings)
    {
        unordered_map<string, vector<string>> mp;

        for (auto s : strings)
        {
            string id = hash(s);
            mp[id].push_back(s);
        }

        vector<vector<string>> groups;
        for (auto [id, v] : mp)
            groups.push_back(v);

        return groups;
    }
};