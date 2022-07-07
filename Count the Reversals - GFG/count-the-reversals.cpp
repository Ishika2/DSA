// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal// } Driver Code Ends



int countRev (string s)
{
    int ans = 0;
    stack<char> S;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '{')
            S.push(s[i]);
        else
        {
            if(!S.empty())
                S.pop();
            else
            {
                S.push('{');
                ans++;
            }
        }
    }
    if(S.size() % 2 != 0)
        return -1;
    ans += S.size()/2;
    //if(S.empty())
    return ans;
    // else
    //     return -1;
    // your code here
}