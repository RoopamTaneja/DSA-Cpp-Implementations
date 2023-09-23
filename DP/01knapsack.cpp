#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define eb emplace_back
typedef vector<ll> vl;
typedef vector<vl> vvl;

// // Brute force recursion
// ll f(vl &w, vl &v, ll ind, ll amt)
// {
//     if (amt == 0 || ind < 0)
//         return 0;

//     // not take
//     ll ans = f(w, v, ind - 1, amt);

//     // take
//     if (w[ind] <= amt)
//         ans = max(ans, f(w, v, ind - 1, amt - w[ind]) + v[ind]);

//     return ans;
// }

// // Memoisation
// vvl dp(110, vl(1e5 + 10, -1));
// ll memo(vl &w, vl &v, ll ind, ll amt)
// {
//     if (amt == 0 || ind < 0)
//         return 0;

//     if (dp[ind][amt] != -1)
//         return dp[ind][amt];

//     // not take
//     ll ans = memo(w, v, ind - 1, amt);

//     // take
//     if (w[ind] <= amt)
//         ans = max(ans, memo(w, v, ind - 1, amt - w[ind]) + v[ind]);

//     return dp[ind][amt] = ans;
// }

// ll tab(vl &w, vl &v, ll N, ll W)
// {
//     for (ll ind = 0; ind <= N; ind++)
//         dp[ind][0] = 0;

//     for (ll amt = 1; amt <= W; amt++)
//     {
//         if (w[0] <= amt)
//             dp[0][amt] = v[0];
//         else
//             dp[0][amt] = 0;
//     }

//     for (ll ind = 1; ind <= N; ind++)
//     {
//         for (ll amt = 1; amt <= W; amt++)
//         {
//             dp[ind][amt] = dp[ind - 1][amt];
//             if (w[ind] <= amt)
//                 dp[ind][amt] = max(dp[ind][amt], dp[ind - 1][amt - w[ind]] + v[ind]);
//         }
//     }
//     return dp[N][W];
// }

ll sp_opt(vl &w, vl &v, ll N, ll W)
{
    vl sp(W + 10, 0);
    for (ll ind = 0; ind <= N; ind++)
        for (ll amt = W; amt > 0; amt--)
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
    cout << sp_opt(w, v, N - 1, W);
    return 0;
}