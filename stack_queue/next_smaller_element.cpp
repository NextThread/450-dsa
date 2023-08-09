class Solution
{
public:
    vector<long long> nextSmallerElement(vector<long long> &arr, int n)
    {
        vector<long long> res(n, 0);
        stack<long long> st;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() and st.top() >= arr[i])
            {
                st.pop();
            }
            if (st.empty())
                res[i] = -1;
            else
                res[i] = st.top();
            st.push(arr[i]);
        }
        return res;
    }
};