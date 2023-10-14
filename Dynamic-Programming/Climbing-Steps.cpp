#include <bits/stdc++.h>
using namespace std;

int climbStair(long long n, int i){
    if (i == n)
    {
        return 1;
    }

    if (i > n)
    {
        return 0;
    }


    return (climbStair(n, i+1) + climbStair(n, i+2));
    
}

int main(){

    return 0;
}