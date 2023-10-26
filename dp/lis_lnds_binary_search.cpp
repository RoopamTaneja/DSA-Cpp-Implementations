#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define eb emplace_back
typedef vector<ll> vl;
typedef vector<vl> vvl;

ll lis(vl const &arr, vl &lis_seq)
{
    ll n = arr.size();
    vl dp, insertedAt(n, -1);
    dp.eb(arr[0]);
    insertedAt[0] = 1;
    for (ll i = 1; i < n; i++)
    {
        if (arr[i] > dp.back())
        {
            dp.eb(arr[i]);
            insertedAt[i] = dp.size();
        }
        else
        {
            ll l = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
            dp[l] = arr[i];
            insertedAt[i] = l + 1;
        }
    }
    ll curLen = dp.size();
    // Store lis
    lis_seq.clear();
    for (int i = n - 1; i >= 0; i--)
    {
        if (insertedAt[i] == curLen)
        {
            lis_seq.eb(arr[i]);
            curLen--;
        }
    }
    reverse(lis_seq.begin(), lis_seq.end());
    return dp.size(); // or lis_seq.size()
}

ll lnds(vl const &arr, vl &lnds_seq)
{
    ll n = arr.size();
    vl dp, insertedAt(n, -1);
    dp.eb(arr[0]);
    insertedAt[0] = 1;
    for (ll i = 1; i < n; i++)
    {
        if (arr[i] >= dp.back())
        {
            dp.eb(arr[i]);
            insertedAt[i] = dp.size();
        }
        else
        {
            ll l = upper_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
            dp[l] = arr[i];
            insertedAt[i] = l + 1;
        }
    }
    lnds_seq.clear();
    ll curLen = dp.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (insertedAt[i] == curLen)
        {
            lnds_seq.eb(arr[i]);
            curLen--;
        }
    }
    reverse(lnds_seq.begin(), lnds_seq.end());
    return dp.size();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, val;
    vl v, lis_seq, lnds_seq;
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        cin >> val;
        v.eb(val);
    }
    cout << "LIS length : ";
    cout << lis(v, lis_seq) << "\n";
    cout << "LIS : ";
    for (auto &i : lis_seq)
        cout << i << " ";
    cout << "\nLNDS length : ";
    cout << lnds(v, lnds_seq) << "\n";
    cout << "LNDS : ";
    for (auto &i : lnds_seq)
        cout << i << " ";
    return 0;
}
