#include <iostream>
using namespace std;

bool isSorted(int arr[], int size)
{
    if (size == 0 || size == 1)
    {
        return true;
    }

    if (arr[0] > arr[1])
    {
        return false;
    }
    else
    {
        return isSorted(arr + 1, size - 1);
    }
}

int main()
{
    int arr[5] = {1, 3, 5, 46, 8};
    int size = 5;
    cout << isSorted(arr, size) << endl;
    return 0;
}