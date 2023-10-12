#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define eb emplace_back
typedef vector<ll> vl;
typedef vector<vl> vvl;

ll knapsack01(vl &w, vl &v, ll W)
{
    ll N = v.size();
    vl kn(W + 10, 0);
    for (ll ind = 0; ind < N; ind++)
        for (ll amt = W; amt > 0; amt--)
            if (w[ind] <= amt)
                kn[amt] = max(kn[amt], kn[amt - w[ind]] + v[ind]);

    return kn[W];
}

ll unbdd_knapsack(vl &w, vl &v, ll W)
{
    ll N = v.size();
    vl ukn(W + 10, 0);
    for (ll ind = 0; ind < N; ind++)
        for (ll amt = 0; amt <= W; amt++)
            if (w[ind] <= amt)
                ukn[amt] = max(ukn[amt], ukn[amt - w[ind]] + v[ind]);

    return ukn[W];
}

ll lcs(string &s1, string &s2)
{
    ll n = s1.size(), m = s2.size();
    vl prev(m + 1, 0), curr(m + 1, 0);
    for (ll i = 1; i <= n; i++) // filling index i with data of (i-1)
    {
        for (ll j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                curr[j] = prev[j - 1] + 1;
            else
                curr[j] = max(prev[j], curr[j - 1]);
        }
        prev = curr;
    }
    return prev[m];
}

int main()
{
    return 0;
}