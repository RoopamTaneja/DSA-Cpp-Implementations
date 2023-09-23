// CSES Coin Combinations - I and Dice Combinations

#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define eb emplace_back
typedef vector<ll> vl;
typedef vector<vl> vvl;

const int MOD = 1e9 + 7;

ll tab(ll amt, vl &coins)
{
    vl dp(amt + 1, 0);
    dp[0] = 1;
    for (ll i = 1; i <= amt; i++)
    {
        for (ll coin : coins)
        {
            if (i - coin >= 0)
            {
                dp[i] += dp[i - coin];
                dp[i] %= MOD;
            }
        }
    }
    return dp[amt];
}

void solve()
{
    ll n, x, entry;
    vl v;
    cin >> n >> x;
    for (ll i = 0; i < n; i++)
    {
        cin >> entry;
        v.emplace_back(entry);
    }
    cout << tab(x, v) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}