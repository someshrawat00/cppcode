#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }

    return n * factorial(n - 1);
}

void printN(int n)
{

    if (n == 0)
    {
        return;
    }

    printN(n - 1);
    cout << n << " ";
}

void rprintN(int n)
{

    if (n == 0)
    {
        return;
    }

    cout << n << " ";
    printN(n - 1);
}

int Fibbonaci(int n)
{
    if (n == 1)
    {
        return 0;
    }

    if (n == 2)
    {
        return 1;
    }

    return Fibbonaci(n - 1) + Fibbonaci(n - 2);
}

void sayDigit(int n, string arr[])
{
    if (n == 0)
        return;

    sayDigit(n / 10, arr);
    cout << arr[n % 10] << " ";
}

int getSum(int arr[], int size)
{

    arr[1] += arr[0];
    if (size == 0)
    {
        return arr[0];
    }

    if (size == 1)
    {
        return arr[0];
    }

    return getSum(arr + 1, size - 1);
}

int main()
{
    // cout << factorial(5);
    // printN(5);
    // for (int i = 1; i <= 10; i++)
    // {
    //     cout << Fibbonaci(i) << " ";
    // }
    // string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    // sayDigit(412, arr);

    int arr[5] = {2, 4, 9, 9, 9};

    int sum = getSum(arr, 5);

    cout << sum << endl;

    return 0;
}