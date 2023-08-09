class Solution
{
public:
    int dp[1001][1001];

    bool solve(string A, string B, string C, int alen, int blen, int clen)
    {
        if (clen == 0)
            return 1;

        if (dp[alen][blen] != -1)
            return dp[alen][blen];

        int op1 = 0, op2 = 0;

        if (alen - 1 >= 0 && A[alen - 1] == C[clen - 1])
            op1 = solve(A, B, C, alen - 1, blen, clen - 1);

        if (blen - 1 >= 0 && B[blen - 1] == C[clen - 1])
            op2 = solve(A, B, C, alen, blen - 1, clen - 1);

        return dp[alen][blen] = op1 or op2;
    }

    bool isInterleave(string A, string B, string C)
    {
        int alen = A.length(), blen = B.length(), clen = C.length();
        if (alen + blen != clen)
            return 0;

        memset(dp, -1, sizeof(dp));
        return solve(A, B, C, alen, blen, clen);
    }
};