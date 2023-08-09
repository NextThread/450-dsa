#include<bits/stdc++.h>
using namespace std;
int main() {
    int v, e;    // v = no of nodes, e = no of edges
    cin >> v >> e;
    vector<vector<int>> adj(v+1);
    for(int i = 0 ; i < e ; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
	vector<int> indegree(v, 0);
	for(int i = 0 ; i < v ; i++) {
	    for(auto it: adj[i]) indegree[it]++;
	}
    vector<int> fd;
    queue<int>q;
	for(int i = 0 ; i < v ;i++) {
	    if(indegree[i] == 0) q.push(i);
	}
	int cnt = 0;
	while(!q.empty()) {
	    int node = q.front();
	    q.pop();
	    cnt++;
	    for(auto it : adj[node]) {
	        indegree[it]--;
	        if(indegree[it] == 0) q.push(it);
	    }
	}
	if(cnt == v) cout<<"No cycle";
	else cout<<"Cycle present";
    return 0;
}