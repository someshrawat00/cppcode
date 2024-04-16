#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n = 4;
    int arr[] = {4, 3, 2, 6};
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }

    long long cost = 0;

    while(pq.size() > 1){
        long long first = pq.top();
        pq.pop();

        long long second = pq.top();
        pq.pop();
        
        long long mergedLength = first + second;
        cost += mergedLength;

        pq.push(mergedLength);

    }
    
    cout << cost;

    return 0;
} 