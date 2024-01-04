/// Given a number N. Print the factorial of number N.

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

        long long factorial = 1;
        while (n)
        {
            factorial = factorial * n;
            n--;
        }
        cout << factorial << endl;
    }

    return 0;
}