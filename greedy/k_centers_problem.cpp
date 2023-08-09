#include <bits/stdc++.h>
using namespace std;
int maxindex(vector<int> &dist, int n)
{
  int mi = 0;
  for (int i = 0; i < n; i++)
    if (dist[i] > dist[mi])
      mi = i;
  return mi;
}
void selectKcities(int n, int weights[4][4], int k)
{
  vector<int> dist(n, INT_MAX), centers;
  int max = 0;
  for (int i = 0; i < k; i++)
  {
    centers.push_back(max);
    for (int j = 0; j < n; j++)
      dist[j] = min(dist[j], weights[max][j]);
    max = maxindex(dist, n);
  }
  cout << dist[max] << endl;
  for (int i = 0; i < centers.size(); i++)
    cout << centers[i] << " ";
}
main()
{
  int n = 4, k = 2;
  int weights[4][4] = {{0, 4, 8, 5},
                       {4, 0, 10, 7},
                       {8, 10, 0, 9},
                       {5, 7, 9, 0}};
  selectKcities(n, weights, k);
}