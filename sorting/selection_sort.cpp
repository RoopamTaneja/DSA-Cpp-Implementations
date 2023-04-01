#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
#define PI 3.14159265359

void swap(int &x, int &y) // swap fn decl needed in C, C++ gives it's own swap fn
{
    int temp = x;
    x = y;
    y = temp;
}

// selection sort algo for sorting in ascending as well as descending

// for arrays:
void asc_array(int arr[], int n)
{
    int min_index = 0;
    for (int i = 0; i < n - 1; i++) // last pe jaane ki zarurat nhi, till (n-2)
    {
        min_index = i;
        for (int j = i + 1; j < n; j++) // loop to find min for each i
        {
            if (arr[j] < arr[min_index])
                min_index = j;
        }
        swap(arr[i], arr[min_index]);
    }
}
void des_array(int arr[], int n)
{
    int max_index = 0;
    for (int i = 0; i < n; i++)
    {
        max_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[max_index])
                max_index = j;
        }
        swap(arr[i], arr[max_index]);
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
void asc_vector(vi &vec) // pass by ref...don't forget
{
    int min_index = 0;
    for (int i = 0; i < vec.size() - 1; i++) // last pe jaane ki zarurat nhi, till (size-2)
    {
        min_index = i;
        for (int j = i + 1; j < vec.size(); j++) // loop to find min for each i
        {
            if (vec[j] < vec[min_index])
                min_index = j;
        }
        swap(vec[i], vec[min_index]);
    }
}
void des_vector(vi &vec)
{
    int max_index = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        max_index = i;
        for (int j = i + 1; j < vec.size(); j++)
        {
            if (vec[j] > vec[max_index])
                max_index = j;
        }
        swap(vec[i], vec[max_index]);
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
        des_vector(v);
        cout << "\nArray in descending order : \n";
        print_vec(v);
        break;
    }
    return 0;
}