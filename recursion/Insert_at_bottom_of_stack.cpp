#include <bits/stdc++.h>
using namespace std;

void solve(stack<int> &s, int x)
{
    if (s.empty())
    {
        s.push(x);
        return;
    }

    int temp = s.top();
    s.pop();
    solve(s, x);
    s.push(temp);
}

void print(stack<int> st){
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
}

int main()
{
    stack<int> st;
    int X = 9;
    st.push(2);
    st.push(4);
    st.push(3);
    cout<<"Before:"<< endl;
    print(st);
    solve(st, X);
    cout<<"After:"<< endl;
    print(st);
    
    return 0;
}