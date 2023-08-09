void rearrange(int arr[], int n)
{
  vector<int> pos, neg, res;
  for (int i = 0; i < n; i++)
    (arr[i] >= 0) ? pos.push_back(arr[i]) : neg.push_back(arr[i]);
  int i = 0, j = 0;
  while (i < pos.size() or j < neg.size())
  {
    if (i < pos.size())
      res.push_back(pos[i++]);
    if (j < neg.size())
      res.push_back(neg[j++]);
  }
  for (int i = 0; i < n; i++)
    arr[i] = res[i];
}