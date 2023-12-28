/// Given two numbers N and M, a 2D array of size N * M and a number X. Determine whether X exists in the 2D array A or not.

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const int mx = 123;
int a[mx][mx];

int main()
{
    optimize();

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    int x;
    cin >> x;
    int exist = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == x)
            {
                exist = 1;
                break;
            }
        }
        if (exist) break;
    }
    
    if (exist) cout << "will not take number";
    else cout << "will take number";

    return 0;
}