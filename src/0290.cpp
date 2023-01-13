// https://leetcode.com/problems/word-pattern/

class Solution
{
public:
    string removeDuplicates(string s)
    {
        stack<char> st;

        for (auto x : s)
        {
            if (!st.empty() && st.top() == x)
                st.pop();
            else
                st.push(x);
        }

        vector<char> ansv;
        while (!st.empty())
        {
            ansv.push_back(st.top());
            st.pop();
        }

        return string(rbegin(ansv), rend(ansv));
    }
};