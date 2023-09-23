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

const int MOD = 1e9 + 7;

// safe_map bfsOfGraph dfsIterOfGraph dfsRecurOfGraph flood_fill dijkstra kruskal

bool comp(pair<int, int> p1, pair<int, int> p2)
{ // just a sample
    if (p1.second > p2.second)
        return true;
    if (p1.second < p2.second)
        return false;
    if (p1.second == p2.second && p1.first > p2.first)
        return true;
    return false;
}

ll bin_mul(ll a, ll b, ll m)
{
    a %= m;
    ll res = 0;
    while (b > 0)
    {
        if (b & 1)
            res = (res + a) % m;
        a = (a + a) % m;
        b >>= 1;
    }
    return res;
}

ll bin_exp_iter(ll a, ll b, ll m)
{
    a %= m;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

ll pow_no_mod(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

ll floor_sqrt(ll x)
{
    ll ans = 0;
    for (ll k = 1LL << 30; k != 0; k /= 2)
    {
        if ((ans + k) * (ans + k) <= x)
            ans += k;
    }
    return ans;
}

class dsu
{
public:
    vl parent, size;
    dsu(ll n)
    { // makes new set
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (ll i = 0; i <= n; i++)
            parent[i] = i;
    }
    ll find_set(ll v)
    {
        if (v == parent[v])
            return v;
        // path compression
        return parent[v] = find_set(parent[v]);
    }
    void union_sets(ll a, ll b)
    {
        // union by size
        a = find_set(a);
        b = find_set(b);
        if (a != b)
        {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};
const ll N = 1e5 + 10;
ll dp[N][4];

// memo
ll f(ll day, int set_task, vvl task)
{
    if (dp[day][set_task] != -1)
        return dp[day][set_task];
    ll maxi = 0;
    if (day == 0)
    {
        for (int i = 0; i < 3; i++)
        {
            if (i != set_task)
                maxi = max(maxi, task[0][i]);
        }
        return maxi;
    }

    ll pts;
    for (int i = 0; i < 3; i++)
    {
        if (i != set_task)
        {
            pts = task[day][i] + f(day - 1, i, task);
            maxi = max(maxi, pts);
        }
    }
    return dp[day][set_task] = maxi;
}

// tab
void tab(ll n, vvl tasks)
{
    for (int task = 0; task <= 3; task++)
    {
        for (int i = 0; i < 3; i++)
        {
            if (i != task)
                dp[0][task] = max(dp[0][task], tasks[0][i]);
        }
    }
    for (ll day = 1; day < n; day++)
    {
        for (int task = 0; task <= 3; task++)
        {
            for (int i = 0; i < 3; i++)
            {
                if (i != task)
                    dp[day][task] = max(dp[day][task], tasks[day][i] + dp[day - 1][i]);
            }
        }
    }
    cout << dp[n - 1][3] << "\n";
}

// space opt
void tab2(ll n, vvl tasks)
{
    vl a(4, -1);
    for (int task = 0; task <= 3; task++)
    {
        for (int i = 0; i < 3; i++)
        {
            if (i != task)
                a[task] = max(a[task], tasks[0][i]);
        }
    }
    for (ll day = 1; day < n; day++)
    {
        vl b(4, -1);
        for (int task = 0; task <= 3; task++)
        {
            for (int i = 0; i < 3; i++)
            {
                if (i != task)
                    b[task] = max(b[task], tasks[day][i] + a[i]);
            }
        }
        a = b;
    }
    cout << a[3] << "\n";
}

void solve()
{
    ll n, entry;
    vvl v;
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        vl vec;
        for (ll j = 0; j < 3; j++)
        {
            cin >> entry;
            vec.eb(entry);
        }
        v.eb(vec);
    }
    // memset(dp, -1, sizeof(dp));
    // cout << f(n - 1, 3, v) << "\n";
    tab2(n, v);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // int t;
    // cin >> t;
    // while (t--)
    solve();
    return 0;
}