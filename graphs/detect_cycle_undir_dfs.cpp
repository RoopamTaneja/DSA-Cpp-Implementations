#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int parent, int vis[], vector<int> adj[])
{
    vis[node] = 1;
    for (auto adjacentNode : adj[node])
    {
        // unvisited adjacent node
        if (!vis[adjacentNode])
        {
            if (dfs(adjacentNode, node, vis, adj) == true)
                return true;
        }
        // visited node but not a parent node
        else if (adjacentNode != parent)
            return true;
    }
    return false;
}

bool isCycle(int V, vector<int> adj[])
{
    int vis[V] = {0};
    // for graph with connected components
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, -1, vis, adj) == true)
                return true;
        }
    }
    return false;
}

int main()
{

    // V = 4, E = 2
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
    bool ans = isCycle(4, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}