#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
#define PI 3.14159265359

void insertionSortRecursive(vi &vec, int n);
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
    int size, entry, key;
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
    // ITERATIVE
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

    // for nonincreasing order:

    // for (j = 1; j < v.size(); j++)
    // {
    //     key = v[j];
    //     i = j - 1;
    //     while (i >= 0 && v[i] < key)
    //     {
    //         v[i + 1] = v[i];
    //         i--;
    //     }
    //     v[i + 1] = key;
    // }

    // insertionSortRecursive(v, size);

    cout << "Sorted array : \n";
    print_vec(v);
    return 0;
}

// RECURSIVE
void insertionSortRecursive(vi &vec, int n)
{
    // Base case
    if (n <= 1)
        return;

    // Sort first n-1 elements
    insertionSortRecursive(vec, n - 1);

    // Insert last element at its correct position
    // in sorted array.
    int last = vec[n - 1];
    int j = n - 2;

    /* Move elements of vec[0..i-1], that are
    greater than key, to one position ahead
    of their current position */
    while (j >= 0 && vec[j] > last)
    {
        vec[j + 1] = vec[j];
        j--;
    }
    vec[j + 1] = last;
}