#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define eb emplace_back
typedef vector<ll> vl;
typedef vector<vl> vvl;

ll tab(vl &w, vl &v, ll N, ll W)
{
    vvl dp(110, vl(1e5 + 10, -1));

    for (ll amt = 0; amt <= W; amt++) // 0 state
        dp[0][amt] = (amt / w[0]) * v[0];

    for (ll ind = 1; ind < N; ind++) // loop runs N-1 times
    {
        for (ll amt = 0; amt <= W; amt++)
        {
            dp[ind][amt] = dp[ind - 1][amt];
            if (w[ind] <= amt)
                dp[ind][amt] = max(dp[ind][amt], dp[ind][amt - w[ind]] + v[ind]);
        }
    }
    return dp[N][W];
}

ll sp_opt(vl &w, vl &v, ll N, ll W)
{
    vl sp(W + 10, 0);                // -1 state
    for (ll ind = 0; ind < N; ind++) // loop running N times
        for (ll amt = 0; amt <= W; amt++)
            if (w[ind] <= amt)
                sp[amt] = max(sp[amt], sp[amt - w[ind]] + v[ind]);

    return sp[W];
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
    cout << sp_opt(w, v, N, W);
    return 0;
}