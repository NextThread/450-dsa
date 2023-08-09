class Solution
{
public:
    int dp[1101][1101];
    int f(int i, int j, string &s, unordered_set<string> &h)
    {
        if (h.find(s.substr(i, j - i + 1)) != h.end())
            return 1;
        else if (i == j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int res = 0;
        for (int k = i; k < j; k++)
        {
            res = res || (f(i, k, s, h) && f(k + 1, j, s, h));
        }

        return dp[i][j] = res;
    }
    int wordBreak(string A, vector<string> &B)
    {
        int n = A.size();
        unordered_set<string> h;

        for (int i = 0; i < B.size(); i++)
            h.insert(B[i]);

        memset(dp, -1, sizeof(dp));
        return f(0, n - 1, A, h);
    }
};

/* most optimized solution*/
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<bool> dp(s.size(), 0);
        dp[0] = true;
        for (int i = 0; i <= s.size(); i++)
        {
            for (auto str : wordDict)
            {
                if (dp[i])
                {
                    if (s.substr(i, str.size()).compare(str) == 0)
                    {
                        dp[i + str.size()] = true;
                    }
                }
            }
        }
        return dp[s.size()];
    }
};