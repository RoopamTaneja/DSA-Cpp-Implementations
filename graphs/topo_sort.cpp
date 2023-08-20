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

vl topoSort(ll V, vl adj[])
{
    ll vis[V] = {0};
    stack<int> st;
    for (ll i = 0; i < V; i++)
    {
        if (vis[i] == 0)
        {
            dfs(i, adj, vis, st);
        }
    }
    vl ans;
    while (!st.empty())
    {
        ans.emplace_back(st.top());
        st.pop();
    }
    return ans;
}

int main()
{
    return 0;
}