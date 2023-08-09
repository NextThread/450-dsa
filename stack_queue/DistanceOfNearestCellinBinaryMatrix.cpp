#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
	vector<vector<int>> res; 
    void dfs(int i, int j, vector<vector<int>>&grid, int steps) {
	    int m = grid.size(), n = grid[0].size();
	    vector<pair<int,int>>dr = {{-1,0}, {0,-1}, {0,1}, {1,0}};
	    for(auto r : dr) {
	        int x = r.first+i;
			int y = r.second+j;
	        if(x < 0 || y < 0 || x >= m || y >= n ) continue;
	        if(res[x][y] > steps+1){
	            res[x][y] = steps+1;
	            dfs(x, y, grid, steps+1);
	        }
	    }
	}
	vector<vector<int>>nearest(vector<vector<int>>grid) {
	    res.resize(grid.size(), vector<int>(grid[0].size() ,INT_MAX));
	    for(int i = 0 ; i < grid.size() ; i++)
	    {
	        for(int j = 0 ; j < grid[0].size() ; j++)
	        {
	            if(grid[i][j]) res[i][j] = 0;
	        }
	    }
	    for(int i = 0 ; i < grid.size() ; i++)
	    {
	        for(int j = 0 ; j < grid[0].size(); j++)
	        {
	            if(grid[i][j]) dfs(i, j, grid, 0);
	        }
	    }
	    return res;
	}

};
int main(){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << ' ';
			}
			cout << '\n';
		}
	return 0;
}