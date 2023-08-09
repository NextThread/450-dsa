#include <bits/stdc++.h>
using namespace std;
int firstpos(vector<int>& arr, int key) {
    int ind = -1, lo = 0, hi = arr.size()-1;
    while(lo <= hi) 
    {
        int mid = (lo+hi)>>1;
        if(arr[mid] == key) 
        {
            ind = mid;
            hi = mid-1;
        }
        else if(arr[mid]<key) 
        {
            lo = mid+1;
        } 
        else 
        {
            hi = mid-1;
        }
    }
    return ind;
}
int lastpos(vector<int>& arr, int key) {
    int ind = -1, lo = 0, hi = arr.size()-1;
    while(lo <= hi) 
    {
        int mid = (lo+hi)>>1;
        if(arr[mid] == key) 
        {
            ind = mid;
            lo = mid+1;
        }
        else if(arr[mid]<key)
        {
            lo = mid+1;
        }
        else {
            hi = mid-1;
        }
    }
    return ind;
}
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    int target;
    cin >> target;
    int firstposition = firstpos(a, target);
    int lastposition = lastpos(a, target);
    cout << "First Position = " << firstposition << '\n';
    cout << "Last Position = " << lastposition << '\n';
}