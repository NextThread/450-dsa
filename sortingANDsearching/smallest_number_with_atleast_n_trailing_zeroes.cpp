int findNum(int n)
{
  int low = 0, high = n * 5;
  int ans = high;
  while (low <= high)
  {
    int mid = (low + high) >> 1;
    int count = 0;
    int num = 5;
    while (mid / num != 0)
    {
      count += mid / num;
      num *= 5;
    }
    if (count < n)
      low = mid + 1;
    else
    {
      ans = min(ans, mid);
      high = mid - 1;
    }
  }
  return ans;
}