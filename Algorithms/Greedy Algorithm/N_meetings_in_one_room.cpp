#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}

int main(){
    
    vector<pair<int,int>> v;
    int n = 6;
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] = {2, 4, 6, 7, 9, 9};
    

    for (int i = 0; i < n; i++)
    {
        pair<int,int> p = make_pair(start[i],end[i]);
        v.push_back(p);
    }

    sort(v.begin(),v.end(), cmp);
    
    int count = 1;
    int ansEnd = v[0].second;

    for (int i = 1; i < n; i++)
    {
        if(v[i].first > ansEnd){
            count++;
            ansEnd = v[i].second;
        }
    }
    
    cout << count;

    return 0;
} 