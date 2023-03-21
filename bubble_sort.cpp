#include <iostream>
using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void ascending(int arr[], int n)
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
void descending(int arr[], int n)
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
int main()
{
    int n;
    int arr[20];
    cout << "Enter number of entries : ";
    cin >> n;
    cout << "\nInput entries : \n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int choice;
    cout << "\n 1 - Ascending\n";
    cout << " 2 - Descending\n";
    cout << "\nEnter choice : ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        ascending(arr, n);
        cout << "\nArray in ascending order : \n";
        printArr(arr, n);
        break;
    case 2:
        descending(arr, n);
        cout << "\nArray in descending order : \n";
        printArr(arr, n);
        break;
    }
    return 0;
}