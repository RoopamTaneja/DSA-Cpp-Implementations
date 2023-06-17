// Code for DFS traversal as well as
// no. of connected components in undirected using DFS

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], int vis[], vector<int> &result)
{
    vis[node] = 1;
    result.push_back(node);
    // traverse all its neighbours
    for (auto it : adj[node])
    {
        // if the neighbour is not visited
        if (!vis[it])
        {
            dfs(it, adj, vis, result);
        }
    }
}

// Function to return a list containing the DFS traversal of the graph.
vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    int vis[V] = {0};
    int count = 0;

    // create a list to store dfs
    vector<int> result;
    for (int i = 0; i < V; i++)
    {
        if (vis[i] == 0)
        {
            dfs(i, adj, vis, result);
            count++;
        }
    }
    cout << "Number of connected components: " << count << "\n";
    return result;
}
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector<int> &ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}

int main()
{
    vector<int> adj[5];

    addEdge(adj, 0, 2);
    addEdge(adj, 2, 4);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);

    vector<int> ans = dfsOfGraph(5, adj);
    printAns(ans);

    return 0;
}