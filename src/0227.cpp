// https://leetcode.com/problems/basic-calculator-ii/description/

class Solution
{
public:
    int calculate(string s)
    {
        int n = s.length();
        char op = '+';
        int num = 0;
        stack<int> st;
        for (int i = 0; i < n; ++i)
        {
            if (isdigit(s[i]))
            {
                num = num * 10 + (s[i] - '0');
            }
            if ((!isdigit(s[i]) && s[i] != ' ') || i == n - 1)
            {
                if (op == '+')
                {
                    st.push(num);
                }
                else if (op == '-')
                {
                    st.push(-num);
                }
                else if (op == '*')
                {
                    int top = st.top();
                    st.pop();
                    st.push(top * num);
                }
                else if (op == '/')
                {
                    int top = st.top();
                    st.pop();
                    st.push(top / num);
                }
                else
                {
                    cout << "Unexpected operator: " << op << endl;
                }

                num = 0;
                op = s[i];
            }
        }

        int ans = 0;
        while (!st.empty())
        {
            int top = st.top();
            st.pop();
            ans += top;
        }

        return ans;
    }
};