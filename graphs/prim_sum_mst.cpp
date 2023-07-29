#include <bits/stdc++.h>
using namespace std;

// Function to find sum of weights of edges of the Minimum Spanning Tree.
int spanningTree(int V, vector<vector<int>> adj[])
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // not carrying parent since we only need sum
    vector<int> vis(V, 0);
    // {wt, node}
    pq.push({0, 0});
    int sum = 0;
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int wt = it.first;

        if (vis[node] == 1) // if top ka node is visited, do nothing
            continue;

        // else add it to the mst sum
        vis[node] = 1;
        sum += wt;
        for (auto it : adj[node])
        {
            int adjNode = it[0];
            int edW = it[1];
            if (!vis[adjNode])
            {
                pq.push({edW, adjNode});
            }
        }
    }
    return sum;
}

int main()
{

    int V = 5;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
    vector<vector<int>> adj[V];
    for (auto it : edges)
    { // making adj list from edges array
        vector<int> tmp(2);
        tmp[0] = it[1];
        tmp[1] = it[2];
        adj[it[0]].push_back(tmp);

        tmp[0] = it[0];
        tmp[1] = it[2];
        adj[it[1]].push_back(tmp);
    }

    int sum = spanningTree(V, adj);
    cout << "The sum of all the edge weights: " << sum << endl;

    return 0;
}

// ALITER:
//  #include <bits/stdc++.h>
//  using namespace std;

// // Function to find sum of weights of edges of the Minimum Spanning Tree.
// int sumMST(int v, vector<pair<int,int>> adj[])
// {
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//     vector<int> vis(v, 0);

//     // {wt, node}
//     pq.push({0, 0});
//     int sumEdges = 0;
//     while (!pq.empty())
//     {
//         auto it = pq.top();
//         pq.pop();
//         int node = it.second;
//         int wt = it.first;

//         if (vis[node] == 1)
//             continue;

//         vis[node] = 1;
//         sumEdges += wt;
//         for (auto it : adj[node])
//         {
//             int adjNode = it.first;
//             int edWeight = it.second;
//             if (!vis[adjNode])
//             {
//                 pq.push({edWeight, adjNode});
//             }
//         }
//     }
//     return sumEdges;
// }

// int main()
// {

//     int v =5;
//     vector<vector<int>> edges = {{0, 1, 1}, {1, 2, 3}, {2, 3, 2}, {3, 4, 5}, {0, 4, 6}, {4,1,7}};
//     vector<pair<int,int>> adj[v];
//     for (auto it : edges)
//     {//making adj list storing weights from edges
//         adj[it[0]].push_back(make_pair(it[1],it[2]));
//         adj[it[1]].push_back(make_pair(it[0],it[2]));
//     }

//     int sumEdges = sumMST(v, adj);
//     cout << "The sum of all the edge weights of MST of given graph : " << sumEdges <<"\n";

//     return 0;
// }