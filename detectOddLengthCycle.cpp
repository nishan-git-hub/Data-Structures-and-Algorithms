#include <bits/stdc++.h>

using namespace std;

bool bfs(int src, vector<int> &color, vector<vector<int>> &adj)
{
    queue<int> q;
    q.push(src);
    color[src] = 1;

    while (!q.empty())
    {
        int src = q.front();
        q.pop();

        for (auto nbr : adj[src])
        {
            if (color[nbr] == -1)
            {
                color[nbr] = (color[src] + 1) % 2;
                q.push(nbr);
            }
            else if (color[nbr] == color[src])
            {
                return false;
            }
        }
    }
    return true;
}

bool oddLengthCycle(int V, vector<vector<int>> &adj)
{
    vector<int> color(V, -1);
    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
        {
            if (!bfs(i, color, adj))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    return 0;
}