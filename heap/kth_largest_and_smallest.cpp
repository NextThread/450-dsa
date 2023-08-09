#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 6;
    int a[] = {1, 2, 3, 4, 5, 6};
    int k = 2;
    priority_queue<int> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;
    for (int i = 0; i < 6; i++)
    {
        pq1.push(a[i]);
        pq2.push(a[i]);
    }
    while (pq1.size() > k and pq2.size() > k)
    {
        pq1.pop();
        pq2.pop();
    }
    cout << pq1.top() << ' ' << pq2.top();
}