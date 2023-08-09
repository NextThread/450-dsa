long long int maxSum(int arr[], int n)
{
  long long int sum = 0;
  sort(arr, arr + n);
  for (int i = 0; i < n / 2; i++)
    sum += abs(arr[i] - arr[n - 1 - i]);
  return sum * 2;
}