#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
#define PI 3.14159265359

void print_vec(vi vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << "\n";
}
int main()
{
    int size = 0, entry = 0, key = 0;
    int i, j;
    cout << "Enter size of array : ";
    cin >> size;
    vi v;
    cout << "\nInput entries of array : \n";
    for (int i = 0; i < size; i++)
    {
        cin >> entry;
        v.emplace_back(entry);
    }
    cout << "\nOriginal array : \n";
    print_vec(v); // Original Array

    // Insertion sort algo (0-based indexing)
    for (j = 1; j < v.size(); j++)
    {
        key = v[j];
        i = j - 1;
        while (i >= 0 && v[i] > key)
        {
            v[i + 1] = v[i];
            i--;
        }
        v[i + 1] = key;
    }

    cout << "Sorted array : \n";
    print_vec(v);
    return 0;
}