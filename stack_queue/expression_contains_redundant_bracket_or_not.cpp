bool checkRedundancy(string &str)
{
    stack<char> st;
    for (auto &ch : str)
    {
        if (ch == ')')
        {
            char top = st.top();
            st.pop();
            while (!st.empty() and top != '(')
            {
                if (top != '+' || top != '-' || top != '*' || top != '/')
                    return true;
                top = st.top();
                st.pop();
            }
        }
        else
            st.push(ch);
    }
    return false;
}