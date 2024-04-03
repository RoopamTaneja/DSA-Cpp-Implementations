#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>
using namespace std;

// Datatypes
typedef long long ll;
typedef long double ld;
typedef long int l;
typedef unsigned int ui;

// Vectors
#define pb push_back
#define eb emplace_back
#define all(v) v.begin(), v.end()
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

// Pairs
#define mp make_pair
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MOD = 1e9 + 7;

void solve()
{
    ll n;
    ld entry;
    vector<ld> v;
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        cin >> entry;
        v.eb(entry);
    }
    vector<vector<ld>> dp(n + 5, vector<ld>(n + 5, 0));
    dp[1][1] = v[0];
    dp[1][0] = 1 - v[0];
    for (ll i = 2; i <= n; i++)
    {
        dp[i][0] = dp[i - 1][0] * (1 - v[i - 1]);
    }

    for (ll i = 2; i <= n; i++)
    {
        for (ll j = 1; j <= i; j++)
        {
            dp[i][j] = dp[i - 1][j] * (1 - v[i - 1]) + dp[i - 1][j - 1] * v[i - 1];
        }
    }
    ld ans = 0;
    for (ll i = (n + 1) / 2; i <= n; i++)
    {
        ans += dp[n][i];
    }
    cout << setprecision(15) << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}