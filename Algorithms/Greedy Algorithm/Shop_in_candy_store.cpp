#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int candies[] = {3, 2, 1, 4};
    int n = 4; 
    sort(candies, candies+n);

    int k = 2;

    int mini = 0;
    int buy = 0;
    int free = n-1;

    while(buy <= free){
        mini = mini + candies[buy];
        buy++;
        free = free-k;
    }

    int maxi = 0;

    buy = n-1;
    free = 0;

    while(free <= buy){
        maxi = maxi + candies[buy];
        buy--;
        free = free + k;
    }

    cout << mini << " " << maxi;

    return 0;
} 