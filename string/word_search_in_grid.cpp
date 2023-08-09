bool isValid(int i, int j, int row, int col)
{
  if (i < 0 || j < 0 || i >= row || j >= col)
    return false;

  else
    return true;
}

vector<vector<int>> dirs = {{-1, 0}, {0, -1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}};

bool dfs(int i, int j, vector<vector<char>> &grid, string word, int row, int col)
{
  for (int k = 0; k < 8; k++)
  {
    int ni = i;
    int nj = j;
    int len = 0;
    while (isValid(ni, nj, row, col) && grid[ni][nj] == word[len])
    {
      ni += dirs[k][0];
      nj += dirs[k][1];
      len++;
    }
    if (len == word.length())
      return true;
  }
  return false;
}

vector<vector<int>> searchWord(vector<vector<char>> grid, string word)
{
  int row = grid.size();
  int col = grid[0].size();
  vector<vector<int>> ans;

  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      if (dfs(i, j, grid, word, row, col) && grid[i][j] == word[0])
        ans.push_back({i, j});
    }
  }

  return ans;
}