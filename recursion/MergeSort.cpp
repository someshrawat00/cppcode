#include <bits/stdc++.h>
using namespace std;

void merge(int *arr, int s, int e)
{
    int mid = s + (e - s) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    //copy values
    int mainArrayIndex = s;
    for(int i = 0; i < len1; i++)
    {
        first[i] = arr[mainArrayIndex++];
    }
    
    mainArrayIndex = mid + 1;
    for(int i = 0; i < len2; i++)
    {
        second[i] = arr[mainArrayIndex++];
    }

    //Merge 2 Sorted Arrays
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while( index1 < len1 && index2 < len2){
        if(first[index1]  < second[index2])
        {
            arr[mainArrayIndex++] = first[index1++];
        }
        else{
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    while(index1 < len1){
        arr[mainArrayIndex++] = first[index1++];
    }

    while(index2 < len2){
        arr[mainArrayIndex++] = second[index2++];
    }

    delete []first;
    delete []second;

}

void mergeSort(int *arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }

    int mid = s + (e - s) / 2;

    // For left part
    mergeSort(arr, s, mid);

    // For right part
    mergeSort(arr, mid + 1, e);

    // merge array
    merge(arr, s, e);
}

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[15] = {3,7,0,1,5,8,3,2,34,66,87,23,12,12,12};
    int n = 15;
    print(arr, n);
    mergeSort(arr, 0, n - 1);
    print(arr, n);
    return 0;
}