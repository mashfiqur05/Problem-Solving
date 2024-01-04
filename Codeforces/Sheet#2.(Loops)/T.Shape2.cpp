/// Given a number N. Print a pyramid that has N rows.

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int main()
{
    optimize()

    int i, space, rows, k = 0;
    cin >> rows;

    for (int i = 1; i <= rows; i++, k = 0)
    {
        for (space = 1; space <= rows - i; space++)
        {
            cout << " ";
        }
        while (k != 2 * i - 1)
        {
            cout << "*";
            k++;
        }
        cout << endl;
    }
    
    
    return 0;
}