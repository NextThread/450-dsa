int minSwap(int arr[], int n, int k)
{
  int cnt = 0, bad = 0;
  for (int i = 0; i < n; i++)
    cnt += (arr[i] <= k);
  for (int i = 0; i < cnt; i++)
    bad += (arr[i] > k);
  int res = bad;
  for (int i = 0, j = cnt; j < n; i++, j++)
  {
    if (arr[i] > k)
      bad--;
    if (arr[j] > k)
      bad++;
    res = min(res, bad);
  }
  return res;
}