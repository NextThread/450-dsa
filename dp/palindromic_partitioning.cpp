// this will count number of palindrome partition

class Solution
{
public:
    int dp[501][501];
    vector<vector<string>> ans; // to store the partitioning
    bool isPalin(string &s, int i, int j)
    {
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int f(string &s, int i, int j)
    {
        if (i >= j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (isPalin(s, i, j))
            return 0;
        int res = INT_MAX;
        for (int k = i; k < j; k++)
        {
            res = min(res, f(s, i, k) + f(s, k + 1, j) + 1);
        }
        if (res != INT_MAX)
            ans.push_back({s.substr(i, j - i + 1)}); // storing the partitioned string
        return dp[i][j] = res;
    }
    int palindromicPartition(string str)
    {
        memset(dp, -1, sizeof(dp));
        return f(str, 0, str.length() - 1);
    }
};

// print the palindromes also

class Solution
{
public:
    bool isPalindrome(string s, int i, int j)
    {
        while (i < j)
        {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }
    void solve(int ind, int n, string s, vector<vector<string>> &ans, vector<string> &temp)
    {
        if (ind == n)
        {
            ans.push_back(temp);
            return;
        }
        for (int i = ind; i < n; i++)
        {
            if (isPalindrome(s, ind, i))
            {
                temp.push_back(s.substr(ind, i - ind + 1));
                solve(i + 1, n, s, ans, temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(0, s.length(), s, ans, temp);
        return ans;
    }
};