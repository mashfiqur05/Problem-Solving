/// Only one line containing the following space-separated values: int, long long, char, float and double respectively.

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int main()
{
    optimize();

    int i;
    long long l;
    char c;
    float f;
    double d;

    cin >> i >> l >> c >> f >> d;
    cout << i << endl << l << endl << c << endl << f << endl << d << endl;

    return 0;
}