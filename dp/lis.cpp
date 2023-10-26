#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define eb emplace_back
typedef vector<ll> vl;
typedef vector<vl> vvl;

ll lis(vl const &a, vl &lis_seq)
{
    ll n = a.size();
    vl d(n, 1), p(n, -1);
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < i; j++)
        {
            if (a[j] < a[i] && d[i] < d[j] + 1)
            {
                d[i] = d[j] + 1;
                p[i] = j;
            }
        }
    }

    ll lis_length = d[0], pos = 0; // get position at which overall lis of array ends
    for (int i = 1; i < n; i++)
    {
        if (d[i] > lis_length)
            lis_length = d[i], pos = i;
    }

    // Backtracking to store lis
    while (pos != -1)
    {
        lis_seq.eb(a[pos]);
        pos = p[pos];
    }
    reverse(lis_seq.begin(), lis_seq.end());
    return lis_length;
} // btw lis_length is just lis_seq.size()

int main()
{
    return 0;
}
