// A type of Partition DP
// https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

#include <bits/stdc++.h>
using namespace std;

int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N, vector<int>(N, 0));
    for (int len = 2; len < N; len++)
    {
        for (int i = 1; i < N - len + 1; i++)
        {
            int j = i + len - 1;
            dp[i][j] = 1e9;
            for (int k = i; k < j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j]);
        }
    }
    return dp[1][N - 1];
}

int main()
{
    return 0;
}