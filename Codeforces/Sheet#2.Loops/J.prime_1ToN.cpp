/// Given a number N. Print all prime numbers between 1 and N inclusive.

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int main()
{
    optimize();

    int n;
    cin >> n;

    for (int i = 2; i <= n; i++)
    {
        int prime = 1;

        for (int j = 2; j <= i / 2; j++)
        {
            if (i % j == 0)
            {
                prime = 0;
                break;
            }
        }
        if (prime) cout << i << " ";
    }
    

    return 0;
}