#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define eb emplace_back
typedef vector<ll> vl;
typedef vector<vl> vvl;

// Brute force recursion
ll f(ll i, ll j, string &s1, string &s2)
{
    if (i < 0 || j < 0)
        return 0;
    if (s1[i] == s2[j])
        return f(i - 1, j - 1, s1, s2) + 1;
    return f(i - 1, j, s1, s2) + f(i, j - 1, s1, s2);
}

// Memoisation
vvl dp(1010, vl(1010, -1));
ll memo(ll i, ll j, string &s1, string &s2)
{
    if (i < 0 || j < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s1[i] == s2[j])
        return dp[i][j] = 1 + memo(i - 1, j - 1, s1, s2);

    return dp[i][j] = max(memo(i - 1, j, s1, s2), memo(i, j - 1, s1, s2));
}

// Tabulation
ll tab(string &s1, string &s2)
{
    ll n = s1.size(), m = s2.size();
    // filling index n with data of (n-1)
    for (ll a = 0; a <= n; a++)
        dp[a][0] = 0;
    for (ll b = 0; b <= m; b++)
        dp[0][b] = 0;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}

// Space optimisation
ll sp_opt(string &s1, string &s2)
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

// Backtracking to print lcs
string print_lcs(string &s1, string &s2)
{
    ll n = s1.size(), m = s2.size();
    string lcs = "";
    while (n && m)
    {
        if (s1[n - 1] == s2[m - 1])
        {
            lcs += s1[n - 1];
            n--;
            m--;
        }
        else if (dp[n - 1][m] > dp[n][m - 1])
            n--;
        else
            m--;
    }
    reverse(lcs.begin(), lcs.end());
    return lcs;
}

int main()
{
    return 0;
}