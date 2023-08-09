#include <bits/stdc++.h>
using namespace std;
#define maxN 100000

vector<int> adj[maxN];
int indegree[maxN];

void addEdge(int u, int v)
{
    adj[u].push_back(v);
    indegree[v]++;
}

int main()
{
    int v, e;
    v = 10;
    e = 13;
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(1, 5);
    addEdge(2, 3);
    addEdge(2, 8);
    addEdge(2, 9);
    addEdge(3, 6);
    addEdge(4, 6);
    addEdge(4, 8);
    addEdge(5, 8);
    addEdge(6, 7);
    addEdge(7, 8);
    addEdge(8, 10);

    int job[v + 1];
    queue<int> q;
    for (int i = 1; i <= v; i++)
    {
        if (indegree[i] == 0) //  those who don't have any incoming parents,
        {                     //  they are parent and need to complete first
            q.push(i);
            job[i] = 1;
        }
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int it : adj[cur])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                job[it] = job[cur] + 1;
                q.push(it);
            }
        }
    }
    for (int i = 1; i <= v; i++)
        cout << job[i] << " ";
    return 0;
}
