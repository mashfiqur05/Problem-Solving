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
    cin >> s;
    string rev = s;
    int len = s.length();
    int pallin = 1;

    for (int i = 0, j = len-1; i < j; i++, j--)
    {
        int temp = s[i];
        s[i] = s[j];
        s[j] = s[i];
    }

    for (int i = 0; i < len; i++)
    {
        if (rev[i] != s[i])
        {
            pallin = 0;
            break;
        }
    }

    if (pallin) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}