string smallestNumber(int s, int d)
{
  if (d * 9 < s)
    return "-1";
  string res = "";
  for (int i = 1; i < d; ++i)
  {
    if (s > 9)
    {
      res += "9";
      s -= 9;
    }
    else
    {
      res += to_string(s - 1);
      s = 1;
    }
  }
  res += to_string(s);
  reverse(res.begin(), res.end());
  return res;
}