/// Given 2 numbers A and B. Print floor, ceil and round of A/B

#include<bits/stdc++.h>
#include<cmath>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int main()
{
    optimize();

    double a, b;
    cin >> a >> b;
    double ans = a / b;
    
    cout << "floor" << " " << a << " " << "/" << " " << b << " " << "=" << " " << floor(ans) << endl;
    cout << "ceil" << " " << a << " " << "/" << " " << b << " " << "=" << " " << ceil(ans) << endl;
    cout << "round" << " " << a << " " << "/" << " " << b << " " << "=" << " " << round(ans) << endl;

    return 0;
}