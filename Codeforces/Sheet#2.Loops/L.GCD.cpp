/// Given two numbers A and B. Print the greatest common divisor between (A, B).

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int main()
{
    optimize();

    int a, b;
    int gcd = 1;
    cin >> a >> b;

    for (int i = 1; (i <= a && i <= b) ; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            if (gcd < i) gcd = i;
        }
    }
    cout << gcd;
    
    return 0;
}