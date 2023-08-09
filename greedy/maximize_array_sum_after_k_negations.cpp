long long int maximizeSum(long long int a[], int n, int k)
{
  sort(a, a + n);
  int count = 0;
  for (int i = 0; i < k; i++)
  {
    if (a[i] > 0)
      else
      {
        count++;
        a[i] = a[i] * -1;
      }
  }
  sort(a, a + n);
  k -= count;
  if (k % 2 != 0)
    a[0] = a[0] * -1;
  return accumulate(a, a + n, 0);
}