#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<ll, ll> pll;

class dsu
{
    vl parent, size;

public:
    dsu(ll n)
    { // makes new set
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (ll i = 0; i <= n; i++)
            parent[i] = i;
    }
    ll find_set(ll v)
    {
        if (v == parent[v])
            return v;
        // path compression
        return parent[v] = find_set(parent[v]);
    }
    void union_sets(ll a, ll b)
    {
        // union by size
        a = find_set(a);
        b = find_set(b);
        if (a != b)
        {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

ll spanningTree(ll V, vector<vl> adj[])
{
    vector<pair<ll, pll>> edges;
    for (ll i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            ll adjNode = it[0];
            ll wt = it[1];
            ll node = i;
            edges.push_back({wt, {node, adjNode}});
        }
    }
    dsu ds(V);
    sort(edges.begin(), edges.end());
    ll mstWt = 0;
    for (auto it : edges)
    {
        ll wt = it.first;
        ll u = it.second.first;
        ll v = it.second.second;
        if (ds.find_set(u) != ds.find_set(v))
        {
            mstWt += wt;
            ds.union_sets(u, v);
        }
    }
    return mstWt;
}

int main()
{
    int V = 5;
    vector<vl> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
    vector<vl> adj[V];
    for (auto it : edges)
    {
        vl tmp(2);
        tmp[0] = it[1];
        tmp[1] = it[2];
        adj[it[0]].push_back(tmp);

        tmp[0] = it[0];
        tmp[1] = it[2];
        adj[it[1]].push_back(tmp);
    }

    int mstWt = spanningTree(V, adj);
    cout << "The sum of all the edge weights: " << mstWt << endl;
    return 0;
}