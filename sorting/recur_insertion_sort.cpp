#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
#define PI 3.14159265359

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

int main()
{

    return 0;
}