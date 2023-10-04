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

void insertionSort(int arr[], int n)
{
    int key, j;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        print(arr, n);
    }
}

int main()
{
    int n;
    cout << "Enter no of elements of array : ";
    cin >> n;
    int arr[n];
    cout << "enter elements in array : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "\nBefore sorting";
    print(arr, n);
    cout << "\nsorted list";
    insertionSort(arr, n);
    print(arr, n);
}