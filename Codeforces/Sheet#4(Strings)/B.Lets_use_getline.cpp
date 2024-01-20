#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const int mx = 123;
int arr[mx];

int main()
{
    optimize();

    string s;
    getline(cin, s);
    int len = s.length();
    for (int i= 0; i < len; i++)
    {
        if (s[i]=='\\')break;
        cout << s[i];
    }    

    return 0;
}