#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n = 8;
    int m = 5;
    int a[] = {3, 4, 1, 9, 56, 7, 9, 12};

    sort(a, a+n);

    int i = 0;
    int j = m-1;
    int mini = INT_MAX;

    while(j < n){
        int diff = a[j] - a[i];
        mini = min(mini, diff);
        i++;
        j++;
    }

    cout << mini;

    return 0;
} 