#include <bits/stdc++.h> 
void dfs(int i, int j, vector < vector < int >> & arr, int n, string temp, vector<string>& res, vector<vector<int>> & vis)
{
    if(i < 0 || j < 0 || i >= n || j >= n || vis[i][j] == 1 || arr[i][j] == 0) return;
    if(i == n-1 && j == n-1 && arr[i][j] == 1)
    {
        res.push_back(temp);
        return;
    }
    vis[i][j] = 1;
    dfs(i+1, j, arr, n, temp + 'D', res, vis);
    dfs(i-1, j, arr, n, temp + 'U', res, vis);
    dfs(i, j+1, arr, n, temp + 'R', res, vis);
    dfs(i, j-1, arr, n, temp + 'L', res, vis);
    vis[i][j] = 0;
}

vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    vector<string> res;
    vector<vector<int>> vis(n, vector<int>(n, 0));
    if(arr[0][0] = 1) dfs(0, 0, arr, n, "", res, vis);
    return res;
}