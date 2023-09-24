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



// --------------------------------------------------------------------------

int main()
{
    return 0;
}