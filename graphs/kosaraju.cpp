#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;

void dfs(ll node, vl adj[], ll vis[], stack<int> &st)
{
    vis[node] = 1;
    for (auto it : adj[node])
        if (!vis[it])
            dfs(it, adj, vis, st);

    st.push(node);
}

void dfs2(ll node, vl adjT[], ll vis[], vl &result)
{
    vis[node] = 1;
    result.push_back(node);
    for (auto it : adjT[node])
        if (!vis[it])
            dfs2(it, adjT, vis, result);
}

vector<vl> kosaraju(ll V, vl adj[])
{
    ll vis[V] = {0};
    stack<int> st;

    // first dfs
    for (int i = 0; i < V; i++)
        if (!vis[i])
            dfs(i, adj, vis, st);

    // reversing edges
    vl adjT[V];
    for (ll i = 0; i < V; i++)
    {
        vis[i] = 0;
        for (auto it : adj[i])
            adjT[it].push_back(i);
    }

    // second dfs
    vector<vl> scc;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!vis[node])
        {
            vl result;
            dfs2(node, adjT, vis, result);
            scc.emplace_back(result);
        }
    }
    return scc;
}

int main()
{

    ll n = 5;
    ll edges[5][2] = {
        {1, 0}, {0, 2}, {2, 1}, {0, 3}, {3, 4}};
    vl adj[n];
    for (int i = 0; i < n; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    vector<vl> ans = kosaraju(n, adj);
    cout << "The number of strongly connected components is: " << ans.size() << "\n";
    cout << "Strongly Connected Components : \n";
    for (auto v : ans)
    {
        for (auto it : v)
            cout << it << " ";
        cout << "\n";
    }

    return 0;
}