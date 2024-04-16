#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int id;
    int dead;
    int profit;
};

bool cmp(Job a, Job b){
    return a.profit > b.profit;
}

vector<int> JobScheduling(Job arr[], int n)
{
    sort(arr, arr + n, cmp);
    int maxiDeadline  = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        maxiDeadline = max(maxiDeadline,arr[i].dead);
    }
    vector<int> schedule(maxiDeadline+1, -1);
    
    int count = 0;
    int maxProfit = 0;

    for (int i = 0; i < n; i++)
    {
        int currProfit = arr[i].profit;
        int currJobID = arr[i].id;
        int currDead = arr[i].dead;

        for (int k = currDead; k > 0; k--)
        {
            if(schedule[k] == -1){
                count++;
                maxProfit += currProfit;
                schedule[k] = currJobID;
                break;
            }
        }
        
    }
    
    vector<int> ans;
    ans.push_back(count);
    ans.push_back(maxProfit);

    return ans;
}

int main()
{
    Job arr[4];

    Job j1;
    j1.id = 1;
    j1.dead = 4;
    j1.profit = 20;

    Job j2;
    j2.id = 2;
    j2.dead = 1;
    j2.profit = 10;

    Job j3;
    j3.id = 3;
    j3.dead = 1;
    j3.profit = 40;

    Job j4;
    j4.id = 4;
    j4.dead = 1;
    j4.profit = 30;

    arr[0] = j1;
    arr[1] = j2;
    arr[2] = j3;
    arr[3] = j4;
    
    cout<<JobScheduling(arr, 4)[0] << " ";
    cout<<JobScheduling(arr, 4)[1];
    return 0;
}