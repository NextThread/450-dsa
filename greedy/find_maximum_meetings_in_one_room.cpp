void maxMeetings(int s[], int f[], int N)
{
  pair<int, int> a[N + 1];
  int i;
  for (i = 0; i < N; i++)
  {
    a[i].first = f[i];
    a[i].second = i;
  }
  sort(a, a + N);
  int time_limit = a[0].first;
  vector<int> m;
  m.push_back(a[0].second + 1);
  for (i = 1; i < N; i++)
  {
    if (s[a[i].second] > time_limit)
    {
      m.push_back(a[i].second + 1);
      time_limit = a[i].first;
    }
  }
  for (int i = 0; i < m.size(); i++)
    cout << m[i] << " ";
}