#include <bits/stdc++.h>
using namespace std;

void reverse(string &str, int i, int j)
{
    if (i > j)
        return;

    swap(str[i], str[j]);

    reverse(str, i + 1, j - 1);
}

bool checkPalindrome(string str, int i, int j)
{
    if (i > j)
    {
        return true;
    }

    if (str[i] != str[j])
    {
        return false;
    }

    return checkPalindrome(str, i + 1, j - 1);
}



int main()
{
    string str = "BookooB";
    // reverse(str, 0, str.length() - 1);
    // cout << str << endl;

    // cout << checkPalindrome(str, 0, str.length() - 1);

   

    return 0;
}