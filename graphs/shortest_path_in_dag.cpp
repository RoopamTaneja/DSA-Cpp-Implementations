#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int, int> pii;

void topoSort(int node, vector<pii> adj[], int vis[], stack<int> &st)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        int v = it.first;
        if (!vis[v])
            topoSort(v, adj, vis, st);
    }
    st.push(node);
}

vector<int> shortestPath(int V, vector<pii> adj[])
{ // adj list contains values as (vertex, weight)

    int vis[V] = {0};
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            topoSort(i, adj, vis, st);
        }
    }

    vector<int> dist(V, 1e9);
    dist[0] = 0; // assuming source to be 0
    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        for (auto it : adj[node])
        {
            int v = it.first;
            int wt = it.second;

            if (dist[node] != 1e9 && dist[node] + wt < dist[v])
                dist[v] = wt + dist[node];
        }
    }
    return dist;
}

int main()
{

    return 0;
}