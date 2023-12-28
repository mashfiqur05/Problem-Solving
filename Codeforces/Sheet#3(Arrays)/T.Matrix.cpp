/// Given a number N and a 2D array A of size N * N. Print the absolute difference between the summation of its two diagonals (primary diagonal and secondary diagonal).

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

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    int primarydiagonal = 0;
    int secondarydiagonal = 0;

    for (int i = 0; i < n; i++)
    {
        primarydiagonal += a[i][i];
    }
    
    for (int i = 0, j = n-1; i < n; i++, j--)
    {
        secondarydiagonal += a[i][j];
    }

    int difference = primarydiagonal - secondarydiagonal;
    if (difference < 0) difference = difference * (-1);

    cout << difference;
    
    return 0;
}