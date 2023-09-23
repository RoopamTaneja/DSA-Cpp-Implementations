#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define eb emplace_back
typedef vector<ll> vl;
typedef vector<vl> vvl;

ll sp_opt(vl &w, vl &v, ll N, ll W)
{
    ll max_val = 1e5 + 1;
    vl dp(max_val, 1e15);
    dp[0] = 0;

    for (ll ind = 1; ind <= N; ind++)
    {
        for (ll val = max_val - 1; val >= 0; val--)
        {
            if (v[ind - 1] <= val)
                dp[val] = min(dp[val], dp[val - v[ind - 1]] + w[ind - 1]);
        }
    }
    for (ll i = max_val - 1; i >= 0; i--)
        if (dp[i] <= W)
            return i;
    return -1;
}

int main()
{
    ll N, entry, W;
    vl w, v;
    cin >> N >> W;
    for (ll i = 0; i < N; i++)
    {
        cin >> entry;
        w.eb(entry);
        cin >> entry;
        v.eb(entry);
    }
    cout << sp_opt(w, v, N, W) << "\n";
    return 0;
}