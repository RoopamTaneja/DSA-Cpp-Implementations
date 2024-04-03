#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;

ll timer = 1;
vector<bool> vis;
vl tin;
vl low;
vector<vl> bridges;

void dfs(ll node, ll parent, vl adj[])
{
    vis[node] = 1;
    tin[node] = low[node] = timer;
    timer++;
    for (auto it : adj[node])
    {
        if (it == parent)
            continue;
        if (vis[it] == 0)
        {
            dfs(it, node, adj);
            low[node] = min(low[it], low[node]);

            // node --- it
            if (low[it] > tin[node])
                bridges.push_back({it, node});
        }
        else
        {
            low[node] = min(low[node], tin[it]);
        }
    }
}

int main()
{
    ll n = 4;
    vector<vector<ll>> connections = {{0, 1}, {1, 2}, {2, 0}, {1, 3}};
    vl adj[n];
    vis.assign(n, false);
    tin.resize(n);
    low.resize(n);
    for (auto it : connections)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    for (ll i = 0; i < n; i++)
    {
        if (!vis[i])
            dfs(i, -1, adj);
    }
    for (auto it : bridges)
        cout << "[" << it[0] << ", " << it[1] << "] ";
    cout << "\n";
    return 0;
}