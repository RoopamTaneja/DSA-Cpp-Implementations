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

        // traverse for all its neighbours
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
    int count = 0;
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

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{
    vector<int> adj[6];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 0, 4);

    if (isBipartite(5, adj))
        cout << "TRUE\n";
    else
        cout << "FALSE\n";

    return 0;
}
