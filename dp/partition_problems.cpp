#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define eb emplace_back
typedef vector<ll> vl;
typedef vector<vl> vvl;

// --------------------------------------------------------------------------
// Partition a set into two subsets with equal sum (yes or no)
bool f(vl &v, ll sum, ll ind, ll k) // pass k = sum
{
    if (k == sum / 2)
        return true;
    if (ind < 0)
        return false;
    bool ans = f(v, sum, ind - 1, k);
    if (k >= v[ind])
        ans = ans | f(v, sum, ind - 1, k - v[ind]);
    return ans;
}

bool f(vl &v, ll ind, ll k) // pass k = sum/2
{
    if (k == 0)
        return true;
    if (ind < 0)
        return false;
    bool ans = f(v, ind - 1, k);
    if (k >= v[ind])
        ans = ans | f(v, ind - 1, k - v[ind]);
    return ans;
}

bool canPartition(vl &nums)
{
    ll sum = 0;
    for (auto i : nums)
        sum += i;
    if (sum % 2)
        return false;

    return f(nums, nums.size() - 1, sum / 2);
}

// --------------------------------------------------------------------------
// Partition into two subsets such that abs(s1-s2) is min
ll foo(ll i, ll k, ll sum, vl &v)
{
    if (i < 0)
        return abs(2 * k - sum);
    ll ans = foo(i - 1, k, sum, v);
    if (k >= v[i])
        return min(ans, foo(i - 1, k - v[i], sum, v));
    return ans;
}
ll minimumDifference(vl &nums)
{
    ll sum = 0;
    for (auto i : nums)
        sum += i;
    return foo(nums.size() - 1, sum, sum, nums);
}

// ALITER :

ll minSubsetSumDifference(vl &arr, ll n)
{
    ll totSum = 0;
    for (ll i = 0; i < n; i++)
        totSum += arr[i];

    vector<bool> prev(totSum + 1, false);
    prev[0] = true; // 0 state
    prev[arr[0]] = true;

    for (int ind = 1; ind < n; ind++) // run N-1 states
    {
        vector<bool> cur(totSum + 1, false);
        cur[0] = true;

        for (ll target = 1; target <= totSum; target++)
        {
            bool notTaken = prev[target];
            bool taken = false;
            if (arr[ind] <= target)
                taken = prev[target - arr[ind]];
            cur[target] = notTaken || taken;
        }
        prev = cur;
    }

    ll mini = 1e9;
    for (ll i = 0; i <= totSum; i++)
        if (prev[i] == true)
            mini = min(mini, abs(i - (totSum - i)));
    return mini;
}

// --------------------------------------------------------------------------

int main()
{
    return 0;
}