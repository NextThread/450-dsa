class Solution
{
public:
    bool ispar(string x)
    {
        stack<char> st;
        for (int i = 0; i < x.length() - 1; i++)
        {
            if (x[i] == '(')
            {
                if (x[i + 1] == '}' or x[i + 1] == ']')
                    return false;
            }
            if (x[i] == '[')
            {
                if (x[i + 1] == '}' or x[i + 1] == ')')
                    return false;
            }
            if (x[i] == '{')
            {
                if (x[i + 1] == ')' or x[i + 1] == ']')
                    return false;
            }
        }
        for (char ch : x)
        {
            if (ch == '[' or ch == '{' or ch == '(')
                st.push(ch);
            else if (ch == ')' or ch == '}' or ch == ']')
            {
                if (st.empty())
                    return false;
                else if ((st.top() == '[' and ch == ']') or
                         (st.top() == '{' and ch == '}') or
                         (st.top() == '(' and ch == ')'))
                    st.pop();
            }
        }
        return st.empty();
    }
};