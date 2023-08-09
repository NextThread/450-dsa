class Solution
{
public:
    int dp[1101][1101];
    int f(string &A, int i, int j, set<string> &st)
    {
        if (st.find(A.substr(i, j - i + 1)) != st.end())
            return 1;
        else if (i == j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int res = 0;
        for (int k = i; k < j; k++)
            res = res || (f(A, i, k, st) && f(A, k + 1, j, st));
        return dp[i][j] = res;
    }
    int wordBreak(string A, vector<string> &B)
    {
        set<string> st;
        int n = A.length();
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < B.size(); i++)
            st.insert(B[i]);
        return f(A, 0, n - 1, st);
    }
};