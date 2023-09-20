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
/*
 Algorithm
  Basic Linear Search

 Input: A list of elements (array) arr.
         The element to be searched for, key.
 Output:The index of the key element if found, or -1 if the element is not in the list.


1 - Initialize a variable i to 0.

2 - Start a loop that will iterate through each element in the array arr.

3 - Check if arr[i] is equal to the key element.

4 - If they are equal, return the value of i, as you have found the key element.

5 - If they are not equal, increment i by 1 to move to the next element in the array.

6 - Repeat steps 3-5 until you find the key element or reach the end of the array.

7 - If you reach the end of the array without finding the key element, return -1 to indicate that the element is not in the list
*/