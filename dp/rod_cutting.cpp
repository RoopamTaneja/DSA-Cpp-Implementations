#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define eb emplace_back
typedef vector<ll> vl;
typedef vector<vl> vvl;

ll unbdd_knapsack(vl &v, ll N)
{
    vl ukn(N + 10, 0);
    for (ll ind = 0; ind < N; ind++)
        for (ll amt = 0; amt <= N; amt++)
            if ((ind + 1) <= amt)
                ukn[amt] = max(ukn[amt], ukn[amt - (ind + 1)] + v[ind]);

    return ukn[N];
}

int main()
{
    return 0;
}