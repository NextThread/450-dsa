string smallestWindow(string s, string p)
{
  unordered_map<char, int> mp;
  for (int i = 0; i < p.length(); i++)
    mp[p[i]] += 1;
  int count = mp.size(), i = 0, j = 0, rs = 0, ans = INT_MAX;
  while (j < s.size())
  {
    mp[s[j]]--;
    if (mp[s[j]] == 0)
      count--;
    if (count == 0)
    {
      while (count == 0)
      {
        if (ans > j - i + 1)
        {
          ans = j - i + 1;
          rs = i;
        }
        mp[s[i]]++;
        if (mp[s[i]] > 0)
          count++;
        i++;
      }
    }
    j++;
  }
  return (ans == INT_MAX) ? "-1" : s.substr(rs, ans);
}