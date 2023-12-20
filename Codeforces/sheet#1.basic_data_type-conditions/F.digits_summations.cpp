///  Given two numbers N and M. Print the summation of their last digits.

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int main()
{
    optimize();

    long long a, b;
    cin >> a >> b;

    int digit1 = a % 10;
    int digit2 = b % 10;

    cout << digit1 + digit2 << endl;

    return 0;
}   