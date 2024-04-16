#include <bits/stdc++.h>
using namespace std;

int main(){
   
	int S = 10;
	int N = 20;
	int M = 30;

	int sunday = S/7;
	int buyingDays = S - sunday;
	int totalFood = S*M;
	int ans = 0;
	if(totalFood%N == 0){
       ans = totalFood/N;
	}
	else{
		ans = (totalFood/N) + 1;
	}
    if(ans <= buyingDays){
		cout << ans;
    }
    else{
    	cout << -1;
    }

	return 0;
}