// BFS -> shortest aug path first => Edmonds Karp algo

#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define eb emplace_back
#define all(v) v.begin(), v.end()
typedef vector<ll> vl;
typedef vector<vl> vvl;
#define mp make_pair
typedef pair<ll, ll> pll;

ll bfs(ll s, ll t, vl &parent, vl adj[], vvl &cap)
{
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pll> q;
    q.push({s, 1e10});
    while (!q.empty())
    {
        ll cur = q.front().first;
        ll flow = q.front().second;
        q.pop();
        for (ll next : adj[cur])
        {
            if (parent[next] == -1 && cap[cur][next] > 0)
            {
                parent[next] = cur;
                ll new_flow = min(flow, cap[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }
    return 0;
}

void solve()
{
    ll n, m, a, b, c;
    cin >> n >> m;
    ll s = 1, t = n;
    vl parent(n + 1);
    vl adj[n + 1];
    vvl cap(n + 1, vl(n + 1, 0));
    for (ll i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        adj[a].eb(b);
        adj[b].eb(a); // for reverse edges
        cap[a][b] += c;
    }
    ll max_flow = 0;
    ll new_flow;
    while ((new_flow = bfs(s, t, parent, adj, cap))) // while aug path exists
    {
        max_flow += new_flow; // increase total flow value
        ll cur = t;
        while (cur != s) // update residual graph
        {
            ll prev = parent[cur];
            cap[prev][cur] -= new_flow; // residual capacity of edge in path decreases by flow value
            cap[cur][prev] += new_flow; // residual capacity of reverse edge increases by flow value
            cur = prev;
        }
    }
    cout << max_flow << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}