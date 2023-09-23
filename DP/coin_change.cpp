#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;

ll f(ll amt, vl &coins)
{
    if (amt == 0)
        return 0;
    ll ans = INT_MAX;
    for (ll coin : coins)
    {
        if (amt - coin >= 0)
            ans = min(ans, f(amt - coin, coins) + 1);
    }
    return ans;
}
// const ll N = 1e4 + 10;
// vl dp(N, -1);

// ll memo(ll amt, vl &coins)
// {
//     if (amt == 0)
//         return 0;
//     if (dp[amt] != -1)
//         return dp[amt];
//     ll ans = INT_MAX;
//     for (ll coin : coins)
//     {
//         if (amt - coin >= 0)
//             ans = min(ans, f(amt - coin, coins) + 1);
//     }
//     return dp[amt] = ans;
// }

const ll N = 1e6 + 10;
vl dp(N, INT_MAX);

ll tab(ll amt, vl &coins)
{
    dp[0] = 0;
    for (ll i = 0; i <= amt; i++)
        for (ll coin : coins)
            if (i - coin >= 0)
                dp[i] = min(dp[i - coin] + 1, dp[i]);
    return dp[amt];
}

ll coinChange(ll amt, vl &coins)
{
    ll ans = tab(amt, coins);
    if (ans == INT_MAX)
        return -1;
    return ans;
}

int main()
{
    ll n, x, entry;
    vl v;
    cin >> n >> x;
    for (ll i = 0; i < n; i++)
    {
        cin >> entry;
        v.emplace_back(entry);
    }
    cout << coinChange(x, v) << "\n";
    return 0;
}