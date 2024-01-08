/// Given a number N. Print a diamond that has 2N rows.

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const int mx = 123;
int arr[mx];

int main()
{
    optimize();

    int rows;
    cin >> rows;

    for (int i = 1; i <= rows; i++)
    {
        int space = rows - i;
        for (int j = 1; j <= space; j++)
        {
            cout << " ";
        }
        int star = 2 * i -1;
        for (int k = 1; k <= star; k++)
        {
            cout << "*";
        }
        cout << endl;
    }

    for (int i = rows; i >= 0; i--)
    {
        int space = rows - i;
        for (int j = 1; j <= space; j++)
        {
            cout << " ";
        }
        int star = 2 * i -1;
        for (int k = 1; k <= star; k++)
        {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}