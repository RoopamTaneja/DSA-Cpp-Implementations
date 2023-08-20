#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // Create a set ds for storing the nodes as a pair {dist,node}
    set<pair<int, int>> st;

    // Initialising dist list with a large number
    vector<int> dist(V + 1, 1e9);

    st.insert({0, S});

    // Source initialised with dist=0
    dist[S] = 0;

    // Now, erase the minimum distance node first from the set
    // and traverse for all its adjacent nodes.
    while (!st.empty())
    {
        auto it = *(st.begin());
        int node = it.second;
        int dis = it.first;
        st.erase(it);

        // Check for all adjacent nodes of the erased
        // element whether the prev dist is larger than current or not.
        for (auto it : adj[node])
        {
            int adjNode = it[0];
            int edgW = it[1];

            if (dis + edgW < dist[adjNode])
            {
                // erase if it was visited previously at
                // a greater cost.
                if (dist[adjNode] != 1e9)
                    st.erase({dist[adjNode], adjNode});

                // If current distance is smaller,
                // push it into the queue
                dist[adjNode] = dis + edgW;
                st.insert({dist[adjNode], adjNode});
            }
        }
    }
    // Return the list containing shortest distances
    // from source to all the nodes.
    return dist;
}

int main()
{
    int V = 5;
    int S; // source and destination
    S = 2;
    vector<vector<int>> adj[V + 1]; // adjacency list
    vector<int> path;               // for storing path

    adj[1].push_back({2, 3});
    adj[1].push_back({3, 4});
    adj[2].push_back({1, 3});
    adj[2].push_back({3, 1});
    adj[2].push_back({4, 6});
    adj[3].push_back({2, 1});
    adj[3].push_back({1, 4});
    adj[3].push_back({4, 2});
    adj[3].push_back({5, 5});
    adj[4].push_back({3, 2});
    adj[4].push_back({5, 1});
    adj[4].push_back({2, 6});
    adj[5].push_back({3, 5});
    adj[5].push_back({4, 1});

    vector<int> res = dijkstra(V, adj, S);

    for (int i = 1; i <= V; i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}