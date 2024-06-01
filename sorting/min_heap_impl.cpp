#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct MinHeap
{
    int *harr;
    int capacity;
    int heap_size;

    MinHeap(int c)
    {
        heap_size = 0;
        capacity = c;
        harr = new int[c];
    }

    ~MinHeap() { delete[] harr; }

    int parent(int i) { return (i - 1) / 2; }

    int left(int i) { return (2 * i + 1); }

    int right(int i) { return (2 * i + 2); }

    void MinHeapify(int);
    int extractMin();
    void decreaseKey(int i, int new_val);
    void deleteKey(int i);
    void insertKey(int k);
};

int MinHeap::extractMin()
{
    if (heap_size <= 0)
        return -1;
    int x = harr[0];
    swap(harr[0], harr[heap_size - 1]);
    heap_size--;
    if (heap_size > 0)
        MinHeapify(0);
    return x;
}

void MinHeap::deleteKey(int i)
{
    // swapping ith with last is WRONG
    // first bring it to root using decreaseKey
    if (i < heap_size)
    {
        decreaseKey(i, INT_MIN);
        extractMin();
    }
}

void MinHeap::insertKey(int k)
{
    heap_size++;
    decreaseKey(heap_size - 1, k);
}

void MinHeap::decreaseKey(int i, int new_val)
{
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i])
    {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(harr[i], harr[smallest]);
        MinHeapify(smallest);
    }
}