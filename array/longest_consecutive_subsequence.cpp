class Solution
{
public:
    int findLongestConseqSubseq(int arr[], int N)
    {
        set<int> st;
        int mx = -1;
        for (int i = 0; i < N; i++)
        {
            mx = max(mx, arr[i]);
            st.insert(arr[i]);
        }
        int res = 0, ind = 0;
        for (int i = 1; i <= mx; i++)
        {
            if (st.count(i))
            {
                ind++;
                res = max(res, ind);
            }
            else
                ind = 0;
        }
        return res;
    }
};