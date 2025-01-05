// "Go through all edges exactly once"

// Undirected graph :
// - If all nodes have even degree, eulerian circuit exists
// - If only two nodes have odd degree, rest all even then eulerian path (not circuit)
//     exists which starts and ends at the odd degree nodes

// Directed graph :
// - If all nodes have indegree = outdegree
// - If only one node has indeg = outdeg + 1 and other indeg = outdeg - 1,
//     rest all have indeg = outdeg then eulerian path (not circuit)
//     exists which starts at larger outdeg and ends at the smaller.

// TC : O(E)

// Given that graph has eulerian circuit (otherwise we can't use this algo),
// we have Hierholzer's algo to construct it :

/*
Say we run a normal DFS -> gives me a simple cycle in graph but may not cover all edges.

To make it cover all edges, let's make sure nodes cover any other cycles (subcircuits) they are part of.

So while returning from DFS, check if a node has any unvisited edges (any for undir, outgoing for dir) 
and run dfs along that edge -> gives a new subcircuit; do this recursively for all nodes. 
Also instead of vis array, we will mark edges as used : 
    - for directed, going over adj list in particular order is sufficient since they are one-way
    - for undirected, maintain removed_edges array to mark a used edge (since two-way)

When a node has no more unvisited edges, add it to my soln.

Thus at each stage, my algo adds subcircuits along an unvisited edge to my eventual circuit.

Here we maintain no of unvisited edges for each vertex (any for undir, outgoing for dir), 
the no will allow us to track no of edges left to check as well as index into the adj list.

Can implement the DFS recursively as well as iteratively via stack.
*/

// If the graph only contains an Eulerian path, we can still use Hierholzer’s
// algorithm to find it by adding an extra edge to the graph and removing the edge
// after the circuit has been constructed.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef vector<pll> vp;

// Recursive - undirected
void dfs_recur_und(ll st, vp adj[], vl &deg, vector<bool> &rem, vl &ans)
{
    while (deg[st] > 0)
    {
        auto [nbor, id] = adj[st][--deg[st]];
        if (!rem[id])
        {
            rem[id] = 1;
            dfs_recur_und(nbor, adj, deg, rem, ans);
        }
    }
    ans.emplace_back(st);
}

// Iterative - undirected
void dfs_und(ll start, vp adj[], vl &deg, vector<bool> &rem, vl &ans)
{
    stack<ll> st;
    st.push(start);
    while (!st.empty())
    {
        ll x = st.top();
        if (deg[x] > 0)
        {
            auto [nbor, id] = adj[x][--deg[x]];
            if (!rem[id])
            {
                rem[id] = 1;
                st.push(nbor);
            }
        }
        else
        {
            st.pop();
            ans.emplace_back(x);
        }
    }
}

// Iterative - directed
void dfs_dir(ll start, vl adj[], vl &out, vl &ans)
{
    stack<ll> st;
    st.push(start);
    while (!st.empty())
    {
        ll x = st.top();
        if (out[x] > 0)
        {
            auto nbor = adj[x][--out[x]];
            st.push(nbor);
        }
        else
        {
            st.pop();
            ans.emplace_back(x);
        }
    }
}

void solve(bool dir, ll st)
{
    ll n, m, a, b;
    cin >> n >> m;
    vl ans;
    if (!dir)
    {
        vp adj[n + 1];
        for (ll i = 0; i < m; i++)
        {
            cin >> a >> b;
            adj[a].emplace_back(b, i);
            adj[b].emplace_back(a, i);
        }
        vl deg(n + 1);
        for (ll i = 1; i <= n; i++)
        {
            if (adj[i].size() % 2)
            {
                cout << "IMPOSSIBLE\n";
                return;
            }
            deg[i] = adj[i].size();
        }
        vector<bool> rem(m + 1);
        dfs_und(st, adj, deg, rem, ans);
    }
    else
    {
        vl adj[n + 1];
        vl out(n + 1), in(n + 1);
        for (ll i = 0; i < m; i++)
        {
            cin >> a >> b;
            adj[a].emplace_back(b);
            out[a]++, in[b]++;
        }
        for (ll i = 1; i <= n; i++)
        {
            if (out[i] != in[i])
            {
                cout << "IMPOSSIBLE\n";
                return;
            }
        }
        dfs_dir(st, adj, out, ans);
    }

    // Found path is eulerian cycle only if the graph was connected
    if (ans.size() == m + 1)
    {
        for (auto &x : ans)
            cout << x << " ";
        cout << "\n";
    }
    else
        cout << "IMPOSSIBLE\n";
}

int main()
{
    solve(false, 1); // true - directed, false - undirected ; start node = 1 (here)
    return 0;
}