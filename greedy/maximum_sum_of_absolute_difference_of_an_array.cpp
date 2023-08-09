#include <bits/stdc++.h>
using namespace std;

int max_abs_diff(int arr[], int i, int j)
{
  int sum = 0;
  while (i <= j)
  {
    sum += abs(arr[i] - arr[j]);
    i++;
    sum += abs(arr[i] - arr[j]);
    j--;
  }
  return sum;
}

int main()
{
  int arr[5] = {4, 5, 3, 1, 2};
  sort(arr, arr + 5);
  cout << max_abs_diff(arr, 0, 4);
  return 0;
}