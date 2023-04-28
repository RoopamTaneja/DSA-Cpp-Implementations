#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
#define PI 3.14159265359

int a(int n)
{
    if (n == 1)
        return 1;

    return a(n - 1);
}
int main()
{
    cout << a(5) << "\n";
    cout << a(10) << "\n";

    return 0;
}