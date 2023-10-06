#include <bits/stdc++.h>
using namespace std;

void stringPermutation(string str, vector<string> &ans, int index)
{

    // base case
    if (index >= str.length())
    {
        ans.push_back(str);
        return;
    }

    for (int i = index; i < str.length(); i++)
    {
        swap(str[index], str[i]);
        stringPermutation(str, ans, index + 1);
        swap(str[index], str[i]);
    }
}

void print(vector<string> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<string> ans;
    string str = "abc";
    stringPermutation(str, ans, 0);
    print(ans);
    return 0;
}

