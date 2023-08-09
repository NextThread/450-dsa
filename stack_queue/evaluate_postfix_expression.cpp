class Solution
{
public:
    int evaluatePostfix(string S) //  reverse polish notation(RPN)
    {
        stack<int> st;
        int i = 0;
        while (i < S.length())
        {
            if (S[i] >= '0' and S[i] <= '9')
                st.push(S[i] - '0');
            else
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                if (S[i] == '*')
                    st.push(a * b);
                else if (S[i] == '+')
                    st.push(a + b);
                else if (S[i] == '/')
                    st.push(b / a);
                else if (S[i] == '-')
                    st.push(b - a);
            }
            i++;
        }
        return st.top();
    }
};