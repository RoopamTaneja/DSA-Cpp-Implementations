#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PI 3.14159265359

int partition(vector<int> &v, int p, int r) // last element as pivot
{
    int x = v[r]; // pivot
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (v[j] <= x)
        {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[r]);
    return i + 1;
}

int partition2(vector<int> &v, int p, int r) // first element as pivot
{                                            // alternative way of partitioning
    int x = v[p];
    int i = r + 1;
    for (int j = r; j > p; j--)
    {
        if (v[j] > x)
        {
            i--;
            swap(v[i], v[j]);
        }
    }
    swap(v[i - 1], v[p]);
    return i - 1;
}

int partition3(vector<int> &v, int p, int r) // alternative way of partitioning
{
    int x = v[p]; // pivot
    int i = p + 1;
    int j = r;
    while (i < j)
    {
        while (v[i] <= x)
            i++;
        while (v[j] > x)
            j--;
        if (i < j)
            swap(v[i], v[j]);
    }
    swap(v[p], v[j]);
    return j;
}

int partition4(vector<int> &v, int p, int r) // alternative way of partitioning
{
    int x = v[r]; // pivot
    int i = p;
    int j = r - 1;
    while (i < j)
    {
        while (v[i] <= x)
            i++;
        while (v[j] > x)
            j--;
        if (i < j)
            swap(v[i], v[j]);
    }
    swap(v[r], v[i]);
    return i;
}

void quicksort(vector<int> &v, int p, int r)
{
    if (p < r) // must have atleast two elements
    {
        int q = partition(v, p, r);
        // int q = partition2(v, p, r);
        // int q = partition3(v, p, r);
        // int q = partition4(v, p, r);
        quicksort(v, p, q - 1);
        quicksort(v, q + 1, r);
    }
}

void print_vec(vector<int> vec)
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
    vector<int> v;
    cout << "\nInput entries of array : \n";
    for (int i = 0; i < size; i++)
    {
        cin >> entry;
        v.emplace_back(entry);
    }
    cout << "\nOriginal array : \n";
    print_vec(v);
    quicksort(v, 0, size - 1);
    cout << "Sorted array : \n";
    print_vec(v);
    return 0;
}