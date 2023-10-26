#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define eb emplace_back
typedef vector<ll> vl;
typedef vector<vl> vvl;

vvl dp(3010, vl(3010, -1));
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
    string s, t;
    cin >> s >> t;
    tab(s, t);
    cout << print_lcs(s, t);
    return 0;
}