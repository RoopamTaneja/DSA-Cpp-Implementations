#include <bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int> &v)
{
    int n = v.size();
    for (int i = 1; i < n; i++)
    {
        int lb = lower_bound(v.begin(), v.begin() + i, v[i]) - v.begin();
        if (lb < i)
        {
            int j = i - 1;
            while (j >= lb)
            {
                swap(v[j], v[j + 1]);
                j--;
            }
        }
    }
}

// Worst Case T.C. : O(n^2) ... bcoz BS reduces no of comparisons
// not the no of shifts, they remain the same

int main()
{
    int n, entry;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> entry;
        v.emplace_back(entry);
    }
    insertion_sort(v);
    cout << "Sorted array : \n";
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
    return 0;
}