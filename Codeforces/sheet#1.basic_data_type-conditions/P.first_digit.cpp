/// Given a number X. Print "EVEN" if the first digit of X is even number. Otherwise print "ODD".

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
    int digit = n;

    while (digit >= 10)
    {
        digit = digit / 10;
    }
    
    if (digit % 2 == 0) cout << "EVEN" << endl;
    else cout << "ODD" << endl;

    return 0;
}       