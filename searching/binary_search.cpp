#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int bs_iter(vi &v, int key)
{ // passed v should be already sorted in asc order
    int start = 0;
    int end = v.size() - 1;
    while (start <= end)
    {
        int mid = ((end - start) / 2) + start;

        if (v[mid] == key)
            return mid;

        else if (v[mid] > key)
            end = mid - 1;

        else
            start = mid + 1;
    }
    return -1;
}

int bs(vi &v, int key, int start, int end)
{ // passed v should be already sorted in asc order

    if (start > end)
        return -1;
    int mid = ((end - start) / 2) + start;

    if (v[mid] > key)
        return bs(v, key, start, mid - 1);

    else if (v[mid] < key)
        return bs(v, key, mid + 1, end);

    return mid; // else (v[mid] = key)
}

int bs_recur(vi &v, int key)
{
    return bs(v, key, 0, v.size() - 1);
}

int main()
{

    return 0;
}