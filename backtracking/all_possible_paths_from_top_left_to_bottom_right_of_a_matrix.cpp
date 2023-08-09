#include <bits/stdc++.h>
using namespace std;

void display(vector<int> &ans) // to print the path
{
  for (auto it : ans)
    cout << it << " ";
  cout << endl;
}

bool issafe(int r, int c, vector<vector<int>> &visited, int n, int m) // check if the cell is safe, that is not outside the boundary
{
  return (r < n and c < m and visited[r] != -1);
}

void FindPaths(vector<vector<int>> &grid, int r, int c, int n, int m, vector<int> &ans)
{
  // reached the last cell
  if (r == n - 1 and c == m - 1)
  {
    ans.push_back(grid[r]);
    display(ans);
    ans.pop_back(); // pop back because we need to backtrack to explore more path
    return;
  }

  int ch = grid[r];
  ans.push_back(ch); // push the path in ans array
  grid[r] = -1;      // mark the visited place with -1

  // if is it safe to take next downward step then take it
  if (issafe(r + 1, c, grid, n, m))
    FindPaths(grid, r + 1, c, n, m, ans);

  // if is it safe to take next rightward step then take it
  if (issafe(r, c + 1, grid, n, m))
    FindPaths(grid, r, c + 1, n, m, ans);

  grid[r] = ch;
  ans.pop_back();
  return;
}

int main()
{
  int n = 3, m = 3;
  vector<vector<int>> grid{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  vector<int> ans;
  FindPaths(grid, 0, 0, n, m, ans);
  return 0;
}
