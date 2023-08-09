bool check(int a[], int n, int k, int sum, int count, int find)
{
  if (find == 0)
  {
    count++;
    find = sum / k;
  }
  if (find < 0)
    return false;
  if (count == k)
    return true;
  for (int i = 0; i < n; i++)
  {
    if (a[i] != INT_MAX)
    {
      int b = a[i];
      a[i] = INT_MAX;
      if (check(a, n, k, sum, count, find - b))
        return true;
      a[i] = b;
    }
  }
  return false;
}

bool isKPartitionPossible(int a[], int n, int k)
{
  int sum = accumulate(a, a + n, 0);
  if (sum % k != 0)
    return false;
  return check(a, n, k, sum, 0, sum / k);
}