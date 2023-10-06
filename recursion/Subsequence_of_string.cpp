#include <bits/stdc++.h>
using namespace std;

void subSeq(string str, string output, int index, vector<string> &ans)
{
    // base case
    if (index >= str.length())
    {
        if (output.length() > 0)
        {
            /* code */
            ans.push_back(output);
        }

        return;
    }

    // exclude
    subSeq(str, output, index + 1, ans);

    // include
    char element = str[index];
    output.push_back(element);
    subSeq(str, output, index + 1, ans);
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
    string output = "";
    string str = "abc";
    int index = 0;
    subSeq(str, output, index, ans);
    print(ans);

    return 0;
}