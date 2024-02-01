/// reverse a given string.

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int main()
{
    optimize();

    string s;
    cin >> s;

    int n = s.length();

    for (int i = 0; i < n/2; i++)
    {
        swap(s[i], s[n-i-1]);
    }

    cout << s;

    return 0;
}