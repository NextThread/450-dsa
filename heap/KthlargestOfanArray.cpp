class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    priority_queue<int> pq;
	    for(int i = 0 ; i < n ; i++) pq.push(arr[i]);
	    vector<int> res;
	    while(k--) {
	        res.push_back(pq.top());
	        pq.pop();
	    }
	    return res;
	}
};