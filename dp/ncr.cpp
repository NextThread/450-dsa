class Solution{
public:
    int nCr(int n, int r) {
        int dp[1001][1001];
        memset(dp, 0, sizeof(dp));
        int mod = 1e9+7;
        for(int i = 0 ; i < 1000 ; i++) dp[i][0] = 1;
        dp[0][1] = 1;
        for(int i = 1 ; i < n ; i++)
        {
            for(int j = 1 ; j < 801 ; j++)
            {
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%mod;
            }
        }
        return dp[n-1][r]%mod;
    }
};