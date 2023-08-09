int minOps(string &A, string &B)
{
  int m = A.length(), n = B.length();
  if (n != m)
    return -1;
  vector<int> count(256, 0);
  for (int i = 0; i < n; i++)
    count[A[i]] += 1;
  for (int i = 0; i < n; i++)
    count[B[i]] -= 1;
  for (int i = 0; i < 256; i++)
    if (count[i])
      return -1;
  int res = 0;
  for (int i = n - 1, j = n - 1; i >= 0;)
  {
    while (i >= 0 && A[i] != B[j])
    {
      i--;
      res++;
    }
    if (i >= 0)
    {
      i--;
      j--;
    }
  }
  return res;
}