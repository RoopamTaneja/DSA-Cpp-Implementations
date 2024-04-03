#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;

ll timer = 1;
vector<bool> vis;
vl tin;
vl low;
vector<bool> art_pts;

void dfs(ll node, ll parent, vl adj[])
{
    vis[node] = 1;
    tin[node] = low[node] = timer;
    timer++;
    ll child = 0;
    for (auto it : adj[node])
    {
        if (it == parent)
            continue;
        if (vis[it] == 0)
        {
            dfs(it, node, adj);
            low[node] = min(low[it], low[node]);

            // node --- it
            if (parent != -1 && low[it] >= tin[node])
                art_pts[node] = 1;

            child++;
        }
        else
        {
            low[node] = min(low[node], tin[it]);
        }
    }
    if (parent == -1 && child > 1)
        art_pts[node] = 1;
}

int main()
{
    ll n = 6;
    vector<vector<ll>> connections = {{0, 1}, {1, 4}, {2, 4}, {2, 3}, {3, 4}};
    vl adj[n];
    vis.assign(n, false);
    tin.resize(n);
    low.resize(n);
    art_pts.assign(n, false);
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
    for (ll i = 0; i < n; i++)
    {
        if (art_pts[i])
            cout << i << " ";
    }
    cout << "\n";
    return 0;
}