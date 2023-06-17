// Code for BFS traversal as well as
// no. of connected components in undirected using BFS

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<int> &vis, vector<int> adj[], int S, vector<int> &result)
{
    vis[S] = 1;
    queue<int> q;
    // push the initial starting node
    q.push(S);

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
}

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    int count = 0;
    vector<int> vis(V, 0);
    vector<int> result;
    for (int i = 0; i < V; i++)
    {
        if (vis[i] == 0)
        {
            bfs(vis, adj, i, result);
            count++; // stores number of connected components
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
    vector<int> adj[6];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 0, 4);

    vector<int> ans = bfsOfGraph(5, adj);
    printAns(ans);

    return 0;
}
