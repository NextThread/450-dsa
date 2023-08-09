#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, int n, int m, int &gold, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (i >= n or j >= n or i < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int rightup = grid[i][j] + f(i - 1, j + 1, n, m, gold, grid, dp);
    int right = grid[i][j] + f(i, j + 1, n, m, gold, grid, dp);
    int rightdown = grid[i][j] + f(i + 1, j + 1, n, m, gold, grid, dp);
    return dp[i][j] = max(rightup, max(right, rightdown));
}

int main()
{
    int n, m;
    cin >> n >> m;
    int gold = 0;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    }
    for (int i = 0; i < n; i++)
    {
        gold = max(gold, f(i, 0, n, m, gold, grid, dp));
    }
    cout << gold;
    return 0;
}