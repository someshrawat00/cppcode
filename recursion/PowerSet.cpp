#include <bits/stdc++.h>
using namespace std;

void powerSet(vector<int> nums, vector<int> output, int index, vector<vector<int>>&ans)
{
    //base case
    if (index >= nums.size())
    {
        ans.push_back(output);
        return; 
    }

    //exclude
    powerSet(nums, output, index + 1, ans);

    //include
    int element = nums[index];
    output.push_back(element);
    powerSet(nums, output, index + 1, ans);
    


}

void print2d(vector<vector<int>> matrix)
{
    
    for (auto &row : matrix)
    {   
        
        for (auto &column : row)
        {
            cout << column;
        }
        cout << endl;
    }
}

int main()
{

    vector<vector<int>> ans;
    vector<int> output;
    vector<int> nums = {1, 2, 3};
    int index = 0;
    powerSet(nums, output, index, ans);
    sort(ans.begin(), ans.end());
    print2d(ans);
    return 0;
}