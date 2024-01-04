/// Given two numbers A and B. Print "Yes" if A is greater than or equal to B. Otherwise print "No".

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int main()
{
    optimize();

    int a, b;
    cin >> a >> b;

    if(a >= b) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}