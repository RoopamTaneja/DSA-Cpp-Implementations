#include <bits/stdc++.h>
using namespace std;

// starting vertex different and multi source functionality pending

vector<int> bfs(int V, vector<int> adj[])
{
    int vis[V] = {0};
    vis[0] = 1;
    queue<int> q;
    // push the initial starting node
    q.push(0);
    vector<int> result;
    // iterate till the queue is empty
    while (!q.empty())
    {
        // get the topmost element in the queue
        int node = q.front();
        q.pop();
        result.push_back(node);
        // traverse for all its neighbours
        for (auto it : adj[node])
        {
            // if the neighbour has previously not been visited,
            // store in Q and mark as visited
            if (!vis[it])
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
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
    vector<int> adj[6];
    // it is an array of 6 vectors of ints. Each element of the array adj is a vector of
    // ints. This is commonly used to represent an adjacency list of a graph where
    // each element of the array represents a vertex and the vector at that index
    // contains the vertices adjacent to it.
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 0, 4);

    vector<int> ans = bfs(5, adj);
    printAns(ans);

    return 0;
}