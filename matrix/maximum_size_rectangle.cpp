class Solution
{
public:
  int largestRectangleArea(vector<int> &height)
  {
    stack<int> s;
    height.push_back(0);
    int maxSize = 0;
    for (int i = 0; i < height.size(); i++)
    {
      if (s.empty() || height[i] >= height[s.top()])
      {
        s.push(i);
      }
      else
      {
        int temp = height[s.top()];
        s.pop();
        maxSize = max(maxSize, temp * (s.empty() ? i : i - 1 - s.top()));
        i--;
      }
    }
    return maxSize;
  }
  int maxArea(int M[MAX][MAX], int n, int m)
  {
    int res = 0;
    vector<int> dp(m, 0);
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (M[i][j] == 1)
          dp[j]++;
        else
          dp[j] = 0;
      }
      res = max(res, largestRectangleArea(dp));
    }
    return res;
  }
};