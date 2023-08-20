#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool bfs(vector<int> &vis, vector<int> adj[], int S)
{
    vis[S] = 0;
    queue<int> q;
    q.push(S);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto it : adj[node])
        {
            if (vis[it] == vis[node])
                return false;
            else if (vis[it] == -1)
            {
                vis[it] = !vis[node];
                q.push(it);
            }
        }
    }
    return true;
}

bool isBipartite(int V, vector<int> adj[])
{
    vector<int> vis(V, -1);
    for (int i = 0; i < V; i++)
    {
        if (vis[i] == -1)
        {
            if (bfs(vis, adj, i) == false)
                return false;
        }
    }
    return true;
}

int main()
{

    return 0;
}
