#include <bits/stdc++.h>
using namespace std;

int power(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }

    if (b == 1)
    {
        return a;
    }

    int ans = power(a, b / 2);

    if (b % 2 == 0)
    {
        return ans * ans;
    }
    else
    {
        return a * ans * ans;
    }
}

int main()
{
    cout << power(3, 10) << endl;
    cout << pow(3, 10) << endl;
    return 0;
}