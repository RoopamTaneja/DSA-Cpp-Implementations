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

// Mathematical Constants
#define _USE_MATH_DEFINES
#define mpi M_PI
#define me M_E
#define mphi 1.618033933 // Golden Ratio

vvl dp(110, vl(1e5 + 10, -1));
ll f(vl &w, vl &v, ll ind, ll amt)
{
    if (amt == 0 || ind < 0)
        return 0;

    if (dp[ind][amt] != -1)
        return dp[ind][amt];

    // not take
    ll ans = f(w, v, ind - 1, amt);

    // take
    if (w[ind] <= amt)
        ans = max(ans, f(w, v, ind - 1, amt - w[ind]) + v[ind]);

    return dp[ind][amt] = ans;
}

void solve()
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
    cout << f(w, v, N - 1, W);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}