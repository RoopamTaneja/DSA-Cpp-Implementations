#include <bits/stdc++.h>
using namespace std;

bool detect(int src, vector<int> adj[], int vis[])
{ // essentially it's bfs with pairs
    vis[src] = 1;
    queue<pair<int, int>> q;
    q.push({src, -1});
    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto adjacentNode : adj[node])
        {
            // if adjacent node is unvisited
            if (!vis[adjacentNode])
            {
                vis[adjacentNode] = 1;
                q.push({adjacentNode, node});
            }
            // if adjacent node is visited and is not it's own parent node
            else if (parent != adjacentNode)
            {
                // yes it is a cycle
                return true;
            }
        }
    }
    // there's no cycle
    return false;
}

bool isCycle(int V, vector<int> adj[])
{
    int vis[V] = {0};
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (detect(i, adj, vis))
                return true; // jaise hi kisi component mein cycle mili : return true
        }
    }
    return false; // saare component dekh liye : no cycles : return false
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