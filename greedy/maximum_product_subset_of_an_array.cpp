long long int findMaxProduct(vector<int> &a, int n)
{
  if (n == 1)
    return a[0];
  int zero = 0, neg = 0, maxneg = INT_MIN, mod = 1e9 + 7;
  long long ans = 1;
  for (int i = 0; i < n; i++)
  {
    if (a[i] == 0)
    {
      zero++;
      continue;
    }
    if (a[i] < 0)
    {
      neg++;
      maxneg = max(maxneg, a[i]);
    }
    ans = (ans * a[i]) % mod;
  }
  if (zero == n)
    return 0;
  else if (neg == 1 && zero + neg == n)
    return 0;
  else if (neg & 1)
    return ans / maxneg;
  else
    return ans;
}