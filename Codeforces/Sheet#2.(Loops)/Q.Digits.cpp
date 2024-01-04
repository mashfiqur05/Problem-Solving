/// Given a number N. Print the digits of that number from right to left separated by space.

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int main()
{
    optimize();

    int t, n;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        cin >> n;

        if (n == 0) cout << 0;
        

        while (n != 0)
        {
            int digit = n % 10;
            n = n / 10;
            cout << digit << " ";
        }
        cout << endl;
    }

    return 0;
}