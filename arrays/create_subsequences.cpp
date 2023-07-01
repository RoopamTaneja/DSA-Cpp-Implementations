#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
#define PI 3.14159265359

// Bit manipulation :
vector<string> power_set(string input)
{
    vector<string> result;
    for (int num = 0; num < (1 << input.length()); num++)
    {
        string s = "";
        for (int i = 0; i < input.length(); i++)
        {
            if (num & (1 << i)) // is ith bit of num a set bit or not?
                s += input[i];
        }
        if (s.length())
            result.push_back(s);
    }
    return result;
}

// Recursive :
void printVec(vi v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i];
    }
    cout << "\n";
}

void f(int index, vi &temp, vi arr)
{
    int n = arr.size();
    if (index >= n)
    {
        printVec(temp);
        return;
    }
    temp.push_back(arr[index]);
    f(index + 1, temp, arr);
    temp.pop_back();
    f(index + 1, temp, arr);
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