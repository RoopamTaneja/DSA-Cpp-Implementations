#include <bits/stdc++.h>
using namespace std;
// prints shortest path also
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S, int D, vector<int> &path)
{

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> distTo(V + 1, INT_MAX);

    // for shortest path
    vector<int> parent(V + 1);
    for (int i = 1; i <= V; i++)
        parent[i] = i;

    // Source initialised with dist=0.
    distTo[S] = 0;
    pq.push({0, S});

    // Now, pop the minimum distance node first from the min-heap
    // and traverse for all its adjacent nodes.
    while (!pq.empty())
    {
        int node = pq.top().second;
        int dis = pq.top().first;
        pq.pop();

        // Check for all adjacent nodes of the popped out
        // element whether the prev dist is larger than current or not.
        for (auto it : adj[node])
        {
            int v = it[0];
            int wt = it[1];
            if (dis + wt < distTo[v])
            {
                distTo[v] = dis + wt;

                // If current distance is smaller,
                // push it into the queue.
                pq.push({dis + wt, v});

                // Update the parent of the adjNode to the recent
                // node where it came from.
                parent[v] = node;
            }
        }
    }

    // If distance to a node could not be found, return an array containing -1.
    if (distTo[D] == INT_MAX)
        path.push_back(-1);

    if (path.empty()) //-1 aa rakha hai toh kuch na karo
    {
        // Iterate backwards from destination to source through the parent array.
        while (parent[D] != D)
        {
            path.push_back(D);
            D = parent[D];
        }
        path.push_back(S);

        reverse(path.begin(), path.end());
    }
    // Return the list containing shortest distances
    // from source to all the nodes.
    return distTo;
}

int main()
{
    int V = 5;
    int S, D; // source and destination
    S = 4, D = 1;
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

    vector<int> res = dijkstra(V, adj, S, D, path);
    cout << "Shortest Distances from " << S << " :\n";
    for (int i = 1; i <= V; i++)
    {
        cout << res[i] << " ";
    }

    cout << "\nShortest Path from " << S << " to " << D << " : \n";
    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i] << " ";
    }
    return 0;
}