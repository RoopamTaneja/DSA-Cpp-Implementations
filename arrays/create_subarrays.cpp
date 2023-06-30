#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

void subarrays(vi input)
{
    int n = input.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = i; k <= j; k++)
            {
                cout << input[k] << " ";
            }
            cout << "\n";
        }
    }
}

int main()
{

    return 0;
}