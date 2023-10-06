#include <bits/stdc++.h>
using namespace std;

bool linearSearch(int arr[], int size, int key)
{
    if (size == 0)
        return false;
    if (arr[0] == key)
        return true;
    return linearSearch(arr + 1, size - 1, key);
}

bool binarySearch(int arr[], int s, int e, int key)
{
    if (s > e)
        return false;

    int mid = s + (e - s) / 2;

    if (arr[mid] == key){
        return true; 
    }
    
    if (arr[mid] < key)
    {
        return binarySearch(arr, mid + 1, e, key);
    }
    else
    {
        return binarySearch(arr, s, mid - 1, key);
    }
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    // cout << linearSearch(arr, 5, 3) << endl;
    cout << binarySearch(arr, 0, 4, 6) << endl;
    return 0;
}