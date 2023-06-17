#include <bits/stdc++.h>
using namespace std;

int main()
{
    // n vertices & m edges
    int n, m;
    cin >> n >> m;

    // Adjacency List

    vector<int> adj[n + 1]; // n+1 for 1-based vertices
    // it is an array of n+1 vectors of ints. Each ele of the array adj is a vector of
    // ints. This is commonly used to represent an adjacency list of a graph where
    // each element of the array represents a vertex and the vector at that index
    // contains the vertices adjacent to it.
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // for u->v only this is needed
        adj[v].push_back(u); // this statement is removed for directed graph
    }

    // Adjacency Matrix

    int adj[n + 1][n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1; // for u->v only this is needed
        adj[v][u] = 1; // this statement is removed for directed graph
    }
    return 0;
}