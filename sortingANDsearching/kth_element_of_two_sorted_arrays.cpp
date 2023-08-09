int kthElement(int arr1[], int arr2[], int n, int m, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
        pq.push(arr1[i]);
    for (int i = 0; i < m; i++)
        pq.push(arr2[i]);
    while (pq.size() > k)
        pq.pop();
    return pq.top();
}