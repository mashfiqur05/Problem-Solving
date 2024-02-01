#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const int mx = 123;
char arr[mx][mx];

void solve()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++) cin >> arr[i][j];
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (arr[i][j] != '.')
            cout << arr[i][j];
        }
    }

    cout << endl;
    
}   

int main()
{
    optimize();

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}