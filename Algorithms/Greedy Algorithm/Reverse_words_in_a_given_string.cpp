#include <bits/stdc++.h>
using namespace std;

int main(){
    
    string S = "i.like.this.program.very.much";
    string ans = "";
    string temp = "";

    for (int i = S.length()-1;i >= 0; i--)
    {
        if(S[i] == '.'){
           reverse(temp.begin(),temp.end());
           ans  = ans + temp;
           ans.push_back('.');
           temp = "";
         }
        else{
            temp.push_back(S[i]);
        }
    }

    reverse(temp.begin(),temp.end());
    ans += temp;

    cout << ans;

    return 0;
} 