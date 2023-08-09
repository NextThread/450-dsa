
int f(int i, int j, int k, string a, string b, string c, vector<vector<vector<int>>> &dp)
{
    if (i >= a.length() or j >= b.length() or k >= c.length())
        return 0;
    if (dp[i][j][k] != -1)
        return dp[i][j][k];
    if (a[i] == b[j] && b[j] == c[k])
    {
        return dp[i][j][k] = 1 + f(i + 1, j + 1, k + 1, a, b, c, dp);
    }
    int op1 = f(i + 1, j, k, a, b, c, dp);
    int op2 = f(i, j + 1, k, a, b, c, dp);
    int op3 = f(i, j, k + 1, a, b, c, dp);
    return dp[i][j][k] = max(op1, max(op2, op3));
}

int LCSof3(string A, string B, string C, int n1, int n2, int n3)
{
    vector<vector<vector<int>>> dp(A.length() + 1, vector<vector<int>>(B.length() + 1, vector<int>(C.length() + 1, -1)));
    return f(0, 0, 0, A, B, C, dp);
}