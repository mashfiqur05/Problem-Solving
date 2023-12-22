/// Given a comparison symbol S between two numbers A and B. Determine whether it is Right or Wrong.The comparison is as follows: A < B, A > B, A = B.

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int main()
{
    optimize();

    int a,b;
    char s;
    cin >> a >> s >> b;

    if (s == '>')
    {
        if (a > b) cout << "Right";
        else cout << "Wrong";
    }
    else if(s == '<')
    {
        if (a < b) cout << "Right";
        else cout << "Wrong";
    }
    else 
    {
        if (a == b) cout << "Right";
        else cout << "Wrong";
    }

    return 0;
}