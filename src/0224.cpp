// https://leetcode.com/problems/basic-calculator/description/

class Solution
{
public:
    int calculate(string s)
    {
        int result = 0;
        int sign = 1;
        int num = 0;
        stack<int> st;
        for (auto ch : s)
        {
            if (ch == ' ')
                continue;
            if (isdigit(ch))
            {
                num = num * 10 + (ch - '0');
            }
            else
            {
                if (ch == '+' || ch == '-')
                {
                    result += sign * num;
                    num = 0;
                    sign = (ch == '+' ? 1 : -1);
                }
                else if (ch == '(')
                {
                    st.push(result);
                    st.push(sign);
                    sign = 1;
                    result = 0;
                }
                else if (ch == ')')
                {
                    result += sign * num;
                    result = st.top() * result;
                    st.pop();
                    result += st.top();
                    st.pop();
                    num = 0;
                }
                else
                {
                    cout << "Unexpexted token: " << ch << endl;
                }
            }
        }

        if (num != 0)
            result += sign * num;

        return result;
    }
};