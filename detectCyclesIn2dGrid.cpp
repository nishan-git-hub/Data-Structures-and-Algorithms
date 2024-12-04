#include <bits/stdc++.h>

using namespace std;

bool dfs(int sx, int sy, int px, int py, vector<vector<bool>> &vis, vector<vector<int>> &dir, vector<vector<char>> &grid)
{
    int n = (int)grid.size();
    int m = (int)grid[0].size();

    vis[sx][sy] = true;

    for (auto d : dir)
    {
        int x = sx + d[0];
        int y = sy + d[1];

        if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == grid[sx][sy] && !(x == px && y == py))
        {
            if (vis[x][y] || dfs(x, y, sx, sy, vis, dir, grid))
            {
                return true;
            }
        }
    }
    return false;
}

bool containsCycle(vector<vector<char>> &grid)
{
    int n = (int)grid.size();
    int m = (int)grid[0].size();

    vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && dfs(i, j, -1, -1, vis, dir, grid))
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