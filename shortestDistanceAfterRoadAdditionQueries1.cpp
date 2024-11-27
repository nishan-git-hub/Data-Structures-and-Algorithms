#include <bits/stdc++.h>

using namespace std;

int bfs(int n, vector<vector<int>> &adj)
{
    vector<int> dist(n, 1e9);
    dist[0] = 0;

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0, 0});

    while (!pq.empty())
    {
        vector<int> temp = pq.top();
        pq.pop();

        int src = temp[1];
        int dis = temp[0];

        if (src == n - 1)
        {
            return dist[n - 1];
        }

        for (auto nbr : adj[src])
        {
            if (dis + 1 <= dist[nbr])
            {
                dist[nbr] = dis + 1;
                pq.push({dist[nbr], nbr});
            }
        }
    }
    return dist[n - 1];
}

vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries)
{
    vector<vector<int>> adj(n);
    for (int i = 0; i <= n - 2; i++)
    {
        int u = i;
        int v = i + 1;
        adj[u].push_back(v);
    }

    vector<int> ans;
    for (auto q : queries)
    {
        int u = q[0];
        int v = q[1];

        adj[u].push_back(v);
        int res = bfs(n, adj);

        ans.push_back(res);
    }
    return ans;
}

int main()
{

    return 0;
}