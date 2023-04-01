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
    int size, entry, key;
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

    int index = -1;
    cout << "Enter key : ";
    cin >> key;
    for (int i = 0; i < size; i++)
    {
        if (v[i] == key)
        {
            index = i;
            break;
        }
    }
    if (index != -1)
        cout << "Index of " << key << " is : " << index << "\n";
    else
        cout << "NIL\n";
    return 0;
}