// https://leetcode.com/problems/simplify-path/description/

class Solution
{
public:
    string simplifyPath(string path)
    {
        int n = path.length();

        stack<string> st;
        for (int i = 0; i < n; ++i)
        {
            if (path[i] == '/')
                continue;

            string token = "";
            while (i < n && path[i] != '/')
            {
                token += path[i];
                ++i;
            }

            if (token == ".")
            {
                continue;
            }
            else if (token == "..")
            {
                if (!st.empty())
                    st.pop();
            }
            else
            {
                st.push(token);
            }
        }

        string canonical_path = "";
        while (!st.empty())
        {
            canonical_path = "/" + st.top() + canonical_path;
            st.pop();
        }

        if (canonical_path.length() == 0)
            return "/";

        return canonical_path;
    }
};