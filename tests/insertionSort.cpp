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

void insertion(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int key = arr[i];

        while (j >= 0 && arr[j] > key)
        {
            swap(arr[j], arr[j + 1]);
            j--;
        }
        arr[j + 1] = key;
    }
    print(arr, n);
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array:\n";
    print(arr, n);

    insertion(arr, n);

    return 0;
}