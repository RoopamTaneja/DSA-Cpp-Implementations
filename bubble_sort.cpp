#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
#define PI 3.14159265359

void swap(int *x, int *y) // swap fn decl needed in C, C++ gives it's own swap fn
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// bubble sort algo for sorting in ascending as well as descending

// for arrays:
void asc_array(int arr[], int n)
{
    for (int i = 1; i < n; i++) // for round 1 to (n-1)
    {
        for (int j = 0; j < n - i; j++) // start from 0 index and stop at (n-1) or (n-i)
        {                               //(n-i) reduces your processing
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}
void des_array(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] < arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}
void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }
}

// for vectors:
void asc_vector(vi vec)
{
    for (int i = 1; i < vec.size(); i++) // for round 1 to (size-1)
    {
        for (int j = 0; j < vec.size() - i; j++) // start from 0 index and stop at (size-1) or (size-i)
        {                                        //(size-i) reduces your processing
            if (vec[j] > vec[j + 1])
                swap(vec[j], vec[j + 1]); // using c++ default swap fn
        }
    }
}
void desc_vector(vi vec)
{
    for (int i = 1; i < vec.size(); i++)
    {
        for (int j = 0; j < vec.size() - i; j++)
        {
            if (vec[j] < vec[j + 1])
                swap(vec[j], vec[j + 1]);
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
    int size = 0, entry = 0;
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

    int choice;
    cout << "\n 1 - Ascending\n";
    cout << " 2 - Descending\n";
    cout << "\nEnter choice : ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        asc_vector(v);
        cout << "\nArray in ascending order : \n";
        print_vec(v);
        break;
    case 2:
        desc_vector(v);
        cout << "\nArray in descending order : \n";
        print_vec(v);
        break;
    }
    return 0;
}