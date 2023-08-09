#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  vector<int> freq(n);
  for (int i = 0; i < n; i++)
    cin >> freq[i];

  vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n));
  for (int gap = 0; gap < n; gap++)
  {
    for (int i = 0, j = gap; j < n; j++, i++)
    {
      if (gap == 0)
        dp[i][j] = {freq[i], freq[i]};
      else
      {
        int first = 99999999;
        int second = 0;

        for (int k = i; k <= j; k++)
        {
          int one = freq[k];
          int two = freq[k];

          one += (k == i) ? 0 : dp[i][k - 1].first + dp[i][k - 1].second;
          two += (k == i) ? 0 : dp[i][k - 1].second;

          one += (k == j) ? 0 : dp[k + 1][j].first + dp[k + 1][j].second;
          two += (k == j) ? 0 : dp[k + 1][j].second;

          if (first > one)
          {
            first = one;
            second = two;
          }
        }
        dp[i][j].first = first;
        dp[i][j].second = second;
      }
    }
  }
  cout << dp[0][n - 1].first;
}