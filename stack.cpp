#include "somesh.h"
using namespace std;

int prec(char c)
{
    if (c == '-' || c == '+')
    {
        return 1;
    }
    else if (c == '/' || c == '*')
    {
        return 2;
    }
    else if (c == '^')
    {
        return 3;
    }
    return -1;
}

string infixToPostfix(string s)
{
    stack<char> st;
    string ans = "";

    for (int i = 0; i < s.length(); i++)
    {

        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
        {
            ans += s[i];
        }

        else
        {
            if (s[i] == '(')
            {
                st.push(s[i]);
            }

            else if (s[i] == ')')
            {
                while (!st.empty() && st.top() != '(')
                {
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            }

            else
            {
                while (!st.empty() && prec(s[i]) <= prec(st.top()))
                {
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
    }

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    return ans;
}

string infixToPrefix(string s)
{
    stack<char> st;
    string ans = "";
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            s[i] = ')';
        }
        else if(s[i] == ')'){
            s[i] = '(';
        }
        
    }
    
     for (int i = 0; i < s.length(); i++)
    {

        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
        {
            ans += s[i];
        }

        else
        {
            if (s[i] == '(')
            {
                st.push(s[i]);
            }

            else if (s[i] == ')')
            {
                while (!st.empty() && st.top() != '(')
                {
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            }

            else
            {
                while (!st.empty() && prec(s[i]) < prec(st.top()))
                {
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
    }

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
}



int main()
{
    cout<<infixToPostfix("(c*b)+a")<<endl;
    cout<<infixToPrefix("x+y*z/w+u")<<endl;
    return 0;
}
