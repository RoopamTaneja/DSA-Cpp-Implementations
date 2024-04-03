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
ld dp[305][305][305] = {0};

// ld f(ll n, ll i, ll j, ll k)
// {
//     if (i == 0 && j == 0 && k == 0)
//         return 0;
//     if (dp[i][j][k] != 0)
//         return dp[i][j][k];
//     ld val = 0;
//     if (i > 0)
//         val += (i * 1.0 / ld(i + j + k)) * (n * 1.0 / ld(i + j + k) + f(n, i - 1, j, k));
//     if (j > 0)
//         val += (j * 1.0 / ld(i + j + k)) * (n * 1.0 / ld(i + j + k) + f(n, i + 1, j - 1, k));
//     if (k > 0)
//         val += (k * 1.0 / ld(i + j + k)) * (n * 1.0 / ld(i + j + k) + f(n, i, j + 1, k - 1));
//     return dp[i][j][k] = val;
// }

void solve()
{
    ll n;
    ll entry;
    vl v;
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        cin >> entry;
        v.eb(entry);
    }
    ll x = 0, y = 0, z = 0;
    for (ll i = 0; i < n; i++)
    {
        if (v[i] == 1)
            x++;
        else if (v[i] == 2)
            y++;
        else
            z++;
    }
    dp[0][0][0] = 0;
    for (ll k = 0; k <= n; k++)
    {
        for (ll j = 0; j <= n; j++)
        {
            for (ll i = 0; i <= n; i++)
            {
                if (i + j + k > n)
                    continue;
                if (i > 0)
                    dp[i][j][k] += (i * 1.0 / ld(i + j + k)) * (n * 1.0 / ld(i + j + k) + dp[i - 1][j][k]);
                if (j > 0)
                    dp[i][j][k] += (j * 1.0 / ld(i + j + k)) * (n * 1.0 / ld(i + j + k) + dp[i + 1][j - 1][k]);
                if (k > 0)
                    dp[i][j][k] += (k * 1.0 / ld(i + j + k)) * (n * 1.0 / ld(i + j + k) + dp[i][j + 1][k - 1]);
            }
        }
    }
    cout << fixed << setprecision(10) << dp[x][y][z] << "\n";
    // cout << fixed << setprecision(10) << f(n, x, y, z) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}