#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;

// -----------------------------------------------------------------
// coin_change_1_remastered
ll dp[20][10010];
ll memo(ll amt, ll ind, vl &coins)
{
    if (ind == 0)
    {
        if (amt % coins[ind])
            return INT_MAX;
        return amt / coins[0];
    }
    if (amt == 0)
        return 0;
    if (dp[ind][amt] != -1)
        return dp[ind][amt];
    ll ans = INT_MAX;
    for (ll i = 0; i * coins[ind] <= amt; i++)
    {
        ll res = memo(amt - i * coins[ind], ind - 1, coins);
        if (res != INT_MAX)
            ans = min(ans, res + i);
    }
    return dp[ind][amt] = ans;
}

// ll tab(ll amt, ll ind, vl &coins)
// {
//     for (ll j = 0; j <= amt; j++)
//     {
//         if (j % coins[0])
//             dp[0][j] = INT_MAX;
//         else
//             dp[0][j] = j / coins[0];
//     }

//     for (ll i = 1; i <= ind; i++)
//     {
//         for (ll j = 0; j <= amt; j++)
//         {
//             dp[i][j] = INT_MAX;
//             for (ll k = 0; k * coins[i] <= j; k++)
//             {
//                 if (dp[i - 1][j - k * coins[i]] != INT_MAX)
//                     dp[i][j] = min(dp[i][j], dp[i - 1][j - k * coins[i]] + k);
//             }
//         }
//     }

//     return dp[ind][amt];
// }

// Improved time complexity
ll tab(ll amt, vl &coins)
{
    for (ll j = 0; j <= amt; j++)
    {
        if (j % coins[0])
            dp[0][j] = 1e7;
        else
            dp[0][j] = j / coins[0];
    }

    for (ll i = 1; i < coins.size(); i++)
    {
        for (ll j = 0; j <= amt; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (coins[i] <= j)
                dp[i][j] = min(dp[i][j], dp[i][j - coins[i]] + 1);
        }
    }

    return dp[coins.size() - 1][amt];
}

ll coinChange(ll amt, vl &coins)
{
    // memset(dp, -1, sizeof(dp));
    ll ans = tab(amt, coins);
    if (ans >= 1e7)
        return -1;
    return ans;
}
// --------------------------------------------------------------------------

// Coin change 2
ll sp[110][1000010];
ll ways(ll amt, ll ind, vl &coins)
{
    if (amt == 0)
        return 1;
    if (ind < 0)
        return 0;
    if (sp[ind][amt] != -1)
        return sp[ind][amt];
    ll ans = 0;
    for (ll c_amt = 0; c_amt <= amt; c_amt += coins[ind])
        ans += ways(amt - c_amt, ind - 1, coins);

    return sp[ind][amt] = ans;
}

const int MOD = 1e9 + 7;
ll tab_ways(ll amt, vl &coins)
{
    ll ind = coins.size() - 1;
    vvl sp(ind + 1, vl(amt + 1, 0));

    for (ll j = 0; j <= amt; j++)
    {
        if (j % coins[0])
            sp[0][j] = 0;
        else
            sp[0][j] = 1;
    }

    for (ll i = 1; i < coins.size(); i++)
    {
        for (ll j = 0; j <= amt; j++)
        {
            sp[i][j] = sp[i - 1][j];
            if (coins[i] <= j)
            {
                sp[i][j] += sp[i][j - coins[i]];
                sp[i][j] %= MOD;
            }
        }
    }

    return sp[ind][amt];
}

ll sp_opt(ll amt, vl &coins)
{
    ll ind = coins.size();
    vl arr(amt + 1, 0);

    for (ll j = 0; j <= amt; j++)
        if (j % coins[0] == 0)
            arr[j] = 1;

    for (ll i = 1; i < ind; i++)
    {
        for (ll j = 0; j <= amt; j++)
        {
            if (coins[i] <= j)
            {
                arr[j] += arr[j - coins[i]];
                arr[j] %= MOD;
            }
        }
    }
    return arr[amt];
}

ll coinChange2(ll amt, vl &coins)
{
    memset(sp, -1, sizeof(sp));
    return ways(amt, coins.size() - 1, coins);
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
    cout << sp_opt(x, v) << "\n";
    return 0;
}