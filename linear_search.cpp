#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int *arr;
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;
    arr = new int[n];

    cout << "Enter elements in the array : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int key;
    cout << "Enter the number to find ";
    cin >> key;

    int index = linearSearch(arr, n, key);
    if (index != -1)
    {
        cout << "Element found at index " << index << "\n";
    }
    else
    {
        cout << "Element not found ";
    }
    return 0;
}