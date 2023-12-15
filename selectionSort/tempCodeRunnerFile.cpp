#include <iostream>
using namespace std;

void print(int arr[], int n)
{
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void selectionSort(int arr[], int n)
{
    int min_idx;
    for (int i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        if (min_idx != i)
        {
            swap(arr[i], arr[min_idx]);
        }
    }
}

int main()
{
    int n;
    cout << "\nEnter no of elements of array : ";
    cin >> n;
    int arr[n];
    cout << "Enter elements in array : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "\nBefore sorting";
    print(arr, n);
    cout << "\nsorted list";
    selectionSort(arr, n);
    print(arr, n);
}