/// Write a program which reads a n×m matrix A and a m×1 vector b, and prints their product Ab.

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const int mx = 123;
int a[mx][mx];
int b[mx];
int c[mx];

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
    
    for (int i = 0; i < m; i++) cin >> b[i];

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < m; j++)
        {
            sum += a[i][j] * b[j];
        }
            c[i] = sum;
    }
    
    for (int i = 0; i < n; i++)
    {
        cout << c[i] << endl;
    }

    return 0;
}