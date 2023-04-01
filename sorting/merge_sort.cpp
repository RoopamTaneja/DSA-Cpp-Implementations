#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
#define PI 3.14159265359

void merge(vi &v, int p, int q, int r)
{
    int i, j;
    vi left, right;
    for (i = p; i <= q; i++)
    {
        left.emplace_back(v[i]);
    }
    for (j = q + 1; j <= r; j++)
    {
        right.emplace_back(v[j]);
    }
    left.emplace_back(INT32_MAX);
    right.emplace_back(INT32_MAX);
    i = 0, j = 0;
    for (int k = p; k <= r; k++)
    {
        if (left[i] <= right[j])
        {
            v[k] = left[i];
            i++;
        }
        else
        {
            v[k] = right[j];
            j++;
        }
    }
}

void merge_sort_asc(vi &v, int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        merge_sort_asc(v, p, q);
        merge_sort_asc(v, q + 1, r);
        merge(v, p, q, r);
    }
}

void print_vec(vi vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << "\t";
    }
    cout << "\n";
}

int main()
{
    int size, entry;
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
    print_vec(v);
    merge_sort_asc(v, 0, size - 1);
    cout << "Sorted array : \n";
    print_vec(v);

    return 0;
}