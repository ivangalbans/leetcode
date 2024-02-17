//

class Solution
{
public:
    int calculate(queue<char> &tokens)
    {
        stack<int> st;
        int num = 0;
        char op = '+';

        while (!tokens.empty())
        {
            char token = tokens.front();
            tokens.pop();

            if (isdigit(token))
            {
                num = num * 10 + (token - '0');
            }
            else if (token == '(')
            {
                num = calculate(tokens);
            }
            else
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
                    cout << "Unexpected token: " << token;
                }

                op = token;
                num = 0;
                if (token == ')')
                {
                    break;
                }
            }
        }

        int result = 0;
        while (!st.empty())
        {
            result += st.top();
            st.pop();
        }

        return result;
    }

    int calculate(string s)
    {
        queue<char> tokens;

        for (auto token : s)
            if (token != ' ')
                tokens.push(token);

        tokens.push('+');
        return calculate(tokens);
    }
};