/// Given a number N.Determine whether N is float number or integer number.

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int main()
{
    optimize();

    double n;
    cin >> n;

    int x = floor(n);

    if(x == n) cout << "int" << " " << x;
    else cout << "float" << " " << x << " " << n - x;

    return 0;
}