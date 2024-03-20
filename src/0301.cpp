// https://leetcode.com/problems/remove-invalid-parentheses/description/

class Solution
{
public:
    vector<string> removeInvalidParentheses(string s)
    {
        vector<string> valid_parenthesis;
        unordered_set<string> visited;
        queue<string> q;

        q.push(s);
        while (!q.empty())
        {
            string t = q.front();
            q.pop();
            if (isValid(t))
                valid_parenthesis.push_back(t);

            if (!valid_parenthesis.empty())
                continue;

            for (int i = 0; i < t.length(); ++i)
            {
                if (t[i] != '(' && t[i] != ')')
                    continue;
                string newS = t.substr(0, i) + t.substr(i + 1);
                if (!visited.count(newS))
                {
                    visited.insert(newS);
                    q.push(newS);
                }
            }
        }

        return valid_parenthesis;
    }

    bool isValid(string &s)
    {
        int counter = 0;
        for (int i = 0; i < s.length(); ++i)
        {

            if (s[i] == '(')
                ++counter;
            else if (s[i] == ')')
                --counter;
            if (counter < 0)
                return false;
        }

        return counter == 0;
    }
};