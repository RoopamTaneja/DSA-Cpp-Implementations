// Theory in eulerian_circuit.cpp
// This is iterative implementation for directed graph
// This is wrt CSES Q Teleporters Path
// (hence assuming it must start at 1 and end at n)
// TC : O(E)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;

void solve()
{
    ll n, m, a, b;
    cin >> n >> m;
    vl adj[n + 1];
    vl out(n + 1), in(n + 1);
    for (ll i = 0; i < m; i++)
    {
        cin >> a >> b;
        adj[a].emplace_back(b);
        out[a]++, in[b]++;
    }
    if (out[1] - in[1] != 1 || in[n] - out[n] != 1)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }
    for (ll i = 2; i < n; i++)
    {
        if (out[i] != in[i])
        {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    // Adding extra edge
    adj[n].emplace_back(1);
    out[n]++, in[1]++;
    vl ans;
    stack<ll> st;
    st.push(1);
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
    if (ans.size() == m + 2)
    {
        reverse(ans.begin(), ans.end());
        // Removing extra edge
        ll val;
        for (ll i = 0; i <= m; i++)
        {
            if (ans[i] == n && ans[i + 1] == 1)
            {
                val = i;
                break;
            }
        }
        vl ans2;
        for (ll i = val + 1; i <= m; i++)
            ans2.emplace_back(ans[i]);
        for (ll i = 0; i <= val; i++)
            ans2.emplace_back(ans[i]);
        for (auto &x : ans2)
            cout << x << " ";
        cout << "\n";
    }
    else
        cout << "IMPOSSIBLE\n";
}

int main()
{
    solve();
    return 0;
}
