/// Given two numbers X and Y. Print the summation and multiplication and subtraction of these 2 numbers.

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

    cout << a << " " << "+" << " " << b << " " << "=" << " " << a + b << endl;
    cout << a << " " << "*" << " " << b << " " << "=" << " " << a * b << endl;
    cout << a << " " << "-" << " " << b << " " << "=" << " "  << a - b << endl;

    return 0;
}