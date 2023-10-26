// Max or min value path from upper left to bottom right cell

#include <bits/stdc++.h>
using namespace std;

// max
int tab(int m, int n, vector<vector<int>> val)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = val[0][0];
                continue;
            }
            int up = INT_MIN, left = INT_MIN;
            if (i > 0)
                up = dp[i - 1][j];
            if (j > 0)
                left = dp[i][j - 1];
            dp[i][j] = max(up, left) + val[i][j];
        }
    }
    return dp[m - 1][n - 1];
}