int minSubset(vector<int> &arr, int n)
{
  long long int halfSum = accumulate(arr.begin(), arr.end(), 0) / 2;
  sort(arr.begin(), arr.end(), greater<int>());
  long long int res = 0, curr_sum = 0;
  for (int i = 0; i < n; i++)
  {

    curr_sum += arr[i];
    res++;
    if (curr_sum > halfSum)
      return res;
  }
  return res;
}