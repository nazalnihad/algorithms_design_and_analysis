#include <iostream>
using namespace std;

void print(int arr[], int n)
{
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                // print(arr, n);
            }
        }
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

    bubbleSort(arr, n);
    print(arr, n);
}