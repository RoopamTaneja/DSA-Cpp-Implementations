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

int main()
{
    return 0;
}