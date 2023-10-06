#include <bits/stdc++.h>

using namespace std;

void keyPad(string num, string output, int index, vector<string> &ans, string mapping[])
{

    // base case
    if (index >= num.length())
    {
        ans.push_back(output);
        return;
    }

    int n = num[index] - '0';
    string value = mapping[n];

    for (int i = 0; i < value.length(); i++)
    {
        output.push_back(value[i]);
        keyPad(num, output, index + 1, ans, mapping);
        output.pop_back();
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
    string num = "23";
    int index = 0;
    vector<string> ans;
    string output = "";
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    keyPad(num, output, index, ans, mapping);
    print(ans);
    return 0;
}

