#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
#define PI 3.14159265359

void printVec(vi v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i];
    }
    cout << "\n";
}

// Print all subseq with sum k
void f(int index, vi &temp, vi arr, int sum, int k)
{
    int n = arr.size();
    if (index >= n)
    {
        if (sum == k)
            printVec(temp);
        return;
    }
    temp.push_back(arr[index]);
    sum += k;
    f(index + 1, temp, arr, sum, k);
    temp.pop_back();
    sum -= k;
    f(index + 1, temp, arr, sum, k);
}

// Print any one subseq with sum k
bool func(int index, vi &temp, vi arr, int sum, int k)
{
    int n = arr.size();
    if (index >= n)
    {
        if (sum == k)
        {
            printVec(temp);
            return true;
        }
        return false;
    }
    temp.push_back(arr[index]);
    sum += k;
    if (func(index + 1, temp, arr, sum, k) == true)
        return true;
    temp.pop_back();
    sum -= k;
    if (func(index + 1, temp, arr, sum, k) == true)
        return true;
    return false;
}

// Count all subseq with sum k ... no need of temp bcoz we're not printing
int foo(int index, vi arr, int sum, int k)
{
    int n = arr.size();
    if (index >= n)
    {
        if (sum == k)
            return 1;
        return 0;
    }
    sum += k;
    int l = foo(index + 1, arr, sum, k);
    sum -= k;
    int r = foo(index + 1, arr, sum, k);
    return l + r;
}

int main()
{
    // vi arr = {1, 2, 3};
    // vi temp;
    // cout << "All possible subsequences are: \n";
    // f(0, temp, arr);

    // string input = "1234";
    // vector<string> ans = power_set(input);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << "\n";
    // }
    return 0;
}