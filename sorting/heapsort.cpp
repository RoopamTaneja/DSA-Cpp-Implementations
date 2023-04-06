#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
#define PI 3.14159265359

// recursive max_heapify
void max_heapify(vi &v, int n, int i)
{
    int largest;
    int l = 2 * i + 1;        // due to
    int r = 2 * i + 2;        // 0-based indexing
    if (l < n && v[l] > v[i]) // that's why l<n (last index is n-1)
        largest = l;
    else
        largest = i;
    if (r < n && v[r] > v[largest])
        largest = r;
    if (largest != i)
    {
        swap(v[i], v[largest]);
        max_heapify(v, n, largest);
    }
}

// iterative max_heapify
// void max_heapify(vi &v, int n, int i)
// {
//     while (i < n)
//     {
//         int largest;
//         int l = 2 * i + 1;        // due to
//         int r = 2 * i + 2;        // 0-based indexing
//         if (l < n && v[l] > v[i]) // that's why l<n (last index is n-1)
//             largest = l;
//         else
//             largest = i;
//         if (r < n && v[r] > v[largest])
//             largest = r;
//         if (largest != i)
//             swap(v[i], v[largest]);
//         else
//             break;
//     }
// }

void min_heapify(vi &v, int n, int i)
{
    int smallest;
    int l = 2 * i + 1;        // due to
    int r = 2 * i + 2;        // 0-based indexing
    if (l < n && v[l] < v[i]) // that's why l<n (last index is n-1)
        smallest = l;
    else
        smallest = i;
    if (r < n && v[r] < v[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(v[i], v[smallest]);
        min_heapify(v, n, smallest);
    }
}

void build_max_heap(vi &v, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        max_heapify(v, n, i);
}

void build_min_heap(vi &v, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        min_heapify(v, n, i);
}

void heapsort(vi &v, int n, int choice)
{
    if (choice == 1)
    {
        build_max_heap(v, n);
        for (int j = n - 1; j >= 1; j--)
        {
            swap(v[0], v[j]);
            max_heapify(v, j, 0); // setting i as initial index and reducing heap size through i
        }
    }
    if (choice == 2)
    {
        build_min_heap(v, n);
        for (int j = n - 1; j >= 1; j--)
        {
            swap(v[0], v[j]);
            min_heapify(v, j, 0); // setting i as initial index and reducing heap size through i
        }
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
    int size, entry, choice;
    cout << "Enter size of array : ";
    cin >> size;
    vi v;
    cout << "\nInput entries of array : \n";
    for (int i = 0; i < size; i++)
    {
        cin >> entry;
        v.emplace_back(entry);
    }
    cout << "Input choice : \n1 for ascending, 2 for descending\nYour choice : ";
    cin >> choice;
    cout << "\nOriginal array : \n";
    print_vec(v);
    if (choice == 1)
    {
        heapsort(v, v.size(), 1);
        cout << "Sorted array : \n";
        print_vec(v);
    }
    if (choice == 2)
    {
        heapsort(v, v.size(), 2);
        cout << "Sorted array : \n";
        print_vec(v);
    }
    return 0;
}