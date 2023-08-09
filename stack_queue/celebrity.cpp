int celebrity(vector<vector<int>> &M, int n)
{
  // similar to Leetcode find judge problem
  vector<pair<int, int>> v(n + 1, {0, 0});
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (M[i][j] == 1)
      {
        v[i].first += 1;  // trusting person
        v[j].second += 1; // trusted person
      }
    }
  }
  for (int i = 0; i <= n; i++)
  {
    if (v[i].first == 0 && v[i].second == n - 1)
      return i;
  }
  return -1;
}