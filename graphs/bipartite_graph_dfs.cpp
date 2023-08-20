#include <bits/stdc++.h>
using namespace std;

// toggling between 0 and 1 : use bitwise NOT (!)

bool dfs(int node, int colour, vector<int> adj[], int vis[])
{
    vis[node] = colour;

    // traverse all its neighbours
    for (auto it : adj[node])
    {
        if (vis[it] == -1)
        {
            if (dfs(it, !colour, adj, vis) == false)
                return false;
        }

        else if (vis[it] == vis[node])
            return false;
    }
    return true;
}

bool isBipartite(int V, vector<int> adj[])
{
    int vis[V] = {-1}; //-1 shows unvisited (and hence uncoloured neighbour)
    return dfs(0, 0, adj, vis);

    // can also make it multi source for connected components like u did in cycles
}

int main()
{

    return 0;
}