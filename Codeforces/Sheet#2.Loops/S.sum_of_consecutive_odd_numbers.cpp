/// Given two numbers X and Y. Print the sum of all odd numbers between them, excluding X and Y.

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int main()
{
    optimize();

    int t, x, y;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        cin >> x >> y;
        int sum = 0;
        
        if (x < y)
        {
            for (int i = x + 1; i < y; i++)
            {
                if (i % 2 == 1) sum += i;
            }
        }
        else 
        {
            for (int i = y + 1; i < x; i++)
            {
                if (i % 2 == 1) sum += i;
            }
        }

        cout << sum << endl;
    }

    return 0;
}