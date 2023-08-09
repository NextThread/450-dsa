#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &a, vector<int> &temp, int low, int mid, int high)
{
    int cnt = 0; // to count the inversion
    int i = low;
    int j = mid;
    int k = low;
    while ((i <= mid - 1) && (j <= high)) // merge sort
    {
        if (a[i] <= a[j]) // if in increasing
        {
            temp[k++] = a[i++];
        }
        else // if in decreasing
        {
            temp[k++] = a[j++];
            cnt += (mid - i);
        }
    }

    while (i <= mid - 1) // for the rest part, if left any
        temp[k++] = a[i++];

    while (j <= high)
        temp[k++] = a[j++];

    for (i = low; i <= high; i++) // copy all elements of temp in a
        a[i] = temp[i];
    return cnt;
}

int mergesort(vector<int> &a, vector<int> &temp, int low, int high)
{
    int cnt = 0;
    if (low < high)
    {
        int mid = (low + high) >> 1;
        cnt += mergesort(a, temp, low, mid);       // for the first half
        cnt += mergesort(a, temp, mid + 1, high);  // for second half
        cnt += merge(a, temp, low, mid + 1, high); // for all
    }
    return cnt;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), temp(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cout << mergesort(a, temp, 0, n - 1);
    return 0;
}