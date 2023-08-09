#include <bits/stdc++.h>
using namespace std;

int kthmin(vector<int> &a, int k)
{
    priority_queue<int> pq;
    for(int i = 0 ; i < a.size() ; i++)
    {
        pq.push(a[i]);
        if(pq.size() > k) pq.pop();
    }
    return pq.top();
}

int kthmax(vector<int> &a, int k)
{
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i = 0 ; i < a.size() ; i++)
    {
        pq.push(a[i]);
        if(pq.size() > k) pq.pop();
    }
    return pq.top();
}

int main () {
    int n;
    cin >> n;
    vector <int> a(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    int k;
    cin >> k;
    priority_queue<int> pq;
    cout << kthmax(a, k) << ' ' << kthmin(a, k);
}